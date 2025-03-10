<h1 align="center"><img src="https://github.com/roboticsatiowa/Documents-and-Resources/raw/main/Media/Banner.png?raw=true"/></h1>

<h1 align="center">Mars Rover Challenge</h1>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Issues](https://img.shields.io/github/issues/roboticsatiowa/Rover.svg)](https://github.com/roboticsatiowa/Rover/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/roboticsatiowa/Rover.svg)](https://github.com/roboticsatiowa/Rover/pulls)
[![License](https://img.shields.io/badge/license-GPLv3.0-blue.svg)](/LICENSE)

</div>

- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Roadmap](#roadmap)
- [Authors](#authors)

## About <a name = "about"></a>

This is a ROS2 based project for the University of Iowa Robotics Club's Mars Rover. It is primarily designed around remote operation with future plans for partial or full autonomy. The rover is equipped with a 6 wheeled rocker bogie suspension system, a 5 DOF custom arm, and a variety of sensors. The onboard computing is handled by an Nvidia Jetson Orin coupled with a Teensy 4.1 microcontroller to assist with IO. The rover is equipped with an Intel Realsense depth camera, 3 Cameras, GPS, and a suite of miscellanious sensors for improved situational awareness.

## Getting Started <a name = "getting_started"></a>

### System Requirements

There are a variety of ways to run this project. The easiest is to use the ROS2 Jazzy running natively on Ubuntu 24.04 LTS. The included install scripts located in the tools/ directory can help with installation of ROS2 and this projects dependencies.

<b>IMPORTANT: This project is still in active development and has not yet been tested on the target environment. These platforms are for development. The Jetson hardware will likely require specialized builds of ROS2 and other dependencies.</b> [ROS Isaac Installation](https://nvidia-isaac-ros.github.io/getting_started/isaac_ros_buildfarm_cdn.html)

- ROS 2 Jazzy
  - [ ] Ubuntu 24.04 LTS
  - [ ] ROS2 Jazzy
<br>

- ROS 2 Humble (may require minimal source changes)
  - [ ] Ubuntu 22.04 LTS
  - [ ] ROS2 Humble
<br>

- Docker install
  - [ ] Any Unix based OS
  - [ ] Docker
  - [ ] Systemd based init system recommended (for udev rules)

### Installation

This guide assumes you are using ROS2 Jazzy on Ubuntu 24.04 LTS. If you are using a different version of ROS2, you may consult the ROS2 documentation for installation instructions [here](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html)

<br>
Clone the repository to your workspace.

```bash
git clone https://github.com/roboticsatiowa/Rover.git
cd Rover
```

<br>
Install ROS and project dependencies. (Recommended even if you already have ROS2 installed)

```bash
./tools/ros/install_ros.sh
./tools/ros/install_dependencies.sh
```

### Building


A convenience script is provided to build the project

```bash
./tools/ros/build.sh
source install/setup.bash
```
<br>
It is recommended to occasionally clean out the workspace. This will remove any generated files which can sometimes cause issues.

```bash
./tools/ros/clean.sh
```


## Usage <a name = "usage"></a>

This will likely change as the project matures. The current launch file will start the gazebo simulation with the rover model. There will also be multiple launch files for different configurations of the rover or for different testing environments.

```bash
ros2 launch uirover_bringup simulator.launch.py
```

## Roadmap

- [x] Gazebo simulation boilerplate
- [x] Simplified rover 3D model
- [ ] Full rover 3D model with meshes
- [x] Video capture and streaming
- [x] Video compression
- [ ] Relative pose estimation
- [ ] Object classification
- [x] Basic aruco marker detection
- [x] ROS2 Control boilerplate
- [ ] Full ROS2 Control hardware support
- [ ] Custom wheel controller for differential swerve drive
- [ ] MoveIt! boilerplate
- [ ] Simplified arm 3D model
- [ ] Full arm 3D model with meshes
- [ ] Arm IK solver
- [ ] Preset arm poses (grab, drop, tool change, etc.)
- [ ] Zenoh middleware
- [ ] Nav2 boilerplate
- [ ] Nav2 basic environment mapping
- [ ] Nav2 basic path planning
- [ ] Nav2 obstacle avoidance

## CIRC Specific Capabilities

<https://circ.cstag.ca/2025/tasks/>

## Required Capabilities

- [ ] record distance between two gps waypoints
- [x] identify aruco markers of 4x4_100
- [ ] take photos BEFORE disturbing scene (need cam with better res or zoom)
- [ ] take photos and automatically upload to base station usb drive
- [ ] communicate with a gieger counter via serial interface
- [ ] night time operation (flood lights, spot lights, low light camera, etc.)
- [ ] 940 nm IR camera
- [ ] must fit in a "storm shelter" dimensions provided by april 2025

#### Bonus Capabilities

- [ ] vision based text identification and translation (no bonus points - to save time)
- [x] Aruco identification running in background and automatically display on screen
- [ ] navigate to a gps waypoint autonomously
- [ ] autonomously follow light points of varying colors

## Contributers <a name = "authors"></a>

- Ethan Holter [@ethanholter](https://github.com/ethanholter)
- Charlie Killian [@charlie-killian](https://github.com/charlie-killian)
