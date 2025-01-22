from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    launch_description_list = []


    launch_description_list.append(
        IncludeLaunchDescription(
            AnyLaunchDescriptionSource(
                    PathJoinSubstitution(
                    [
                        FindPackageShare("realsense2_camera"),
                        "launch/rs_launch.py",
                    ]

                )
            ),
            launch_arguments={
                "depth_module.depth_profile": "640x480x30",
                "pointcloud.enable": "true",
                "unite_imu_method": "2",
                "tf_publish_rate": "5.0",
                "enable_gyro": "true",
                "enable_accel": "true",
                "enable_infra1": "true",
            }.items(),
        )
    )

    return LaunchDescription(launch_description_list)
