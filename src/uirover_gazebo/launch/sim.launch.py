from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, SetEnvironmentVariable, 
                            IncludeLaunchDescription, SetLaunchConfiguration)
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration, TextSubstitution
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource


def generate_launch_description():
    pkg_ros_gz_sim = get_package_share_directory('ros_gz_sim')
    pkg_uirover_gazebo = get_package_share_directory('uirover_gazebo')
    pkg_uirover_description = get_package_share_directory('uirover_description')
    
    gz_launch_path = PathJoinSubstitution([pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py'])
    gz_spawn_model_path = PathJoinSubstitution([pkg_ros_gz_sim, 'launch', 'gz_spawn_model.launch.py'])
    gz_world_path = PathJoinSubstitution([pkg_uirover_gazebo, 'worlds', 'moon.sdf'])
    gz_urdf_path = PathJoinSubstitution([pkg_uirover_description, 'urdf', 'uirover.urdf'])

    return LaunchDescription([
        # <param name="robot_description" command="$(find xacro)/xacro.py $(find robot_package)/urdf/robot.urdf.xacro" />
        SetEnvironmentVariable('GZ_SIM_RESOURCE_PATH', PathJoinSubstitution([pkg_uirover_gazebo, 'worlds'])),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(gz_launch_path),
            launch_arguments={
                'gz_args': [PathJoinSubstitution(gz_world_path)],
                'on_exit_shutdown': 'True'
            }.items(),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(gz_spawn_model_path),
            launch_arguments={
                'model': PathJoinSubstitution(gz_world_path),
                'file': gz_urdf_path,
                'robot_namespace': 'uirover',
                'x': '0.0',
                'y': '0.0',
                'z': '8.0',
            }.items(),
        ),
        Node(
            package='ros_gz_bridge',
            executable='parameter_bridge',
            arguments=[],
            remappings=[],
            output='screen'
        ),       
    ])