from launch import LaunchDescription
from launch.actions import ExecuteProcess, DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    port = LaunchConfiguration("port")
    ip = LaunchConfiguration("ip")
    video_device = LaunchConfiguration("video_device")

    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "port",
                default_value="5000",
                description="Port to stream video to (Default: 5000)",
            ),
            DeclareLaunchArgument(
                "ip",
                default_value="0.0.0.0",
                description="IP address to stream video to (Default: 0.0.0.0)",
            ),
            DeclareLaunchArgument(
                "video_device",
                default_value="/dev/video0",
                description="Video device to stream from (Default: /dev/video0)",
            ),
            ExecuteProcess(
                cmd=[
                    "gst-launch-1.0",
                    "v4l2src",
                    "device=",
                    video_device,
                    "!",
                    "jpegdec",
                    "!",
                    "queue",
                    "!",
                    "videoconvert",
                    "!",
                    "x264enc",
                    "tune=zerolatency",
                    "key-int-max=15",
                    "!",
                    "video/x-h264,profile=main",
                    "!",
                    "rtph264pay",
                    "pt=96",
                    "config-interval=-1",
                    "!",
                    "udpsink",
                    "host=",
                    ip,
                    "port=",
                    port,
                ],
                output="screen",
            ),
        ]
    )
