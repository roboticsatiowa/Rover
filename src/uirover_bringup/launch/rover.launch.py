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

    try:
        i = 0
        for camera in os.listdir('/dev/Arducam'):
            if not camera.startswith('CAM'): 
                continue
            index = int(camera[3:])
            nodes.append(
                Node(
                    package="uirover_video",
                    executable="stream",
                    name=f"arducam_{i}",
                    output="both",
                    parameters=[{
                        'port': 5000 + index,
                        'device': f"/dev/Arducam/{camera}",
                        'host': '192.168.55.100',
                        # 'width': 1280,
                        # 'height': 720,
                        'framerate': 20.0
                    }]
                )
            )
            i+= 1
    except FileNotFoundError:
        pass

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
            output="both",
        )
    )

    nodes.append(
        ExecuteProcess(
            cmd=f"ros2 bag record -o bag/{strftime('%Y-%m-%d-%H-%M-%S')} -a -d 9000".split(" "),
            output="log",
        )
    )

    return LaunchDescription(nodes)
