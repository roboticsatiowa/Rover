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

## Other Launch Files



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
