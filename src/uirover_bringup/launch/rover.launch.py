import os
from platform import node
from time import strftime

os.environ["RCUTILS_COLORIZED_OUTPUT"] = "1"

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, ExecuteProcess
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution, Command, FindExecutable

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():

    controller_config = PathJoinSubstitution(
        [FindPackageShare("uirover_description"), "config", "diff_drive.yaml"]
    )

    ublox_config = PathJoinSubstitution(
        [FindPackageShare("uirover_gnss"), "config", "zed_f9p.yaml"]
    )

    zenoh_config = PathJoinSubstitution(
        [FindPackageShare("uirover_bringup"), "config", "zenoh_rover.config.json"]
    )

    nodes = []

    
    nodes.append(
        Node(
            package="uirover_video",
            executable="stream",
            name=f"camera_0",
            output="both",
            parameters=[{
                'port': 5000,
                'device': f"/dev/video0",
                'host': '192.168.55.100',
                'width': 1920,
                'height': 1080,
                'framerate': 20.0
            }]
        )
    )

    nodes.append(
        Node(
            package="uirover_video",
            executable="stream",
            name=f"camera_1",
            output="both",
            parameters=[{
                'port': 5001,
                'device': f"/dev/video1",
                'host': '192.168.55.100',
                'width': 1280,
                'height': 720,
                'framerate': 20.0
            }]
        )
    )
    nodes.append(
        IncludeLaunchDescription(
            AnyLaunchDescriptionSource(
                PathJoinSubstitution(
                    [FindPackageShare("realsense2_camera"), "launch/rs_launch.py"]
                )
            ),
            launch_arguments={
                "camera_namespace": "uirover",
                "camera_name": "D435i_realsense_camera",
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

    nodes.append(
        Node(
            package="ublox_gps",
            executable="ublox_gps_node",
            name="ublox_gps_node",
            parameters=[ublox_config]
        )
    )

    nodes.append(
        Node(
            package='uirover_simple_hardware',
            executable='hardware_node'
        )
    )

    nodes.append(
        Node(
            package="rmw_zenoh_cpp",
            executable="rmw_zenohd",
            output="log",
        )
    )

    nodes.append(
        Node(
            name="rover_joy",
            package="joy",
            executable="game_controller_node",

        )
    )


    nodes.append(
        ExecuteProcess(
            cmd=f"ros2 bag record -o bag/{strftime('%Y-%m-%d-%H-%M-%S')} -a -d 9000".split(" "),
            output="log",
        )
    )

    return LaunchDescription(nodes)
