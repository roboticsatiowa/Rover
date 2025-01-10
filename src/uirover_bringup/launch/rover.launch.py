from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch.actions import ExecuteProcess
import os
from time import strftime


def generate_launch_description():
    launch_description_list = []

    # Arducam
    # list devices in /dev that start with "CAM" as per the udev rule
    if os.path.exists("/dev/Arducam"):
        arducam_devices = [
            int(i[3]) for i in os.listdir("/dev/Arducam") if i.startswith("CAM")
        ]
        for i in arducam_devices:
            launch_description_list.append(
                Node(
                    package="uirover_arducam",
                    executable="arducam_video",
                    parameters=[{"cam_index": i}],
                    respawn=True,
                    respawn_delay=10,
                )
            )

    # GPS
    launch_description_list.append(
        IncludeLaunchDescription(
            AnyLaunchDescriptionSource(
                PathJoinSubstitution(
                    [
                        FindPackageShare("ublox_gps"),
                        "launch/ublox_gps_node_zedf9p-launch.py",
                    ]
                )
            )
        )
    )

    # # Teensy Interface
    launch_description_list.append(
        Node(
            name="uirover_hardware",
            package="uirover_hardware",
            executable="uirover_hardware",
            respawn=True,
            respawn_delay=10,
        )
    )

    # Zenoh Bridge
    # https://zenoh.io/blog/2021-09-28-iac-experiences-from-the-trenches/
    launch_description_list.append(
        ExecuteProcess(
            cmd="zenoh-bridge-dds --no-multicast-scouting -l udp/0.0.0.0:7447".split(
                " "
            ),
            output="screen",
        )
    )

    # Rosbag
    # Start rosbag recording [-a = all topics] [ -d = file split duration in seconds]
    launch_description_list.append(
        ExecuteProcess(
            cmd=f"ros2 bag record -o bag/{strftime('%Y-%m-%d-%H-%M-%S')} -a --compression-mode file --compression-format zstd -d 9000".split(
                " "
            ),
            output="screen",
        )
    )

    return LaunchDescription(launch_description_list)
