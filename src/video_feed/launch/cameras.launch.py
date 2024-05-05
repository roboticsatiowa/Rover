import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import Command

def generate_launch_description():
    # Get the directory of the current file
    launch_file_dir = os.path.dirname(os.path.realpath(__file__))
    
    # Initialize LaunchDescription list
    ld = []
    pixel_format = 'yuyv'  # Ensure this format is supported by the device
    
    # Camera 1
    camera_name_1 = 'camera1'
    video_device_1 = '/dev/video0'
    camera_info_url = Command(['echo "file://', launch_file_dir, '/', 'fisheye_cam_calib', '.yaml"'])
    
    if os.path.exists(video_device_1):
        ld.append(Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name=camera_name_1,
            namespace=camera_name_1,
            parameters=[{
                'video_device': video_device_1,
                'camera_info_url': camera_info_url,
                'camera_name': camera_name_1,
                'pixel_format': pixel_format,
            }],
            remappings=[('image_raw', 'image_raw')]
        ))


    # Camera 2
    camera_name_2 = 'camera2'
    video_device_2 = '/dev/video4'
    
    if os.path.exists(video_device_2):
        ld.append(Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name=camera_name_2,
            namespace=camera_name_2,
            parameters=[{
                'video_device': video_device_2,
                'camera_info_url': camera_info_url,
                'camera_name': camera_name_2,
                'pixel_format': pixel_format,
            }],
            remappings=[('image_raw', 'image_raw')]
        ))
    
     # Camera 3
    camera_name_3 = 'camera3'
    video_device_3 = '/dev/video8'  # Ensure this is correct
    
    if os.path.exists(video_device_3):
        ld.append(Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name=camera_name_3,
            namespace=camera_name_3,
            parameters=[{
                'video_device': video_device_3,
                'camera_info_url': camera_info_url,
                'camera_name': camera_name_3,
                'pixel_format': pixel_format,
            }],
            remappings=[('image_raw', 'image_raw')]
        ))

    # Camera 4
    camera_name_4 = 'camera4'
    video_device_4 = '/dev/video12'  # Ensure this is correct
    
    if os.path.exists(video_device_4):
        ld.append(Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name=camera_name_4,
            namespace=camera_name_4,
            parameters=[{
                'video_device': video_device_4,
                'camera_info_url': camera_info_url,  
                'camera_name': camera_name_4,
                'pixel_format': pixel_format,
            }],
            remappings=[('image_raw', 'image_raw')]
        ))


    return LaunchDescription(ld)
