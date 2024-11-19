from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch.actions import ExecuteProcess
from time import strftime
import os


def generate_launch_description():
    launch_description_list = []
    
    launch_description_list.append(
        IncludeLaunchDescription(
            AnyLaunchDescriptionSource(
                PathJoinSubstitution(
                    [FindPackageShare("foxglove_bridge"), "launch", "foxglove_bridge_launch.xml"]
                )
            )
        )
    )
    
    # joy node
    launch_description_list.append(
        Node(
            package="joy",
            executable="joy_node",
            name="joy_node",
            parameters=[{"coalesce_interval": "0.5",
                         "default_trig_val": "true"}],
        )
    )

    # # Arducam
    # # list devices in /dev that start with "CAM" as per the udev rule
    # if os.path.exists("/dev/Arducam"):
    #     arducam_devices = [int(i[3]) for i in os.listdir("/dev/Arducam") if i.startswith("CAM")]
    #     for i in arducam_devices:
    #         launch_description_list.append(
    #             Node(
    #                 package="arducam",
    #                 executable="arducam_video",
    #                 parameters=[{"cam_index": i}],
    #                 respawn=True,
    #                 respawn_delay=10,
    #             )
    #         )
    #  # GPS
    # launch_description_list.append(
    #     IncludeLaunchDescription(
    #         AnyLaunchDescriptionSource(
    #             PathJoinSubstitution(
    #                 [
    #                     FindPackageShare("ublox_gps"),
    #                     "launch/ublox_gps_node_zedf9p-launch.py",
    #                 ]
    #             )
    #         )
    #     )
    # )

    # # # Teensy Interface
    # launch_description_list.append(
    #     Node(
    #         name="simple_hardware_interface",
    #         package="simple_hardware_interface",
    #         executable="simple_hardware_interface",
    #         respawn=True,
    #         respawn_delay=10,
    #     )
    # )

    # Rosbag
    # Start rosbag recording [-a = all topics] [ -d = file split duration in seconds]
    # launch_description_list.append(
    #     ExecuteProcess(
    #         cmd=f'ros2 bag record -o bag/{strftime("%Y-%m-%d-%H-%M-%S")} -a --compression-mode file --compression-format zstd -d 9000'.split(
    #             " "
    #         ),
    #         output="screen",
    #     )
    # )

    return LaunchDescription(launch_description_list)
