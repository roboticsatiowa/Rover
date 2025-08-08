from launch import LaunchDescription 
from launch.actions import ExecuteProcess
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    launch_description_list = []
    
    launch_description_list.append(
        ExecuteProcess(
            cmd=['mapproxy-util', 'serve-develop', 
                 PathJoinSubstitution(
                     [FindPackageShare("uirover_basestation"), "mapproxy", "mapproxy.yaml"]
                 )],
            output="both",
        )
    )
    
    return LaunchDescription(launch_description_list)