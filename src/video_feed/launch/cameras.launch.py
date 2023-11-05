import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, Command

def generate_launch_description():
    # Use the 'ROS_HOME' environment variable if it's set, otherwise default to '/home/robotics/.ros'
    default_ros_home = os.environ.get('ROS_HOME', '/home/robotics/.ros')
    
    # Configure the camera_info_url to dynamically create the path to the camera calibration file
    camera_info_url = Command([
        'echo "file://', default_ros_home, '/camera_info/', LaunchConfiguration('camera_name'), '.yaml"'
    ])
    
    return LaunchDescription([
        DeclareLaunchArgument(
            'camera_name',
            default_value='default_cam',  # Set the default camera name to 'default_cam'
            description='Name of the camera node'
        ),
        DeclareLaunchArgument(
            'video_device',
            default_value='/dev/video0',  # Default to using '/dev/video0' for the webcam
            description='Video device path of the USB webcam'
        ),
        Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name=LaunchConfiguration('camera_name'),
            namespace='camera',
            parameters=[{
                'video_device': LaunchConfiguration('video_device'),
                'camera_info_url': camera_info_url,  # Use the dynamically constructed camera_info_url
                'camera_name': LaunchConfiguration('camera_name'),  # Set the camera name
                # Additional parameters can be added here if needed
            }],
            remappings=[('image_raw', 'video_feed')],
        ),
    ])
