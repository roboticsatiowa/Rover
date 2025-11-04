import os
import json

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution

from ament_index_python.packages import get_package_share_directory

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import Command, FindExecutable
from moveit_configs_utils import MoveItConfigsBuilder


def generate_launch_description():
    ld = LaunchDescription()

    # ================================
    # Configs
    # ================================

    ublox_config = PathJoinSubstitution(
        [FindPackageShare("uirover_gnss"), "config", "zed_f9p.yaml"]
    )

    controller_config = PathJoinSubstitution(
        [FindPackageShare("uirover_description"), "config", "diff_drive.yaml"]
    )

    zenoh_config = PathJoinSubstitution(
        [FindPackageShare("uirover_bringup"), "config", "zenoh_rover.config.json"]
    )
    
    moveit_controller_config = PathJoinSubstitution(
        [FindPackageShare("uirover_moveit"), "config", "ros2_controllers.yaml"]
    )

    robot_description_path = PathJoinSubstitution(
        [
            FindPackageShare("uirover_description"),
            "urdf",
            "uirover.urdf.xacro",
        ]
    )

    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            robot_description_path,
            " hw_type:='mock'",
        ]
    )

    moveit_config = (
        MoveItConfigsBuilder(
            robot_name="uirover",
            package_name="uirover_moveit",
        )
        .robot_description(
            file_path=os.path.join(
                get_package_share_directory("uirover_description"),
                "urdf",
                "uirover.urdf.xacro",
            )
        )
        .trajectory_execution(file_path="config/moveit_controllers.yaml")
        .planning_scene_monitor(
            publish_robot_description=True, publish_robot_description_semantic=True
        )
        .planning_pipelines(
            pipelines=["ompl", "stomp", "pilz_industrial_motion_planner"]
        )
        .to_moveit_configs()
    )

    nodes = []

    try:
        i = 0
        for camera in os.listdir("/dev/Arducam"):
            if not camera.startswith("CAM"):
                continue
            index = int(camera[3:])
            ld.add_action(
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

    ld.add_action(
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            name="robot_state_publisher",
            output="screen",
            namespace="uirover",
            parameters=[
                {"robot_description": robot_description_content},
            ],
        )
    )
    ld.add_action(
        Node(
            package="joint_state_publisher",
            executable="joint_state_publisher",
            name="joint_state_publisher",
            namespace="uirover",
            output="screen",
        )
    )
    ld.add_action(
        Node(
            package="moveit_ros_move_group",
            executable="move_group",
            output="screen",
            namespace="uirover",
            parameters=[moveit_config.to_dict()],
        )
    )

    # This node spawns controllers AND hardware interfaces based on the
    # contents of the <ros2_control> tags in the URDF
    ld.add_action(
        Node(
            package="controller_manager",
            executable="ros2_control_node",
            namespace="uirover",
            parameters=[
                controller_config,
                moveit_controller_config

            ],
            output="both",
        )
    )

    ld.add_action(
        Node(
            package="controller_manager",
            executable="spawner",
            namespace="uirover",
            arguments=["arm_controller", 
                       "-c", 
                       "/uirover/moveit_simple_controller_manager",
                       ],
        )
    )

    # ld.add_action(
    #     Node(
    #         package="controller_manager",
    #         executable="spawner",
    #         arguments=["robotiq_gripper_controller", "-c", "/uirover/controller_manager"],
    #     )
    # )

    ld.add_action(
        Node(
            package="rviz2",
            namespace="",
            executable="rviz2",
            name="rviz2",
            arguments=[
                "-d"
                + os.path.join(
                    get_package_share_directory("uirover_basestation"),
                    "rviz",
                    "default.rviz",
                )
            ],
        )
    )

    # ============================
    # Visual SLAM
    # ============================

    ld.add_action(
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

    ld.add_action(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution(
                    [
                        FindPackageShare("uirover_moveit"),
                        "launch",
                        "move_group.launch.py",
                    ]
                )
            ),
        )
    )

    ld.add_action(
        Node(
            package="ublox_gps",
            executable="ublox_gps_node",
            name="ublox_gps_node",
            parameters=[ublox_config],
        )
    )

    ld.add_action(
        Node(
            package="rmw_zenoh_cpp",
            executable="rmw_zenohd",
            output="both",
        )
    )

    # ld.add_action(
    #     ExecuteProcess(
    #         cmd=f"ros2 bag record -o bag/{strftime('%Y-%m-%d-%H-%M-%S')} -a -d 9000".split(" "),
    #         output="log",
    #     )
    # )

    return ld
