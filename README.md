<h1 align="center"><img src="https://github.com/roboticsatiowa/Documents-and-Resources/raw/main/Media/Banner.png?raw=true"/></h1>

<h1 align="center">Mars Rover Challenge</h1>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Issues](https://img.shields.io/github/issues/roboticsatiowa/Rover.svg)](https://github.com/roboticsatiowa/Rover/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/roboticsatiowa/Rover.svg)](https://github.com/roboticsatiowa/Rover/pulls)
[![License](https://img.shields.io/badge/license-GPLv3.0-blue.svg)](/LICENSE)

</div>

- [About](#about)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributors](#contributers)

---

## About

This is a ROS2 based project for the University of Iowa Robotics Club's Mars Rover. It is primarily designed around remote operation with future plans for partial or full autonomy. The rover is equipped with a 6 wheeled rocker bogie suspension system, a 5 DOF custom arm, and a variety of sensors. The onboard computing is handled by an Nvidia Jetson Orin coupled with a Teensy 4.1 microcontroller to assist with IO. The rover is equipped with an Intel Realsense depth camera, 3 Cameras, GPS, and a suite of miscellanious sensors for improved situational awareness.

---

## Getting Started

### System Requirements

**Native Install:**

- Ubuntu 24.04 LTS

**Docker install:**

- Any Unix based OS (Windows will also work, but has limititations)
- Docker
- Systemd based init system (for udev rules)

### Installation

Clone the repository to your workspace

```bash
git clone https://github.com/roboticsatiowa/Rover.git
cd Rover
```

Install ROS2 (you may skip this step if you already followed install instructions from their [documentation](https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debs.html))

```bash
./tools/ros/install_ros.sh
```

Install [rosdep](https://docs.ros.org/en/jazzy/Tutorials/Intermediate/Rosdep.html#what-is-rosdep) dependencies

```bash
./tools/ros/rosdep.sh
```

Install additional dependencies

```bash
./tools/ros/install_dependencies.sh
```

Install udev rules. These create more descriptive device names in `/dev` for example `/dev/ttyACM0 -> /dev/ttyTEENSY` and are required for ROS2 nodes to properly recognize hardware. More info in the [man page](https://man7.org/linux/man-pages/man7/udev.7.html) (`$ man udev`)

```bash
./tools/misc/symlink_udev.sh
```

### Building

A convenience script is provided to build the project

```bash
./tools/ros/build.sh
source install/setup.bash
```

> [!NOTE]
> You must source the `install/setup.bash` file in every new terminal so ROS2 can find the uirover packages. Otherwise you will see errors like `package 'uirover_bringup' not found`.

> [!IMPORTANT]
> Running `source install/setup.bash` will automatically set the appropriate environment variables for Zenoh Middleware. It defaults to using the basestation config file (`zenoh_basestation.config.json5`). If you are working on the rover you must manually set the `ZENOH_ROUTER_CONFIG_URI` environment variable to point to `zenoh_rover.config.json5` in `~/.bashrc` or manually before launching any nodes.

It is recommended to occasionally clean out the workspace. This will remove any generated files which can sometimes cause issues.


```bash
./tools/ros/clean.sh
```

## Usage

Basestation launch

```bash
ros2 launch uirover_bringup basestation.launch.py
```

Rover launch

```bash
ros2 launch uirover_bringup rover.launch.py
```

---

## Other Launch Files/Scripts

### URDF development

Preview the robot model in RViz. Useful when manually tweaking urdf files.

```bash
ros2 launch uirover_description preview.launch.py
```

### Mapproxy

[Mapproxy](https://mapproxy.org/) is a map tile provider which allows map data to be cached locally for offline use. To use it offline, the map cache must first be "seeded" with data from an online source.

To seed the map cache with data, run:

```bash
ros2 launch uirover_basestation mapproxy_seed.launch.py
```

this launch file starts the mapproxy server:

```bash
ros2 launch uirover_basestation mapproxy.launch.py
```

Map proxy UI can be found at [http://localhost:8080/demo/](http://localhost:8080/demo/) while the service is running.

Map tiles will be served at [http://localhost:8080/tiles/satellite/webmercator/{z}/{x}/{y}.png](http://localhost:8080/tiles/satellite/webmercator/1/1/1.png) where {x}, {y}, and {z} are the tile coordinates.

More info can be found in the [mapproxy docs](https://mapproxy.github.io/mapproxy/latest/index.html)

### MoveIt2

[MoveIt2](https://moveit.ros.org/) is a motion planning framework for ROS2. It will do inverse kinematics, path planning, and collision checking for the rover arm.

To view the demo for our arm, run:

```bash
ros2 launch uirover_moveit demo.launch.py
```

More info can be found in the [MoveIt2 docs](https://moveit.picknik.ai/main/index.html)

> [!WARNING]
>
> As of **October 2025**, MoveIt2's setup assistant has a fatal issue caused by a version incompatibility with Rviz2. The current workaround is to downgrade to an older version of Rviz2. The GitHub issue is found [here](https://github.com/moveit/moveit2/issues/3546). A script is provided to automate this process:
>
>```bash
>./tools/misc/moveit_rviz_workaround.sh
>```

### Perception

Camera streams (sources) and viewers (sinks) can be launched with the following commands:

```bash
ros2 launch uirover_perception gstream_source.launch.py
ros2 launch uirover_perception gstream_sink.launch.py
```

The realsense D435i can be demoed with this file


```bash
ros2 launch uirover_perception realsense.launch.py
```

A more complete SLAM demo using the realsense can be run with

```bash
ros2 launch uirover_perception stereo_slam.launch.py
```

> [!NOTE]
> To make full use of the D435i make sure that you are using a USB 3.0 compatible port and cable.

---

## Development Tools and Utilities

### VCAN

VCAN (Virtual Controller Area Network) is a linux kernel module which allows a [CAN bus](https://en.wikipedia.org/wiki/CAN_bus) network to be simulated entirely on-system. This allows firmware to be tested in conditions nearly identical to the real world. The following script can be used to enable it

```bash
./tools/misc/enable_vcan.sh
```

you can then check its working with

```bash
ip link
```

and you should see something like this

```text
9: vcan0: <NOARP,UP,LOWER_UP> mtu 72 qdisc noqueue state UNKNOWN mode DEFAULT group default qlen 1000
    link/can 
```

More info in the [linux netmodule docs](https://netmodule-linux.readthedocs.io/en/latest/howto/can.html)

### Network Stress Testing

To test nodes under lossy/delayed network conditions you may want to artificially induce packet loss, delay, and/or bandwidth restrictions on localhost. The following command will enable it:

```bash
sudo tc qdisc add dev lo root netem delay 200ms loss 20% 50%
```

To disable this you may run

```bash
sudo tc qdisc delete dev lo root netem
```

More information can be found in the [man page](https://man7.org/linux/man-pages/man8/tc-netem.8.html) (`$ man tc-netem`)

---

## CIRC Task Lists

- [2022](https://circ.cstag.ca/2022/tasks/)
- [2023](https://circ.cstag.ca/2023/tasks/)
- [2024](https://circ.cstag.ca/2024/tasks/)
- [2025](https://circ.cstag.ca/2025/tasks/)

## Contributers

- Ethan Holter [@ethanholter](https://github.com/ethanholter)
- Charlie Killian [@charlie-killian](https://github.com/charlie-killian)
