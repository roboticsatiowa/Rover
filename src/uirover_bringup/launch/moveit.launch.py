import os
from ament_index_python import get_package_share_directory
from launch import LaunchDescription
from moveit_configs_utils import MoveItConfigsBuilder
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()

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

    ros2_controllers_path = os.path.join(
        get_package_share_directory("uirover_moveit"),
        "config",
        "ros2_controllers.yaml",
    )

    ld.add_action(
        Node(
            package="moveit_ros_move_group",
            executable="move_group",
            output="screen",
            parameters=[moveit_config.to_dict()],
        )
    )

    ld.add_action(
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            name="static_transform_publisher",
            output="log",
            arguments=["--frame-id", "world", "--child-frame-id", "base_link"],
        )
    )

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

    # Publish TF
    ld.add_action(
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            name="robot_state_publisher",
            output="both",
            parameters=[moveit_config.robot_description],
        )
    )

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

    ld.add_action(
        Node(
            package="controller_manager",
            executable="spawner",
            arguments=["arm_controller", "-c", "/controller_manager"],
        )
    )

    return ld
