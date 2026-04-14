from moveit_configs_utils import MoveItConfigsBuilder
from moveit_configs_utils.launches import generate_demo_launch
from launch_ros.actions import Node


def generate_launch_description():
    moveit_config = MoveItConfigsBuilder("uirover", package_name="uirover_moveit").to_moveit_configs()
    ld = generate_demo_launch(moveit_config)
    ld.add_action(Node(
        package='uirover_mock_hardware',
        executable='odrive',
    ))
    return ld
