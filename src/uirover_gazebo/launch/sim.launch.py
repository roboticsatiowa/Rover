from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import SetEnvironmentVariable, IncludeLaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource


def generate_launch_description():
    pkg_ros_gz_sim = get_package_share_directory('ros_gz_sim')
    pkg_ros_gz_bridge = get_package_share_directory('ros_gz_bridge')
    pkg_uirover_gazebo = get_package_share_directory('uirover_gazebo')
    pkg_uirover_description = get_package_share_directory('uirover_description')
    
    gz_launch_path = PathJoinSubstitution([pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py'])
    gz_spawn_model_path = PathJoinSubstitution([pkg_ros_gz_sim, 'launch', 'gz_spawn_model.launch.py'])
    gz_world_path = PathJoinSubstitution([pkg_uirover_gazebo, 'worlds', 'moon.sdf'])
    gz_urdf_path = PathJoinSubstitution([pkg_uirover_description, 'urdf', 'uirover_sim.urdf'])

    return LaunchDescription([
        # <param name="robot_description" command="$(find xacro)/xacro.py $(find robot_package)/urdf/robot.urdf.xacro" />
        SetEnvironmentVariable('GZ_SIM_RESOURCE_PATH', PathJoinSubstitution([pkg_uirover_gazebo, 'worlds'])),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(gz_launch_path),
            launch_arguments={
                'gz_args': [gz_world_path],
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
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([pkg_ros_gz_bridge, 'launch', 'ros_gz_bridge.launch.py'])),
            launch_arguments={
                'bridge_name': 'gazebo_bridge',
                'config_file': PathJoinSubstitution([pkg_uirover_gazebo, 'config', 'bridge_config.yaml']),
            }.items(),
        ),
    ])