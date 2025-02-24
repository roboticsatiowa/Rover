// std lib
#include <chrono>
#include <memory>
#include <string>

// ros
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp" 

// opencv
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/aruco.hpp>

// https://trepo.tuni.fi/bitstream/handle/10024/149126/VechtomovVladimir.pdf?sequence=2
// Very useful paper about optimization of H264 parameters for low latency streaming

using namespace std::chrono_literals;

class GStreamerNode : public rclcpp::Node {
public:
    GStreamerNode() : Node("gstreamer_stream_source") {

        auto param_desc_port = rcl_interfaces::msg::ParameterDescriptor{};
        param_desc_port.description = "UDP port to stream video to.";
        auto param_desc_host = rcl_interfaces::msg::ParameterDescriptor{};
        param_desc_host.description = "UDP host to stream video to.";
        auto param_desc_device = rcl_interfaces::msg::ParameterDescriptor{};
        param_desc_device.description = "Video device to stream from.";
        auto param_desc_framerate = rcl_interfaces::msg::ParameterDescriptor{};
        param_desc_framerate.description = "Framerate of the video stream.";
        auto param_desc_width = rcl_interfaces::msg::ParameterDescriptor{};
        param_desc_width.description = "Width of the video stream.";
        auto param_desc_height = rcl_interfaces::msg::ParameterDescriptor{};
        param_desc_height.description = "Height of the video stream.";
        auto param_desc_bitrate = rcl_interfaces::msg::ParameterDescriptor{};
        param_desc_bitrate.description = "gstreamer x264enc bitrate in Kbit/s. No effect on the ROS2 topic.";
        auto param_desc_publish_topic = rcl_interfaces::msg::ParameterDescriptor{};
        param_desc_publish_topic.description = "Publish the video stream to a ROS2 topic.";
        auto param_desc_publish_topic_name = rcl_interfaces::msg::ParameterDescriptor{};
        param_desc_publish_topic_name.description = "Name of the ROS2 topic to publish to.";
        auto param_desc_dictionary = rcl_interfaces::msg::ParameterDescriptor{};
        param_desc_dictionary.description = "aruco dictionary to use for marker detection.";
        param_desc_dictionary.additional_constraints = "Valid options are: DICT_4X4_50, DICT_4X4_100, DICT_4X4_250, DICT_4X4_1000, DICT_5X5_50, DICT_5X5_100, DICT_5X5_250, DICT_5X5_1000, DICT_6X6_50, DICT_6X6_100, DICT_6X6_250, DICT_6X6_1000, DICT_7X7_50, DICT_7X7_100, DICT_7X7_250, DICT_7X7_1000, DICT_ARUCO_ORIGINAL";



        this->declare_parameter("port", 5000, param_desc_port);
        this->declare_parameter("host", "0.0.0.0", param_desc_host);
        this->declare_parameter("device", "/dev/video0", param_desc_device);
        this->declare_parameter("framerate", 30.0, param_desc_framerate); // TODO unimplemented
        this->declare_parameter("width", 1920, param_desc_width); // TODO unimplemented
        this->declare_parameter("height", 1080, param_desc_height); // TODO unimplemented
        this->declare_parameter("bitrate", 2048, param_desc_bitrate);
        this->declare_parameter("publish_topic", false, param_desc_publish_topic); // TODO unimplemented
        this->declare_parameter("publish_topic_name", "camera_stream", param_desc_publish_topic_name); // TODO unimplemented
        this->declare_parameter("dictionary", "DICT_4X4_100", param_desc_dictionary);

        start_stream();

        auto cb_restart_stream = [this](const rclcpp::Parameter& p) {
            RCLCPP_INFO(
                this->get_logger(), "Received an update to parameter \"%s\" of type %s",
                p.get_name().c_str(),
                p.get_type_name().c_str()
            );

            RCLCPP_INFO(this->get_logger(), "Restarting camera stream.");
            end_stream();
            start_stream();
        };
        param_subscriber = std::make_shared<rclcpp::ParameterEventHandler>(this);

        cb_handle_dictionary = param_subscriber->add_parameter_callback("dictionary", cb_restart_stream);
        cb_handle_bitrate = param_subscriber->add_parameter_callback("bitrate", cb_restart_stream);
        cb_handle_port = param_subscriber->add_parameter_callback("port", cb_restart_stream);
        cb_handle_host = param_subscriber->add_parameter_callback("host", cb_restart_stream);
        cb_handle_device = param_subscriber->add_parameter_callback("device", cb_restart_stream);

    }

    ~GStreamerNode() {
        end_stream();
    }

