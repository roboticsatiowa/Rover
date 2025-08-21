from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import SetParameter


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
                "initial_reset": "true",
                "depth_module.depth_profile": "640x480x30",
                "enable_pointcloud": "true",
                
            }.items(),
        )
    )

    return LaunchDescription(launch_description_list)
