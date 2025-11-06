import os
import yaml

from ament_index_python import get_package_share_directory
from launch import LaunchDescription
from moveit_configs_utils import MoveItConfigsBuilder
from launch_ros.actions import Node
from launch_ros.descriptions import ComposableNode


def generate_launch_description():
    ld = LaunchDescription()

    # =========================================
    #               MOVEIT2
    # =========================================

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
            mappings={"hw_type": "mock"},
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

    ld.add_action(
        Node(
            package="moveit_ros_move_group",
            executable="move_group",
            output="screen",
            parameters=[moveit_config.to_dict()],
        )
    )

    # =========================================
    #                 RVIZ2
    # =========================================

    ld.add_action(
        Node(
            package="rviz2",
            executable="rviz2",
            name="rviz2",
            parameters=[
                moveit_config.robot_description,
                moveit_config.robot_description_semantic,
                moveit_config.robot_description_kinematics,
                moveit_config.planning_pipelines,
                moveit_config.joint_limits,
            ],
        )
    )

    # =========================================
    #             Transform
    # =========================================

    # Publishes full URDF "poses" based on the joint states provided by the joint_state_broadcaster
    ld.add_action(
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            name="robot_state_publisher",
            output="both",
            parameters=[moveit_config.robot_description],
        )
    )

    # Creates a transform from world frame to base_link frame of the rover. This is a placeholder for robot localization
    ld.add_action(
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            name="static_transform_publisher",
            output="log",
            arguments=["--frame-id", "world", "--child-frame-id", "base_link"],
        )
    )

    # =========================================
    #             ROS2 CONTROL
    # =========================================

    ros2_controllers_path = os.path.join(
        get_package_share_directory("uirover_moveit"),
        "config",
        "ros2_controllers.yaml",
    )

    # Controller Manager. Responsible for managing individual controllers (spawned below) and their access to hardware
    ld.add_action(
        Node(
            package="controller_manager",
            executable="ros2_control_node",
            parameters=[ros2_controllers_path],
            remappings=[
                ("/controller_manager/robot_description", "/robot_description"),
            ],
            output="both",
        )
    )

    # Spawn controller: joint state broadcaster. Constantly reads and publishes hardware position/encoder data
    ld.add_action(
        Node(
            package="controller_manager",
            executable="spawner",
            arguments=[
                "joint_state_broadcaster",
                "--controller-manager",
                "/controller_manager",
            ],
        )
    )

    # Spawn controller: arm controller. Responsible for sending commands to arm motors
    ld.add_action(
        Node(
            package="controller_manager",
            executable="spawner",
            arguments=["arm_controller", "-c", "/controller_manager"],
        )
    )

    # =========================================
    #             USER INTERACTION
    # =========================================

    with open(
        os.path.join(
            get_package_share_directory("uirover_moveit"), "config", "moveit_servo.yaml"
        )
    ) as file:
        moveit_servo_params = {"moveit_servo": yaml.safe_load(file)}


    

    # ld.add_action(
    #     Node(
    #         package="joy",
    #         executable="joy_node",
    #         name="joy_node",
    #     )
    # )

    # ld.add_action(
    #     Node(
    #         package="teleop_twist_joy",
    #         executable="teleop_node",
    #         name="teleop_twist_joy_node",
    #         parameters=[
    #             {"publish_stamped_twist": True},
    #             {"require_enable_button": False},
    #             {"frame": "end_effector"}  # indicates we are moving up/down l/r etc. relative to the hands current orientation
    #         ],
    #         remappings=[("/cmd_vel", "/servo_node/delta_twist_cmds")],
    #     )
    # )

    # ld.add_action(
    #     Node(
    #         package="moveit_servo",
    #         executable="servo_node",
    #         parameters=[
    #             moveit_servo_params,
    #             moveit_config.robot_description,
    #             moveit_config.robot_description_semantic,
    #             moveit_config.robot_description_kinematics,
    #         ],
    #     )
    # )

    return ld
