import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, Command

def generate_launch_description():
    from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='aruco_detector',
            namespace='aruco_detector',
            executable='aruco_detector_node',  # Replace with your actual node executable name
            name='aruco_detector_node',
            output='screen',
            parameters=[
                {'camera1': '/camera1/image_raw'},
                {'camera2': '/camera2/image_raw'},
                {'aruco_dictionary_id': 0},
                {'marker_size': 0.05},
                {'processing_rate': 10},
                
            ],
        ),
    ])
