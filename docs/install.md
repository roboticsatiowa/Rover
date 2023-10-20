# Installation Instructions

- We installed the nvidia\_ros\_common dev environment setup with the [documentation here](https://github.com/NVIDIA-ISAAC-ROS/isaac_ros_common/blob/main/docs/dev-env-setup_jetson.md). We copied the directions, however put the data-root for nvidia docker under ~/docker/nvidia. Not sure if this part is necessary as the documentation is limited.

- A prebuild docker binary has been created and can be built locally after cloning nvidia\_ros\_common going to the docker folder and then moving Dockerfile.aarch64.ros2_humble to Dockerfile and then running `docker build . -t 'isaac_ros2_humble'` This should build almost instantaneously as its pre-compiled.

- Realsense support can be added to this baseimage by setting BASE_IMAGE in Dockerfile.realsense and compiling using the same docker build command with tag 'issac\_ros2\_humble\_realsense' although the build can take 1+ hour when built on the jetson.

- A script directory was created in the project root directory to run the docker container shell and add the ros2-docker script to the bash path. The default path for the git directory with these scripts is set to `~/git/Rover/scripts/ros2-humble-isaac` but can be changed in the `install.sh` and `ros2-docker` scripts to whatever directory

- Run a docker shell for ros2-humble-isaac using the command `ros2-docker /bin/bash` or run a specific ros2 program using `ros2-docker ros2 [cmd]`
- Run the demo talker/listener app using `ros2docker ros2 run demo_nodes_cpp listener & ros2-docker ros2 run demo_nodes_cpp talker`
