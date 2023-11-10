import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, Command

def generate_launch_description():
    # Use the 'ROS_HOME' environment variable if it's set, otherwise default to '/home/robotics/.ros'
    default_ros_home = os.environ.get('ROS_HOME', '/home/robotics/.ros')
    
<<<<<<< HEAD
    # Configure the camera_info_url for the first camera
    camera_info_url_1 = Command([
        'echo "file://', default_ros_home, '/camera_info/', LaunchConfiguration('camera_name_1'), '.yaml"'
    ])
    
    # Configure the camera_info_url for the second camera
    camera_info_url_2 = Command([
        'echo "file://', default_ros_home, '/camera_info/', LaunchConfiguration('camera_name_2'), '.yaml"'
=======
    # Configure the camera_info_url to dynamically create the path to the camera calibration file
    camera_info_url = Command([
        'echo "file://', default_ros_home, '/camera_info/', LaunchConfiguration('camera_name'), '.yaml"'
>>>>>>> 655f3b74b2d2aa9ecb90a46595e527f4ea71f354
    ])
    
    return LaunchDescription([
        # Launch arguments for the first camera
        DeclareLaunchArgument(
<<<<<<< HEAD
            'camera_name_1',
            default_value='camera1',  # Set the default camera name to 'camera1'
            description='Name of the first camera node'
        ),
        DeclareLaunchArgument(
            'video_device_1',
            default_value='/dev/video2',  # Default to using '/dev/video0' for the first webcam
            description='Video device path of the first USB webcam'
=======
            'camera_name',
            default_value='default_cam',  # Set the default camera name to 'default_cam'
            description='Name of the camera node'
        ),
        DeclareLaunchArgument(
            'video_device',
            default_value='/dev/video0',  # Default to using '/dev/video0' for the webcam
            description='Video device path of the USB webcam'
>>>>>>> 655f3b74b2d2aa9ecb90a46595e527f4ea71f354
        ),
        # Launch arguments for the second camera
        DeclareLaunchArgument(
            'camera_name_2',
            default_value='camera2',  # Set the default camera name to 'camera2'
            description='Name of the second camera node'
        ),
        DeclareLaunchArgument(
            'video_device_2',
            default_value='/dev/video4',  # Default to using '/dev/video2' for the second webcam
            description='Video device path of the second USB webcam'
        ),
        # Node for the first camera
        Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name=LaunchConfiguration('camera_name_1'),
            namespace=LaunchConfiguration('camera_name_1'),
            parameters=[{
<<<<<<< HEAD
                'video_device': LaunchConfiguration('video_device_1'),
                'camera_info_url': camera_info_url_1,  # Use the dynamically constructed camera_info_url
                'camera_name': LaunchConfiguration('camera_name_1'),  # Set the camera name
=======
                'video_device': LaunchConfiguration('video_device'),
                'camera_info_url': camera_info_url,  # Use the dynamically constructed camera_info_url
                'camera_name': LaunchConfiguration('camera_name'),  # Set the camera name
>>>>>>> 655f3b74b2d2aa9ecb90a46595e527f4ea71f354
                # Additional parameters can be added here if needed
            }],
            remappings=[('image_raw', 'image_raw')]
        ),
        # Node for the second camera
        Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name=LaunchConfiguration('camera_name_2'),
            namespace=LaunchConfiguration('camera_name_2'),
            parameters=[{
                'video_device': LaunchConfiguration('video_device_2'),
                'camera_info_url': camera_info_url_2,  # Use the dynamically constructed camera_info_url
                'camera_name': LaunchConfiguration('camera_name_2'),  # Set the camera name
                # Additional parameters can be added here if needed
            }],
            remappings=[('image_raw', 'image_raw')]
        ),
    ])
