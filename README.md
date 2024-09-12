<p align="center">
  <a href="" rel="noopener">
 <img src="https://github.com/roboticsatiowa/Documents-and-Resources/raw/main/Media/Banner.png?raw=true" alt="Project logo"></a>
</p>

<h3 align="center">Robotics at Iowa Mars Rover Challenge</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Issues](https://img.shields.io/github/issues/roboticsatiowa/Rover.svg)](https://github.com/roboticsatiowa/Rover/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/roboticsatiowa/Rover.svg)](https://github.com/roboticsatiowa/Rover/pulls)
[![License](https://img.shields.io/badge/license-GPL-blue.svg)](/LICENSE)

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
- [ ] Ubuntu LTS 22.04

### Installing

Clone the repository and run the install script.
```bash
git clone https://github.com/roboticsatiowa/Rover.git
chmod u+x ./Rover/install.sh
./Rover/install.sh
```
### Running the code

There are several launch files for various subsystems. To run the entire system, use the following command.
```bash
ros2 launch rover_launch launch_all.launch.py
```
[ROS Isaac Installation](https://nvidia-isaac-ros.github.io/getting_started/isaac_ros_buildfarm_cdn.html)

`docker run -it ros2-humble-isaac`

The system can also be run remotely using ssh. This is done via the ```remote_launch.sh``` 
This script should not need to be run directly.

## Roadmap

### Completed
- [x] Basic ROS2 Setup
- [x] Camera Streaming
- [x] GPS
- [x] Manual Control

### In progress
- [ ] Visual SLAM with Intel Realsense
- [ ] Full PID control
- [ ] RTK GPS

### Future Plans
- [ ] Autonomous Waypoint Navigation
- [ ] Inverse Kinematics
- [ ] Preset subroutines
  - [ ] "Push-up mode"
  - [ ] Race mode
  - [ ] Button targeting
