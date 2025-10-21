import os

os.environ["RCUTILS_COLORIZED_OUTPUT"] = "1"

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution

from ament_index_python.packages import get_package_share_directory

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    ublox_config = PathJoinSubstitution(
        [FindPackageShare("uirover_gnss"), "config", "zed_f9p.yaml"]
    )

    zenoh_config = PathJoinSubstitution(
        [FindPackageShare("uirover_bringup"), "config", "zenoh_rover.config.json"]
    )
    
    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution(
                [
                    FindPackageShare("uirover_description"),
                    "urdf",
                    "uirover.urdf.xacro",
                ]
            ),
        ]
    )

    nodes = []

    try:
        i = 0
        for camera in os.listdir("/dev/Arducam"):
            if not camera.startswith("CAM"):
                continue
            index = int(camera[3:])
            nodes.append(
                Node(
                    package="uirover_perception",
                    executable="stream",
                    name=f"arducam_{i}",
                    output="both",
                    parameters=[
                        {
                            "port": 5000 + index,
                            "device": f"/dev/Arducam/{camera}",
                            "host": "192.168.55.100",
                            # 'width': 1280,
                            # 'height': 720,
                            "framerate": 20.0,
                        }
                    ],
                )
            )
            i += 1
    except FileNotFoundError:
        pass
    
    nodes.append(
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            output="screen",
            parameters=[{"robot_description": robot_description_content}],
        )
    )

    # ============================
    # Visual SLAM
    # ============================

    nodes.append(
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
                "initial_reset": "true",
            }.items(),
        ),
    )

    nodes.append(
        Node(
            package="imu_filter_madgwick",
            executable="imu_filter_madgwick_node",
            namespace="rover",
            output="screen",
            parameters=[{"use_mag": False, "world_frame": "enu", "publish_tf": False}],
            remappings=[
                ("imu/data_raw", "realsense/imu"),
                ("imu/data", "realsense/imu/data"),
            ],
        ),
    )

    nodes.append(
        Node(
            package="rtabmap_odom",
            executable="rgbd_odometry",
            namespace="rover/slam",
            output="screen",
            parameters=[
                {
                    "frame_id": "realsense_link",
                    "subscribe_depth": True,
                    "subscribe_odom_info": True,
                    "approx_sync": False,
                    "wait_imu_to_init": True,
                }
            ],
            remappings=[
                ("imu", "/rover/realsense/imu/data"),
                ("rgb/image", "/rover/realsense/infra1/image_rect_raw"),
                ("rgb/camera_info", "/rover/realsense/infra1/camera_info"),
                ("depth/image", "/rover/realsense/depth/image_rect_raw"),
            ],
        ),
    )

    nodes.append(
        Node(
            package="rtabmap_slam",
            executable="rtabmap",
            namespace="rover/slam",
            output="screen",
            parameters=[
                {
                    "frame_id": "realsense_link",
                    "subscribe_depth": True,
                    "subscribe_odom_info": True,
                    "approx_sync": False,
                    "wait_imu_to_init": True,
                }
            ],
            remappings=[
                ("imu", "/rover/realsense/imu/data"),
                ("rgb/image", "/rover/realsense/infra1/image_rect_raw"),
                ("rgb/camera_info", "/rover/realsense/infra1/camera_info"),
                ("depth/image", "/rover/realsense/depth/image_rect_raw"),
            ],
            arguments=["-d"],
        ),
    )

    nodes.append(
        Node(
            package="rtabmap_viz",
            executable="rtabmap_viz",
            namespace="rover/slam",
            output="screen",
            parameters=[
                {
                    "frame_id": "realsense_link",
                    "subscribe_depth": True,
                    "subscribe_odom_info": True,
                    "approx_sync": False,
                    "wait_imu_to_init": True,
                }
            ],
            remappings=[
                ("rgb/image", "/rover/realsense/infra1/image_rect_raw"),
                ("rgb/camera_info", "/rover/realsense/infra1/camera_info"),
                ("depth/image", "/rover/realsense/depth/image_rect_raw"),
            ],
        ),
    )

    nodes.append(
        Node(
            package="ublox_gps",
            executable="ublox_gps_node",
            name="ublox_gps_node",
            parameters=[ublox_config],
        )
    )

    nodes.append(Node(package="uirover_simple_hardware", executable="hardware_node"))

    nodes.append(
        Node(
            package="rmw_zenoh_cpp",
            executable="rmw_zenohd",
            output="both",
        )
    )

    # nodes.append(
    #     ExecuteProcess(
    #         cmd=f"ros2 bag record -o bag/{strftime('%Y-%m-%d-%H-%M-%S')} -a -d 9000".split(" "),
    #         output="log",
    #     )
    # )

    return LaunchDescription(nodes)
