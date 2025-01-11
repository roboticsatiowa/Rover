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

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node {
public:
    GstElement* pipeline, * v4lsrc, * jpegdec, * appsrc, * appsink, * queue, * videoconvert, * x264enc, * rtph264pay, * udpsink;
    GstBus* bus;
    GstMessage* msg;
    GstStateChangeReturn ret;

    MinimalPublisher() : Node("gstreamer_source") {

        RCLCPP_INFO(this->get_logger(), "Starting gstreamer source node");

        // initialize gstreamer
        gst_init(NULL, NULL);

        // create pipeline elements
        v4lsrc = gst_element_factory_make("v4l2src", "v4l_src");
        jpegdec = gst_element_factory_make("jpegdec", "jpeg_dec");
        appsink = gst_element_factory_make("appsink", "app_sink");
        appsrc = gst_element_factory_make("appsrc", "app_src");
        queue = gst_element_factory_make("queue", "queue");
        videoconvert = gst_element_factory_make("videoconvert", "video_convert");
        x264enc = gst_element_factory_make("x264enc", "x264_enc");
        rtph264pay = gst_element_factory_make("rtph264pay", "rtp_h264_pay");
        udpsink = gst_element_factory_make("udpsink", "udp_sink");

        gst_app_sink_set_emit_signals((GstAppSink*)appsink, true);
        gst_app_sink_set_drop((GstAppSink*)appsink, true);
        gst_app_sink_set_max_buffers((GstAppSink*)appsink, 1);

        g_signal_connect(appsink, "new-buffer", G_CALLBACK(cv_process_frame), (gpointer)mark);

        // empty pipeline
        pipeline = gst_pipeline_new("pipeline");

        if (!pipeline || !v4lsrc || !jpegdec || !appsrc || !appsink || !queue || !videoconvert || !x264enc || !rtph264pay || !udpsink) {
            RCLCPP_ERROR(this->get_logger(), "Failed to create elements");
        }

        // build pipeline
        gst_bin_add_many(GST_BIN(pipeline), v4lsrc, jpegdec, appsink, appsrc, queue, videoconvert, x264enc, rtph264pay, udpsink, NULL);
        if (gst_element_link_many(v4lsrc, jpegdec, appsink, appsrc, queue, videoconvert, x264enc, rtph264pay, udpsink, NULL) != TRUE) {
            RCLCPP_ERROR(this->get_logger(), "Failed to link elements");
        }

        // set properties
        g_object_set(v4lsrc, "device", "/dev/video0", NULL);
        g_object_set(x264enc, "tune", 0x00000004, NULL); // zerolatency
        g_object_set(x264enc, "key-int-max", 15, NULL);
        g_object_set(rtph264pay, "pt", 96, NULL);
        g_object_set(rtph264pay, "config-interval", -1, NULL);
        g_object_set(udpsink, "host", "0.0.0.0", NULL);
        g_object_set(udpsink, "port", 5000, NULL);

        // start playing
        ret = gst_element_set_state(pipeline, GST_STATE_PLAYING);
        if (ret == GST_STATE_CHANGE_FAILURE) {
            RCLCPP_ERROR(this->get_logger(), "Failed to start pipeline");
        }

        bus = gst_element_get_bus(pipeline);
        gst_bus_add_watch(bus, (GstBusFunc)gst_bus_callback, this);
    }

    ~MinimalPublisher() {
        if (msg != NULL) {
            gst_message_unref(msg);
        }
        gst_object_unref(bus);
        gst_element_set_state(pipeline, GST_STATE_NULL);
        gst_object_unref(pipeline);
    }

    gst_bus_callback() {
        msg = gst_bus_pop_filtered(bus, (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

        if (msg == NULL) {
            return;
        }

        switch (GST_MESSAGE_TYPE(msg)) {
            case GST_MESSAGE_ERROR:
                GError* err;
                gchar* debug_info;
                gst_message_parse_error(msg, &err, &debug_info);
                RCLCPP_ERROR(this->get_logger(), "Error received from element %s: %s", GST_OBJECT_NAME(msg->src), err->message);
                RCLCPP_ERROR(this->get_logger(), "Debugging information: %s", debug_info ? debug_info : "none");
                g_clear_error(&err);
                g_free(debug_info);
                break;
            case GST_MESSAGE_EOS:
                RCLCPP_INFO(this->get_logger(), "End of stream");
                rclcpp::shutdown();
                break;
            default:
                RCLCPP_ERROR(this->get_logger(), "Unexpected message received");
                break;
        }

        gst_message_unref(msg);
    }

    cv_process_frame(GstAppSink *fks, gpointer mark) {

    }





private:
    rclcpp::TimerBase::SharedPtr timer;

};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}