<p align="center">
  <a href="" rel="noopener">
 <img width=600px src="images/logo.jpg" alt="Project logo"></a>
</p>

<h3 align="center">Robotics at Iowa Mars Rover Challenge</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Issues](https://img.shields.io/github/issues/roboticsatiowa/Rover.svg)](https://github.com/roboticsatiowa/Rover/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/roboticsatiowa/Rover.svg)](https://github.com/roboticsatiowa/Rover/pulls)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE)

</div>

---

<p align="center"> 
    This repository contains the code for our rover's onboard Nvidia Jetson Xavier.
    <br> 
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Deployment](#deployment)
- [Usage](#usage)
- [Built Using](#built_using)
- [TODO](../TODO.md)
- [Contributing](../CONTRIBUTING.md)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## About <a name = "about"></a>

Our rover uses 6 wheeled rocker bogie suspension system along with a 5 DOF custom arm. The onboard computing is handled by an Nvidia Jetson Xavier coupled with a Teensy 4.1 microcontroller to assist with IO. The rover is equipped with an Intel Realsense depth camera, 3 Cameras, and GPS.

## Getting Started <a name = "getting_started"></a>

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. 

### Prerequisites

- [ ] ROS2 Humble installed and sourced (Instructions [here](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html))
- [ ] x86 Ubuntu LTS 20.04

### Dependencies
- [ ] ```sudo apt install python3-colcon-common-extensions```
- [ ] ```sudo apt install tmux```

### Installing

Clone the repository into your workspace.
```bash
git clone https://github.com/roboticsatiowa/Rover.git
cd Rover
```

Check for missing dependencies and install them using rosdep.
```bash
rosdep install --from-paths src --ignore-src -r -y
```

Build and source the workspace.
```bash
colcon build
source install/setup.bash
```

### Running the code

Always make sure the workspace is sourced before running the code.
```bash
source install/setup.bash 
```

There are several launch files for various subsystems. To run the entire system, use the following command.
```bash
ros2 launch uiowa_rover rover.launch.py
```

The system can also be run remotely using ssh. This is done via the ```remote_launch.sh``` 
This script should not need to be run directly.

## Roadmap

### Completed
- [x] Basic ROS2 Setup
- [x] Camera Streaming
- [x] Visual SLAM with Intel Realsense

### In progress
- [ ] GPS
- [ ] Manual Control
- [ ] Full PID control

### Future Plans
- [ ] RTK GPS
- [ ] Autonomous Waypoint Navigation
- [ ] Inverse Kinematics
- [ ] Preset subroutines
  - [ ] "Push-up mode"
  - [ ] Race mode
  - [ ] Button targeting