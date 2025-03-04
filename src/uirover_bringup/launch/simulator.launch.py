from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    ExecuteProcess,
    IncludeLaunchDescription,
    RegisterEventHandler,
    OpaqueFunction,
)
from launch.substitutions import (
    PathJoinSubstitution,
    LaunchConfiguration,
)
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

from time import strftime


FOXGLOVE_URL = "https://app.foxglove.dev/uiowarobotics/view?openIn=desktop&ds=foxglove-websocket&ds.url=ws%3A%2F%2Flocalhost%3A8765"


def generate_launch_description():
    use_sim_time = LaunchConfiguration("use_sim_time", default=True)

    # ======= Supplimentary config files ======= #

    controller_config = (
        PathJoinSubstitution(
            [FindPackageShare("uirover_description"), "config", "diff_drive.yaml"]
        )
    )

    gz_bridg_config = (
        PathJoinSubstitution(
            [FindPackageShare("uirover_gazebo"), "config", "bridge_config.yaml"]
        ),
    )

    # ======= Launch files ======= #

    launch_gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [
                PathJoinSubstitution(
                    [
                        FindPackageShare("ros_gz_sim"),
                        "launch",
                        "gz_sim.launch.py",
                    ]
                )
            ]
        ),
        # launch_arguments=[("gz_args", [" -r -v 1 'https://fuel.gazebosim.org/1.0/Penkatron/worlds/Rubicon World'"])],
        launch_arguments=[("gz_args", [" -r -v 1 empty.sdf"])],
    )

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

    # ======= Nodes ======= #

    node_gazebo_spawn_urdf = Node(
        package="ros_gz_sim",
        executable="create",
        output="screen",
        arguments=[
            "-topic",
            "robot_description",
            "-name",
            "uirover",
            "-allow_renaming",
            "true",
            "-z",
            "4",
        ],
    )
    node_joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster"],
    )
    node_diff_drive_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["diff_drive_base_controller", "--param-file", controller_config],
    )
    node_gazebo_parameter_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        output="screen",
        # arguments=["/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock"],
        parameters=[{"config_file": gz_bridg_config}],
    )
    node_foxglove_bridge = Node(
        package="foxglove_bridge",
        executable="foxglove_bridge",
        name="foxglove_bridge",
        output="screen",
    )
    # higher deadzone makes it easier to drive straight
    node_gamepad_publisher = Node(
        package="joy",
        executable="joy_node",
        name="joy_node",
        parameters=[{"coalesce_interval": 0.5,
                     "deadzone": 0.20}],
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

    cmd_ros_bag = ExecuteProcess(
        cmd=f"ros2 bag record -o bag/{strftime('%Y-%m-%d-%H-%M-%S')}_gazebo -a -d 9000".split(
            " "
        ),
        output="screen",
    )

    # ======= Arguments ======= #

    arg_use_sim_time = DeclareLaunchArgument(
        "use_sim_time",
        default_value=use_sim_time,
        description="If true, use simulated clock",
    )

    launch_description = LaunchDescription(
        [
            # Event handlers used to start nodes in a predictable order
            RegisterEventHandler(
                event_handler=OnProcessExit(
                    target_action=node_gazebo_spawn_urdf,
                    on_exit=[node_joint_state_broadcaster_spawner],
                )
            ),
            RegisterEventHandler(
                event_handler=OnProcessExit(
                    target_action=node_joint_state_broadcaster_spawner,
                    on_exit=[node_diff_drive_controller_spawner],
                )
            ),
            node_gazebo_spawn_urdf,
            launch_gazebo,
            node_gazebo_parameter_bridge,
            node_foxglove_bridge,
            node_gamepad_publisher,
            node_twist_publisher,
            cmd_ros_bag,
            arg_use_sim_time,
        ]
    )

    launch_description.add_action(OpaqueFunction(function=robot_state_publisher))

    return launch_description
