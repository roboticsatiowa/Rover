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
    pixel_format = 'yuyv'
    color_format = 'yuv420p'
    # Camera 1
    camera_name_1 = 'narrow_stereo'
    video_device_1 = '/dev/video0'
    camera1_info_url = Command(['echo "file://', launch_file_dir, '/', 'camera1', '.yaml"'])
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
                'image_width' : 800,
                'image_height' : 600

                # 'image_transport' : 'compressed',
                # 'jpeg_quality' : 1
                # 'color_format': color_format
            }],
            remappings=[('image_raw', 'image_raw')]
        ))

        

    # Camera 2
    camera_name_2 = 'camera1' 
    video_device_2 = '/dev/video4'
    
    if os.path.exists(video_device_2):
    
        ld.append(Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name=camera_name_2,
            namespace=camera_name_2,
            parameters=[{
                'video_device': video_device_2,
                'camera_info_url': camera1_info_url,
                'camera_name': camera_name_2,
                'pixel_format': pixel_format,
                # 'image_transports' : 'compressed',
                # 'jpeg_quality' : 1
                # 'color_format': color_format
                'image_width' : 800,
                'image_height' : 600
            }],
            remappings=[('image_raw', 'image_raw')]
        ))

        ld.append(Node(
                package='image_transport',
                executable='republish',
                name='republisher_camera_1',
                namespace=camera_name_1,
                arguments=['raw', f'in:=/{camera_name_2}/image_raw', 'compressed', f'out:=/{camera_name_2}/image/compressed'],
                parameters=[{'jpeg_quality': 100}]
            ))

    # ld.append(Node(
    #     package = 'video_feed',
    #     executable='image_decompressor',
    # ))
    return LaunchDescription(ld)
