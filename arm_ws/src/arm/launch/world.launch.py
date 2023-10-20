import launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo
from launch.substitutions import LaunchConfiguration
import launch_ros.actions

def generate_launch_description():
    world_file = LaunchConfiguration('world')

    return LaunchDescription([
        DeclareLaunchArgument('world', default_value='arm/worlds/arm_world.world', description='Path to the Gazebo world file'),
        LogInfo(
            condition=launch.conditions.IfCondition(launch.substitutions.LaunchConfiguration('world')),
            msg=[f"Using world file '{world_file}'"]
        ),
        launch_ros.actions.Node(
            package='gazebo_ros',
            executable='gazebo',
            name='gazebo',
            output='screen',
            arguments=['-s', 'libgazebo_ros_init.so', '-s', 'libgazebo_ros_factory.so', '-s', 'libgazebo_ros_control.so', '-s', 'libgazebo_ros_init.so', '--world', world_file]
        ),
    ])
