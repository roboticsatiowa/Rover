import os

import launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration

def generate_camera_info_url(camera_name):
    ros_home = os.environ.get('ROS_HOME', '/home/robotics/.ros')
    return f'file://{ros_home}/camera_info/{camera_name}.yaml'

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'camera_name',
            default_value='camera',
            description='Name of the camera node'
        ),
        DeclareLaunchArgument(
            'video_device',
            default_value='/dev/video0',
            description='Video device path of the USB webcam'
        ),
        Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name=LaunchConfiguration('camera_name'),
            namespace='camera',
            parameters=[{
                'video_device': LaunchConfiguration('video_device'),
                'camera_info_url': generate_camera_info_url(LaunchConfiguration('camera_name')),
            }],
            remappings=[('image_raw', 'video_feed')],
        ),
    ])
