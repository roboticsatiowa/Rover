from launch import LaunchDescription

from launch.actions import IncludeLaunchDescription, ExecuteProcess, OpaqueFunction, RegisterEventHandler
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch.event_handlers import OnProcessExit

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

import os
from time import strftime


def generate_launch_description():

    common_params = {
        "rover_host": "192.168.1.2",
        "rover_hostname": "uirover",
        "basestation_host": "192.168.1.3",
        "basestation_hostname": "uibasestation",
    }

    controller_config = PathJoinSubstitution(
        [FindPackageShare("uirover_description"), "config", "diff_drive.yaml"]
    )

    # We use a launch action to launch the robot state publisher because the launch context is needed to perform the path join substitution
    def robot_state_publisher(context):
        robot_description = PathJoinSubstitution(
            [
                FindPackageShare("uirover_description"),
                "urdf",
                "uirover_sim.urdf",
            ],
        )

        with open(robot_description.perform(context), "r") as fd:
            robot_description_content = fd.read()

        node_robot_state_publisher = Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            output="screen",
            parameters=[{"robot_description": robot_description_content}],
        )

        return [node_robot_state_publisher]
    
    arducam_nodes = []

    # Arducam
    # list devices in /dev that start with "CAM" as per the udev rule
    if os.path.exists("/dev/Arducam"):
        arducam_devices = [
            int(i[3]) for i in os.listdir("/dev/Arducam") if i.startswith("CAM")
        ]
        for i in arducam_devices:
            arducam_nodes.append(
                Node(
                    package="uirover_arducam",
                    executable="arducam_video",
                    parameters=[{"cam_index": i}, common_params],
                    respawn=True,
                    respawn_delay=10,
                )
            )

    # GPS
    launch_ublox_gps = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution(
                [
                    FindPackageShare("ublox_gps"),
                    "launch/ublox_gps_node_zedf9p-launch.py",
                ]
            )
        )
    )
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

    # # Teensy Interface
    node_hardware_interface = Node(
        name="uirover_hardware",
        package="uirover_hardware",
        executable="uirover_hardware",
        respawn=True,
        respawn_delay=2,
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
    node_diff_drive_controller_spawner = Node(
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
    node_foxglove_bridge = Node(
        package="foxglove_bridge",
        executable="foxglove_bridge",
        name="foxglove_bridge",
    )
    # higher deadzone makes it easier to drive straight
    node_gamepad_publisher = Node(
        package="joy",
        executable="joy_node",
        name="joy_node",
        parameters=[{"coalesce_interval": 0.5, "deadzone": 0.20}],
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
            }
        ],
    )

    # ======= Processes ======= #

    # Zenoh Bridge
    # https://zenoh.io/blog/2021-09-28-iac-experiences-from-the-trenches/
    cmd_zenoh_bridge = ExecuteProcess(
        cmd="zenoh-bridge-dds --no-multicast-scouting -l udp/0.0.0.0:7447".split(
            " "
        ),
        output="screen",
    )
    cmd_ros_bag = ExecuteProcess(
        cmd=f"ros2 bag record -o bag/{strftime('%Y-%m-%d-%H-%M-%S')}_gazebo -a -d 9000".split(
            " "
        ),
        output="screen",
    )

    launch_description = LaunchDescription([
        # Event handlers used to start nodes in a predictable order
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=node_hardware_interface,
                on_exit=[node_joint_state_broadcaster_spawner],
            )
        ),
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=node_joint_state_broadcaster_spawner,
                on_exit=[node_diff_drive_controller_spawner],
            )
        ),
        node_hardware_interface,
        # node_joint_state_broadcaster_spawner,
        node_foxglove_bridge,
        node_gamepad_publisher,
        node_twist_publisher,
        cmd_zenoh_bridge,
        cmd_ros_bag,
        launch_ublox_gps,
        launch_realsense_d435i,
    ].extend(arducam_nodes))

    launch_description.add_action(OpaqueFunction(function=robot_state_publisher))

    return launch_description
