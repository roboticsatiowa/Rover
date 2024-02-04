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


    return LaunchDescription([
        launch_aruco_detection,
        launch_video_feeds
    ])

