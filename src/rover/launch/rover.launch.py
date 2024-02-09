from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch.actions import ExecuteProcess


def generate_launch_description():

    # Start video feeds
    launch_video_feeds = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution(
                [FindPackageShare("video_feed"), "launch/cams.launch.xml"]
            )
        )
    )

    hardware_interace_node = Node(
        name="simple_hardware_interface",
        package="simple_hardware_interface",
        executable="simple_hardware_interface",
    )


    return LaunchDescription(
        [
            launch_video_feeds,
            hardware_interace_node
        ]
    )
