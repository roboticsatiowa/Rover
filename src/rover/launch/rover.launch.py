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
                [FindPackageShare("video_feed"),"launch/cameras.launch.py"]
            )
        )
    )
    launch_aruco_detection = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution(
                [FindPackageShare("aruco_detection"),"launch/aruco_detector.launch.py"]
            )
        )
    )

    hardware_interace_node = Node(
        name="hardware_interface",
        package="simple_hardware_interface",
        executable="interface_node",
    )

    # Start rosbag recording [-a = all topics] [ -d = file split duration in seconds] 
    rosbag = ExecuteProcess(cmd="ros2 bag record -a --compression-mode file --compression-format zstd -d 9000".split(" "), output="screen") 

    return LaunchDescription([
        launch_aruco_detection,
        launch_video_feeds,
        hardware_interace_node,
        rosbag
    ])

