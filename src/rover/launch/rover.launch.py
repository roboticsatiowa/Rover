from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch.actions import ExecuteProcess


def generate_launch_description():
    # include launch file in video_feed/launch/video_feed.launch.py

    launch_video_feeds = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution(
                [FindPackageShare("video_feed"),"launch/cameras.launch.py"]
            )
        )
    )
    # launch_aruco_detection = IncludeLaunchDescription(
    #     AnyLaunchDescriptionSource(
    #         PathJoinSubstitution(
    #             [FindPackageShare("aruco_detection"),"aruco_detector.launch.py"]
    #         )
    #     )
    # )    

    node_foxglove_bridge = Node(name="foxglove_bridge", package="foxglove_bridge", executable="foxglove_bridge", output="screen")

    exec_foxglove_studio = ExecuteProcess(cmd=["foxglove-studio"])

    return LaunchDescription([
        node_foxglove_bridge,
        exec_foxglove_studio,
        launch_video_feeds,
    ])
