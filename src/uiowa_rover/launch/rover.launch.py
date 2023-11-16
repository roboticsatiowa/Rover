from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch.actions import ExecuteProcess


def generate_launch_description():
    # include launch file in video_feed/launch/video_feed.launch.py

    rover_ip = "192.168.1.70"
    rover_user = "ethan"
    rover_launch_cmd = "echo 'TODO'"
    tmux_session_name = "ros"

    # Start video feeds
    launch_video_feeds = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution(
                [FindPackageShare("video_feed"), "launch/cams.launch.xml"]
            )
        )
    )

    # Start foxglove_bridge node
    node_foxglove_bridge = Node(
        name="foxglove_bridge",
        package="foxglove_bridge",
        executable="foxglove_bridge",
        output="screen",
    )

    # Start foxglove studio
    exec_foxglove_studio = ExecuteProcess(cmd=["foxglove-studio"])

    # SSh into rover and start tmux session if it doesn't exist - create it and run launch command then exit
    exec_start_rover = ExecuteProcess(
        cmd=[
            f"ssh {rover_user}@{rover_ip} 'if ! tmux has-session -t {tmux_session_name}; then tmux new-session -d -s {tmux_session_name} \"{rover_launch_cmd}\"; fi'; exit"
        ]
    )
    return LaunchDescription(
        [
            node_foxglove_bridge,
            exec_foxglove_studio,
            launch_video_feeds,
            exec_start_rover,
        ]
    )
