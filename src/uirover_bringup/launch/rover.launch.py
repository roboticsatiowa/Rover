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

    camera_nodes = []
    try :
        for camera in os.listdir('/dev/Arducam'):
            index = int(camera[3:])
            camera_nodes.append(
                Node(
                    package="uirover_video",
                    executable="stream",
                    name=f"arducam_{index}",
                    output="both",
                    parameters=[{
                        'port': 5000 + index,
                        'device': f"/dev/Arducam/{camera}",
                        'host': '192.168.55.100'
                    }]
                )
            )
    except FileNotFoundError:
        # If the directory does not exist, we assume no cameras are connected
        pass

    # Include the camera nodes in the launch description
        

    # https://github.com/introlab/rtabmap_ros/blob/ros2/rtabmap_examples/launch/realsense_d435i_stereo.launch.py
    # Realsense Camera
    launch_realsense_d435i = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
                PathJoinSubstitution(
                [
                    FindPackageShare("realsense2_camera"),
                    "launch/rs_launch.py",
                ]

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
    node_video = Node(
        package="uirover_video",
        executable="camera_stream",
        output="both",
    )
    # publishes a topic containing the robots urdf description
    node_robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="both",
        parameters=[{"robot_description":robot_description_content}],
    )
    node_ublox_gps = Node(
        package="ublox_gps",
        executable="ublox_gps_node",
        name="ublox_gps_node",
        parameters=[ublox_config]
        
    )
    node_ros2_control = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[controller_config],
        output="both",
    )
    node_joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster", 
                   "--switch-timeout", 
                   "20.0",
                   "--service-call-timeout",
                   "20.0"],
    )
    node_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "diff_drive_base_controller",
            "--switch-timeout",
            "20.0",
            "-p",
            controller_config,
        ],
    )
    node_twist_publisher = Node(
        package="teleop_twist_joy",
        executable="teleop_node",
        name="teleop_twist_joy_node",
        remappings=[("/cmd_vel", "/diff_drive_base_controller/cmd_vel")],
        parameters=[
            {
                "publish_stamped_twist": True,
                "require_enable_button": False,
                "axis_angular.yaw": 0,
                "axis_linear.x": 1,
                "scale_linear.x": 2.5, # 0 - 255 
            }
        ],
    )

    # ======= Processes ======= #

    # Zenoh Bridge
    # https://zenoh.io/blog/2021-09-28-iac-experiences-from-the-trenches/
    cmd_zenoh_bridge = ExecuteProcess(
        # cmd=["zenoh-bridge-ros2dds", "-e", "tcp/192.168.55.100:7447"],
        cmd=["zenoh-bridge-ros2dds"],
        output="log",
    )
    cmd_ros_bag = ExecuteProcess(
        cmd=f"ros2 bag record -o bag/{strftime('%Y-%m-%d-%H-%M-%S')} -a -d 9000".split(
            " "
        ),
        output="log",
    )
    
    nodes = [
        # ros2_control
        node_ros2_control,
        node_robot_state_publisher,
        node_controller_spawner,
        node_joint_state_broadcaster_spawner,
        node_twist_publisher,
        # cmd_zenoh_bridge,
        cmd_ros_bag,
        node_ublox_gps,
        launch_realsense_d435i,
    ]
    nodes.extend(camera_nodes)

    launch_description = LaunchDescription(nodes)

    return launch_description