    void start_stream() {

        std::string dictionary = this->get_parameter("dictionary").as_string();
        std::string device = this->get_parameter("device").as_string();
        std::string host = this->get_parameter("host").as_string();
        int bitrate = this->get_parameter("bitrate").as_int();
        int port = this->get_parameter("port").as_int();
        double framerate = this->get_parameter("framerate").as_double();
        int width = this->get_parameter("width").as_int();
        int height = this->get_parameter("height").as_int();

        set_aruco_dict(dictionary);

        std::string pipeline_video_capture = "v4l2src device="
            + device
            + " ! jpegdec ! videoconvert ! appsink drop=1";

        std::string pipeline_video_writer = "appsrc ! videoconvert ! x264enc tune=zerolatency key-int-max=15 insert-vui=1 speed-preset=veryfast bitrate="
            + std::to_string(bitrate)
            + " ! video/x-h264,profile=main ! rtph264pay pt=96 config-interval=-1 ! udpsink host="
            + host
            + " port="
            + std::to_string(port);

        cap = cv::VideoCapture(pipeline_video_capture);

        if (!cap.isOpened()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open camera.");
            return;
        }

        writer = cv::VideoWriter(pipeline_video_writer, 0, framerate, cv::Size(width, height), true);

        if (!writer.isOpened()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open writer.");
            return;
        }

        auto timer_callback = [this]() -> void {
            this->process_frame();
            };

        timer = this->create_wall_timer(1ms, timer_callback);

        RCLCPP_INFO(this->get_logger(), "Camera stream started.");
    }

    void end_stream() {
        cap.release();
        writer.release();
        RCLCPP_INFO(this->get_logger(), "Camera stream ended.");
    }

    void process_frame() {
        cap >> frame;
        if (frame.empty()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to capture frame.");
            return;
        }

        // detect and draw aruco markers. 6 lines of code - god bless opencv
        // https://docs.opencv.org/4.6.0/d5/dae/tutorial_aruco_detection.html
        std::vector<int> ids;
        std::vector<std::vector<cv::Point2f> > corners;
        cv::aruco::detectMarkers(frame, aruco_dictionary, corners, ids);
        if (ids.size() > 0) {
            cv::aruco::drawDetectedMarkers(frame, corners, ids);
        }

        writer << frame;
    }


private:
    cv::Mat frame;
    cv::VideoCapture cap;
    cv::VideoWriter writer;
    cv::Ptr<cv::aruco::Dictionary> aruco_dictionary;

    std::shared_ptr<rclcpp::ParameterEventHandler> param_subscriber;
    std::shared_ptr<rclcpp::ParameterCallbackHandle> cb_handle_dictionary;
    std::shared_ptr<rclcpp::ParameterCallbackHandle> cb_handle_bitrate;
    std::shared_ptr<rclcpp::ParameterCallbackHandle> cb_handle_port;
    std::shared_ptr<rclcpp::ParameterCallbackHandle> cb_handle_host;
    std::shared_ptr<rclcpp::ParameterCallbackHandle> cb_handle_device;


    rclcpp::TimerBase::SharedPtr timer;


    void set_aruco_dict(const std::string& dictionary) {
        if (dictionary == "DICT_4X4_50") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);
        }
        else if (dictionary == "DICT_4X4_100") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_100);
        }
        else if (dictionary == "DICT_4X4_250") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_250);
        }
        else if (dictionary == "DICT_4X4_1000") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_1000);
        }
        else if (dictionary == "DICT_5X5_50") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_5X5_50);
        }
        else if (dictionary == "DICT_5X5_100") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_5X5_100);
        }
        else if (dictionary == "DICT_5X5_250") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_5X5_250);
        }
        else if (dictionary == "DICT_5X5_1000") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_5X5_1000);
        }
        else if (dictionary == "DICT_6X6_50") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_50);
        }
        else if (dictionary == "DICT_6X6_100") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_100);
        }
        else if (dictionary == "DICT_6X6_250") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
        }
        else if (dictionary == "DICT_6X6_1000") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_1000);
        }
        else if (dictionary == "DICT_7X7_50") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_7X7_50);
        }
        else if (dictionary == "DICT_7X7_100") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_7X7_100);
        }
        else if (dictionary == "DICT_7X7_250") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_7X7_250);
        }
        else if (dictionary == "DICT_7X7_1000") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_7X7_1000);
        }
        else if (dictionary == "DICT_ARUCO_ORIGINAL") {
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
        }
        else {
            RCLCPP_ERROR(this->get_logger(), "Invalid aruco dictionary. Using default (DICT_4X4_250).");
            aruco_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_250);
            return;
        }
    }

};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GStreamerNode>());
    rclcpp::shutdown();
    return 0;
}