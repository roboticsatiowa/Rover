# https://github.com/introlab/rtabmap_ros/blob/ros2/rtabmap_examples/launch/realsense_d435i_stereo.launch.py

# Requirements:
#   A realsense D435i
#   Install realsense2 ros2 package (ros-$ROS_DISTRO-realsense2-camera)
# Example:
#   $ ros2 launch rtabmap_examples realsense_d435i_stereo.launch.py

import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    parameters=[{
          'frame_id':'realsense_link',
          'subscribe_stereo':True,
          'subscribe_odom_info':True,
          'wait_imu_to_init':True}]

    remappings=[
        ('imu', '/rover/slam/imu/data'),
        ('left/image_rect', '/rover/realsense/infra1/image_rect_raw'),
        ('left/camera_info', '/rover/realsense/infra1/camera_info'),
        ('right/image_rect', '/rover/realsense/infra2/image_rect_raw'),
        ('right/camera_info', '/rover/realsense/infra2/camera_info'),
        ('rgb/image',       '/data_throttled_image'),
        ('depth/image',     '/data_throttled_image_depth'),
        ('rgb/camera_info', '/data_throttled_camera_info'),
        ('scan',            '/jn0/base_scan'),
        ('gps/fix',             '/rover/gps/fix'),]

    return LaunchDescription([

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([os.path.join(
                get_package_share_directory('uirover_perception'), 'launch'),
                '/realsense.launch.py']),
        ),

        Node(
            package='rtabmap_odom', executable='stereo_odometry', output='screen',
            namespace='rover/slam',
            parameters=parameters,
            remappings=remappings),

        Node(
            package='rtabmap_slam', executable='rtabmap', output='screen',
            namespace='rover/slam',
            parameters=parameters,
            remappings=remappings,
            arguments=['-d']),

        Node(
            package='rtabmap_viz', executable='rtabmap_viz', output='screen',
            namespace='rover/slam',
            parameters=parameters,
            remappings=remappings),
                
        # Compute quaternion of the IMU
        Node(
            package='imu_filter_madgwick', executable='imu_filter_madgwick_node', output='screen',
            namespace='rover/slam',
            parameters=[{'use_mag': False, 
                         'world_frame':'enu', 
                         'publish_tf':False}],
            remappings=[('imu/data_raw', '/rover/realsense/imu'),
                        ('imu/data', '/rover/slam/imu/data')]),
    ])