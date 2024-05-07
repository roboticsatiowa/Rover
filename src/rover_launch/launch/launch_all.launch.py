from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch.actions import ExecuteProcess
from time import strftime


def generate_launch_description():

    # Video feeds
    launch_video_feeds = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution(
                [FindPackageShare("video_feed"),"launch/cameras.launch.py"]
            )
        )
    )

    launch_gps = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution(
                [FindPackageShare("ublox_gps"),"ublox_gps_node_zedf9p-launch.py"]
            )
        )
    )
    
    # Aruco detection
    launch_aruco_detection = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution(
                [FindPackageShare("aruco_detection"),"launch/aruco_detector.launch.py"]
            )
        )
    )

    # Simple hardware interface
    hardware_interace_node = Node(
        name="simple_hardware_interface",
        package="simple_hardware_interface",
         executable="simple_hardware_interface",
        respawn=True,
        respawn_delay=5,
    )

    # Start rosbag recording [-a = all topics] [ -d = file split duration in seconds] 
    rosbag = ExecuteProcess(cmd=f'ros2 bag record -o bag/{strftime("%Y-%m-%d-%H-%M-%S")} -a --compression-mode file --compression-format zstd -d 9000'.split(" "), output="screen") 

    return LaunchDescription([
        launch_aruco_detection,
        launch_video_feeds,
        hardware_interace_node,
        rosbag,
        launch_gps
    ])

