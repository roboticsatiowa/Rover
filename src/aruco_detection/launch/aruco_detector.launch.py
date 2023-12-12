from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='aruco_detection',
            namespace='aruco_detector',
            executable='aruco_detector_node',
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
