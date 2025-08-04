from launch import LaunchDescription 
import launch
from launch.actions import ExecuteProcess, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource, AnyLaunchDescriptionSource
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution


def generate_launch_description():
    launch_description_list = []
    
    zenoh_config = PathJoinSubstitution(
        [FindPackageShare("uirover_bringup"), "config", "zenoh_basestation.config.json"]
    )

    # Zenoh Bridge
    # https://zenoh.io/blog/2021-09-28-iac-experiences-from-the-trenches/
    launch_description_list.append(
        ExecuteProcess(
            cmd=['zenoh-bridge-ros2dds', 
                 '-c', 
                 zenoh_config],
            output="both",
        )
    )
    
    launch_description_list.append(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([
                    FindPackageShare("uirover_video"),
                    "launch",
                    "gstreamer_sink.launch.py"
                ])
            ),
            launch_arguments={
                "host": "192.168.55.1"
            }.items()
        )
    )
        

    launch_description_list.append(
        Node(
            name="joy",
            
            package="joy",
            executable="joy_node",

        )
    )
    
    launch_description_list.append(
        Node(
            package='foxglove_bridge',
            executable='foxglove_bridge',
            name='foxglove_bridge'
        )
    )

    return LaunchDescription(launch_description_list)
