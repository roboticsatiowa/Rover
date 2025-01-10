from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node


def generate_launch_description():
    launch_description_list = []

    # Zenoh Bridge
    # https://zenoh.io/blog/2021-09-28-iac-experiences-from-the-trenches/
    launch_description_list.append(
        ExecuteProcess(
            cmd='zenoh-bridge-dds \
            --no-multicast-scouting \
            -l udp/0.0.0.0:7447 \
            -e udp/192.168.1.2:7447 \
            --allow "position|speed|levels|race_flags|emergency_stop"  \
            --max-frequency "race_flags=5" \
            --max-frequency "emergency_stop=20"'.split(" "),
            output="screen",
        )
    )

    launch_description_list.append(
        Node(
            name="joy",
            package="joy",
            executable="joy_node",

        )
    )

    return LaunchDescription(launch_description_list)
