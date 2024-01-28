import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, Command

def generate_launch_description():
    # Get the directory of the current file (i.e., the directory where this launch file is located)
    launch_file_dir = os.path.dirname(os.path.realpath(__file__))
    
    # Initialize LaunchDescription list
    ld = []

    # Camera 1
    camera_name_1 = 'camera1'
    video_device_1 = '/dev/video2'
    if os.path.exists(video_device_1):
        camera_info_url_1 = Command([
            'echo "file://', launch_file_dir, '/', camera_name_1, '.yaml"'
        ])
        ld.append(Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name=camera_name_1,
            namespace=camera_name_1,
            parameters=[{
                'video_device': video_device_1,
                'camera_info_url': camera_info_url_1,
                'camera_name': camera_name_1,
            }],
            remappings=[('image_raw', 'image_raw')]
        ))

    # Camera 2
    camera_name_2 = 'camera2'
    video_device_2 = '/dev/video0'
    if os.path.exists(video_device_2):
        camera_info_url_2 = Command([
            'echo "file://', launch_file_dir, '/', camera_name_2, '.yaml"'
        ])
        ld.append(Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name=camera_name_2,
            namespace=camera_name_2,
            parameters=[{
                'video_device': video_device_2,
                'camera_info_url': camera_info_url_2,
                'camera_name': camera_name_2,
            }],
            remappings=[('image_raw', 'image_raw')]
        ))

    return LaunchDescription(ld)
