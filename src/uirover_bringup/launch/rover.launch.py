import os
import json

from launch import LaunchDescription
from launch.actions import (
    IncludeLaunchDescription,
    DeclareLaunchArgument,
    SetEnvironmentVariable,
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import (
    PathJoinSubstitution,
    LaunchConfiguration,
    PythonExpression,
)

from launch.conditions import IfCondition

from ament_index_python.packages import get_package_share_directory

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import Command, FindExecutable
from moveit_configs_utils import MoveItConfigsBuilder


def generate_launch_description():
    ld = LaunchDescription()

    # ==================================
    #      LAUNCH CONFIGURATIONS
    # ==================================

    # change this by appending `hw_type:=[hw_type_goes_here]` to the end of launch command
    use_sim_time = LaunchConfiguration("use_sim_time", default=True)
    headless = LaunchConfiguration("headless", default=True)
    hw_type = LaunchConfiguration("hw_type", default="target")

    ld.add_action(
        DeclareLaunchArgument(
            "hw_type", default_value=hw_type, choices=["target", "mock", "gazebo"]
        )
    )
    ld.add_action(
        DeclareLaunchArgument(
            "use_sim_time",
            default_value=use_sim_time,
            description="If true, use simulated clock",
        )
    )
    ld.add_action(
        DeclareLaunchArgument(
            "headless",
            default_value=headless,
            description="If true, assume basestation will handle GUI and user input. Otherwise spawn Rviz and other basestation nodes",
        )
    )

    # ==================================
    #      CONFIGURATION FILES
    # ==================================

    ublox_config = PathJoinSubstitution(
        [FindPackageShare("uirover_gnss"), "config", "zed_f9p.yaml"]
    )

    zenoh_config = PathJoinSubstitution(
        [FindPackageShare("uirover_bringup"), "config", "zenoh_rover.config.json"]
    )

    ekf_config_path = os.path.join(get_package_share_directory("uirover_navigation"),"config", "ekf.yaml")

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
            f" hw_type:=",
            hw_type,
        ]
    )

    # ==================================
    #             PERCEPTION
    # ==================================

    # this is super hacky and needs to go
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

    # ld.add_action(
    #     Node(
    #         package="depth_image_proc",
    #         executable="point_cloud_xyz_node",
    #         namespace="/uirover/perception",
    #         remappings=[
    #             ("camera_info", "/uirover/perception/d435i_rgbd_info"),
    #             ("image_rect", "/uirover/perception/d435i_rgbd"),
    #             ("points", "/uirover/perception/d435i_points")
    #         ]
    #     )
    # )

    # ==================================
    #     NAVIGATION AND LOCALIZATION
    # ==================================

    ld.add_action(
        Node(
            package="robot_localization",
            executable="ekf_node",
            name="ekf_node",
            output="screen",
            namespace="/uirover/navigation",
            parameters=[
                ekf_config_path, 
                {"use_sim_time": LaunchConfiguration("use_sim_time")},
            ],
        )
    )

    # ==================================
    #             MOVEIT2
    # ==================================

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
            ),
            mappings={"hw_type": hw_type},
        )
        .trajectory_execution(file_path="config/moveit_controllers.yaml")
        .planning_scene_monitor(
            publish_robot_description=False, publish_robot_description_semantic=True
        )
        .planning_pipelines(pipelines=["ompl"])
        .to_moveit_configs()
    )

    # sort of a hack since move MoveItConfigsBuilder doesnt support use_sim_time directly
    moveit_parameters = moveit_config.to_dict()
    moveit_parameters["use_sim_time"] = use_sim_time

    ld.add_action(
        Node(
            package="moveit_ros_move_group",
            executable="move_group",
            output="screen",
            namespace="/uirover/moveit",
            parameters=[moveit_parameters],
            remappings=[
                (
                    "/uirover/moveit/arm_controller/follow_joint_trajectory/_action/feedback",
                    "/uirover/control/arm_controller/follow_joint_trajectory/_action/feedback",
                ),
                (
                    "/uirover/moveit/arm_controller/follow_joint_trajectory/_action/status",
                    "/uirover/control/arm_controller/follow_joint_trajectory/_action/status",
                ),
                ("/uirover/moveit/joint_states", "/uirover/control/joint_states"),
            ],
        )
    )

    # ==================================
    #          ROS2 CONTROL
    # ==================================

    controllers_config_path = os.path.join(
        get_package_share_directory("uirover_controllers"),
        "config",
        "controllers.yaml",
    )

    # Controller Manager. Responsible for managing individual controllers (spawned below) and their access to hardware
    # https://control.ros.org/rolling/doc/ros2_control/controller_manager/doc/userdoc.html
    ld.add_action(
        Node(
            package="controller_manager",
            executable="ros2_control_node",
            parameters=[controllers_config_path],
            namespace="/uirover/control",
            remappings=[
                ("controller_manager/robot_description", "robot_description"),
            ],
            output="both",
            # When using gazebo, the gz_ros2_control plugin acts as the controller manager
            condition=IfCondition(PythonExpression(["'", hw_type, "'!= 'gazebo'"])),
        )
    )

    # Solves 3D pose of robot based on the supplied joint states (from joint_state_publisher) and URDF
    # https://index.ros.org/r/robot_state_publisher/#rolling
    ld.add_action(
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            name="robot_state_publisher",
            output="screen",
            namespace="/uirover/control",
            parameters=[
                {"robot_description": robot_description_content},
            ],
        )
    )

    # Spawns arm controller. trajectory controller is used to execute pre-planned trajectories.
    # https://control.ros.org/rolling/doc/ros2_controllers/joint_trajectory_controller/doc/userdoc.html
    ld.add_action(
        Node(
            package="controller_manager",
            executable="spawner",
            namespace="/uirover/control",
            arguments=[
                "arm_trajectory_controller",
                "-c",
                "controller_manager",
                "--switch-timeout",
                "15",
            ],
        )
    )

    ld.add_action(
        Node(
            package="controller_manager",
            executable="spawner",
            namespace="/uirover/control",
            arguments=[
                "arm_position_controller",
                "-c",
                "controller_manager",
                "--switch-timeout",
                "15",
                "--load-only",  # do not configure. this will be done when switching control modes
            ],
        )
    )

    # Spawns diff drive controller. Controls wheels
    # https://control.ros.org/rolling/doc/ros2_controllers/diff_drive_controller/doc/userdoc.html
    ld.add_action(
        Node(
            package="controller_manager",
            executable="spawner",
            namespace="/uirover/control",
            arguments=[
                "diff_drive_controller",
                "-c",
                "controller_manager",
                "--switch-timeout",
                "15",
            ],
        )
    )

    # https://control.ros.org/rolling/doc/ros2_controllers/joint_state_broadcaster/doc/userdoc.html
    ld.add_action(
        Node(
            package="controller_manager",
            executable="spawner",
            namespace="/uirover/control",
            arguments=[
                "joint_state_broadcaster",
                "-c",
                "controller_manager",
                "--switch-timeout",
                "15",
            ],
        )
    )

    # ==================================
    #         BASESTATION NODES
    # ==================================

    ld.add_action(
        Node(
            package="rviz2",
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
            parameters=[
                moveit_config.robot_description,
                moveit_config.robot_description_semantic,
                moveit_config.robot_description_kinematics,
                moveit_config.planning_pipelines,
                moveit_config.joint_limits,
            ],
            condition=IfCondition(PythonExpression(["'", headless, "'== 'False'"])),
        )
    )
    ld.add_action(
        Node(
            package="joy",
            executable="joy_node",
            name="joy_node",
            namespace="/basestation",
        )
    )

    # index.ros.org/r/teleop_twist_joy/#rolling
    ld.add_action(
        Node(
            package="teleop_twist_joy",
            executable="teleop_node",
            name="diff_drive_teleop_twist",
            namespace="/uirover/teleoperation",
            parameters=[
                {"publish_stamped_twist": True},
                {"require_enable_button": False},
                {"frame": "base_link"},
                {"axis_angular.yaw": 0},
                {"axis_linear.x": 1},
            ],
            remappings=[
                ("cmd_vel", "/uirover/control/diff_drive_controller/cmd_vel"),
                ("joy", "/basestation/joy"),
            ],
        )
    )
    ld.add_action(
        Node(
            package="foxglove_bridge",
            executable="foxglove_bridge",
            name="foxglove_bridge",
            condition=IfCondition(PythonExpression(["'", headless, "'== 'False'"])),
        )
    )

    # ==================================
    #             GAZEBO SIM
    # ==================================

    pkg_ros_gz_sim = get_package_share_directory("ros_gz_sim")
    pkg_uirover_gazebo = get_package_share_directory("uirover_gazebo")
    gz_world_path = PathJoinSubstitution([pkg_uirover_gazebo, "worlds", "rubicon.sdf"])
    gz_launch_path = PathJoinSubstitution(
        [pkg_ros_gz_sim, "launch", "gz_sim.launch.py"]
    )

    ld.add_action(
        SetEnvironmentVariable(
            "GZ_SIM_RESOURCE_PATH", PathJoinSubstitution([pkg_uirover_gazebo, "worlds"])
        ),
    )

    ld.add_action(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(gz_launch_path),
            launch_arguments={
                "gz_args": PathJoinSubstitution(
                    [pkg_uirover_gazebo, "worlds", "rubicon.sdf"]
                ),
                "on_exit_shutdown": "True",
            }.items(),
            condition=IfCondition(PythonExpression(["'", hw_type, "'== 'gazebo'"])),
        )
    )
    ld.add_action(
        Node(
            package="ros_gz_sim",
            executable="create",
            output="screen",
            arguments=[
                "-topic",
                "/uirover/control/robot_description",
                "-name",
                "uirover",
                "-allow_renaming",
                "true",
                "-z",
                "4",
                "-y",
                "1",
            ],
            condition=IfCondition(PythonExpression(["'", hw_type, "'== 'gazebo'"])),
        )
    )
    ld.add_action(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution(
                    [
                        FindPackageShare("ros_gz_bridge"),
                        "launch",
                        "ros_gz_bridge.launch.py",
                    ]
                )
            ),
            launch_arguments={
                "bridge_name": "gazebo_bridge",
                "config_file": PathJoinSubstitution(
                    [FindPackageShare("uirover_gazebo"), "config", "bridge_config.yaml"]
                ),
            }.items(),
        )
    )

    # ==================================
    #             MISC NODES
    # ==================================

    if hw_type == "target":
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
