from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription, ExecuteProcess
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


FOXGLOVE_URL="https://app.foxglove.dev/uiowarobotics/view?openIn=desktop&ds=foxglove-websocket&ds.url=ws%3A%2F%2Flocalhost%3A8765"


def generate_launch_description():
    launch_description_list = []

    launch_description_list.append(
        IncludeLaunchDescription(
            AnyLaunchDescriptionSource(
                PathJoinSubstitution(
                    [
                        FindPackageShare("foxglove_bridge"),
                        "launch",
                        "foxglove_bridge_launch.xml",
                    ]
                )
            )
        )
    )

    # joy node
    # FIXME: This is an official ROS2 package but is absolutely riddled with bugs
    # We should eventually write something custom, or fork it and fix. For now, it works.
    launch_description_list.append(
        Node(
            package="joy",
            executable="joy_node",
            name="joy_node",
            parameters=[{"coalesce_interval": "0.5", "default_trig_val": "true"}],
        )
    )

    # Foxglove
    # launch_description_list.append(
    #     ExecuteProcess(
    #         cmd=f"xdg-open {FOXGLOVE_URL}".split(" "),
    #         output="screen",
    #     )
    # )

    launch_description_list.append(
        ExecuteProcess(
            cmd=["rqt_graph"],
            output="screen",
        )
    )


    launch_description_list.append(
        IncludeLaunchDescription(
            AnyLaunchDescriptionSource(
                PathJoinSubstitution(
                    [FindPackageShare("uirover_gazebo"), "launch", "sim.launch.py"]
                )
            )
        )
    )

    # launch_description_list.append(
    #     ExecuteProcess(
    #         cmd=f'ros2 bag record -o bag/{strftime("%Y-%m-%d-%H-%M-%S")} -a --compression-mode file --compression-format zstd -d 9000'.split(
    #             " "
    #         ),
    #         output="screen",
    #     )
    # )

    return LaunchDescription(launch_description_list)
