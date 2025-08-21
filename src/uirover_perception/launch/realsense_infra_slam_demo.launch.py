# https://github.com/introlab/rtabmap_ros/blob/ros2/rtabmap_examples/launch/realsense_d435i_infra.launch.py

# Requirements:
#   A realsense D435i
#   Install realsense2 ros2 package (ros-$ROS_DISTRO-realsense2-camera)
# Example:
#   $ ros2 launch rtabmap_examples realsense_d435i_infra.launch.py

import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import Node, SetParameter
from launch.actions import IncludeLaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    parameters = [
        {
            "frame_id": "realsense_link",
            "subscribe_depth": True,
            "subscribe_odom_info": True,
            "approx_sync": False,
            "wait_imu_to_init": True,
        }
    ]

    remappings = [
        ("imu", "rover/realsense/imu/data"),
        ("rgb/image", "rover/realsense/infra1/image_rect_raw"),
        ("rgb/camera_info", "rover/realsense/infra1/camera_info"),
        ("depth/image", "rover/realsense/depth/image_rect_raw"),
    ]

    return LaunchDescription(
        [
            # Launch camera driver
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    [
                        os.path.join(
                            get_package_share_directory("realsense2_camera"), "launch"
                        ),
                        "/rs_launch.py",
                    ]
                ),
                launch_arguments={
                    "camera_name": "realsense",
                    "camera_namespace": "rover",
                    "enable_gyro": "true",
                    "enable_accel": "true",
                    "unite_imu_method": "2",
                    "enable_infra1": "true",
                    "enable_infra2": "true",
                    "enable_sync": "true",
                }.items()
            ),
            
            # Hack to disable IR emitter
            SetParameter(name="depth_module.emitter_enabled", value=0),
            
            Node(
                package="rtabmap_odom",
                executable="rgbd_odometry",
                output="screen",
                parameters=parameters,
                remappings=remappings,
            ),
            Node(
                package="rtabmap_slam",
                executable="rtabmap",
                output="screen",
                parameters=parameters,
                remappings=remappings,
                arguments=["-d"],
            ),
            Node(
                package="rtabmap_viz",
                executable="rtabmap_viz",
                output="screen",
                parameters=parameters,
                remappings=remappings,
            ),
            # Compute quaternion of the IMU
            Node(
                package="imu_filter_madgwick",
                executable="imu_filter_madgwick_node",
                namespace="rover",
                output="screen",
                parameters=[
                    {"use_mag": False, "world_frame": "enu", "publish_tf": False}
                ],
                remappings=[("imu/data_raw", "realsense/imu"),
                            ("imu/data", "realsense/imu/data")],
            ),
        ]
    )
