// std lib
#include <chrono>
#include <memory>
#include <string>

// ros
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp" 

// gstreamer https://gstreamer.freedesktop.org/documentation/
#include <gst/gst.h>

// opencv
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/aruco.hpp>

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node {
public:
    MinimalPublisher() : Node("gstreamer_source") {
        RCLCPP_INFO(this->get_logger(), "Starting camera stream.");
        cap = cv::VideoCapture("v4l2src device=/dev/video0 ! jpegdec ! queue ! videoconvert ! appsink");
        if (!cap.isOpened()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open camera.");
            return;
        }

        RCLCPP_INFO(this->get_logger(), "Camera opened.");

        // FPS set to 31 but actual FPS is 30. When the FPS matches exactly, the latency gets progressively 
        // worse because of small delays accumulating. This is not the proper way to fix it but it works for now.
        writer = cv::VideoWriter("appsrc ! videoconvert ! x264enc tune=zerolatency key-int-max=15 ! video/x-h264,profile=main ! rtph264pay pt=96 config-interval=-1 ! udpsink host=0.0.0.0 port=5000", 0, 31.0, cv::Size(1920, 1080), true);
        if (!writer.isOpened()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open writer.");
            return;
        }

        RCLCPP_INFO(this->get_logger(), "Writer opened.");

        auto timer_callback = [this]() -> void {
            this->process_frame();
            };

        timer = this->create_wall_timer(1ms, timer_callback);

        RCLCPP_INFO(this->get_logger(), "Camera stream started.");
    }

    void process_frame() {
        cap >> frame;
        if (frame.empty()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to capture frame.");
            return;
        }

        std::vector<int> ids;
        std::vector<std::vector<cv::Point2f> > corners;
        cv::aruco::detectMarkers(frame, dictionary, corners, ids);
        if (ids.size() > 0) {
            cv::aruco::drawDetectedMarkers(frame, corners, ids);
        }

        writer << frame;
    }


private:
    cv::Mat frame;
    cv::VideoCapture cap;
    cv::VideoWriter writer;
    rclcpp::TimerBase::SharedPtr timer;

    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}