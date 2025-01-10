from sympy import E
from launch import LaunchDescription
from launch.actions import ExecuteProcess, DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    port = LaunchConfiguration("port")
    ip = LaunchConfiguration("ip")

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
            # gst-launch-1.0 udpsrc port=5000 ! application/x-rtp,clock-rate=90000,payload=96 ! rtph264depay ! h264parse ! avdec_h264 ! videoconvert ! xvimagesink
            ExecuteProcess(
                cmd=[
                    "gst-launch-1.0",
                    "udpsrc",
                    "address=", 
                    ip,
                    "port=", 
                    port,
                    "!",
                    "application/x-rtp,clock-rate=90000,payload=96",
                    "!",
                    "rtph264depay",
                    "!",
                    "h264parse",
                    "!",
                    "avdec_h264",
                    "!",
                    "videoconvert",
                    "!",
                    "xvimagesink",
                ],
                output="screen",
            ),
        ]
    )
