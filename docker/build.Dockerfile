# syntax=docker/dockerfile:1

FROM ros:humble-ros-core-jammy AS build-base

RUN apt-get update && apt-get install -y \
    ros-dev-tools \
    && rm -rf /var/lib/apt/lists/*



# ========================================
# this is the old dockerfile for reference
# ========================================



# # syntax=docker/dockerfile:1

# # ---------------------
# # Build image
# # ---------------------

#     FROM ros:humble-ros-core-jammy as build_ublox
#     # use bash instead of sh. allows us to use 'source' command.
#     SHELL ["/bin/bash", "-c"]
    
#     # install dependencies. delete cache after, and dont install recommended packages to keep image small.
    
#     RUN apt-get update \    
#         && apt-get install -q -y --no-install-recommends \
#         python3-colcon-common-extensions \
#         make \
#         build-essential \
#         ros-humble-ament-cmake \
#         libasio-dev \
#         ros-humble-diagnostic-updater \
#         ros-humble-tf2 \
#         git \
#         && rm -rf /var/lib/apt/lists/*
    
#     # Create robotics user and setup user environment
#     RUN groupadd robotics \
#         && useradd -rm -d /home/robotics -s /bin/bash -g robotics robotics \
#         && usermod -aG dialout robotics \
#         && usermod -aG video robotics \
#         && touch "${HOME}/.bashrc" \
#         && chown -R robotics:robotics "${HOME}/.bashrc" \
#         && echo "source /opt/ros/humble/setup.bash" >> "${HOME}/.bashrc" \
#         && echo "source ${HOME}/Rover/install/setup.bash" >> "${HOME}/.bashrc"
    
#     # build ublox first so docker can cache it seperately
#     WORKDIR /home/robotics/Rover/src
#     RUN git clone https://github.com/gokulp01/ros2-ublox-zedf9p
#     ADD ./zed_f9p.yaml /home/robotics/Rover/src/ros2-ublox-zedf9p/ublox_gps/config/zed_f9p.yaml
#     RUN chown -R robotics:robotics /home/robotics
#     USER robotics
#     WORKDIR /home/robotics/Rover
#     RUN source /opt/ros/humble/setup.bash && colcon build \
#         && rm -rf /home/robotics/Rover/src
    
#     # using ros humble core 
#     # ARM64 (raspberry pi 4) compatible:
#     FROM ros:humble-ros-core-jammy@sha256:ce60463faaaa1f41a2c28fe852d407f4e538c7cad815b73f030a5e841d73103d as build
    
#     # docker run --rm --privileged multiarch/qemu-user-static --reset -p yes -c yes
    
#     # use bash instead of sh. allows us to use 'source' command.
#     SHELL ["/bin/bash", "-c"]
    
#     # install dependencies. delete cache after, and dont install recommended packages to keep image small.
    
#     RUN apt-get update \    
#         && apt-get install -q -y --no-install-recommends \
#         python3-colcon-common-extensions \
#         make \
#         build-essential \
#         ros-humble-ament-cmake \
#         libasio-dev \
#         ros-humble-diagnostic-updater \
#         ros-humble-tf2 \
#         && rm -rf /var/lib/apt/lists/*
    
#     # Create robotics user and setup user environment
#     RUN groupadd robotics \
#         && useradd -rm -d /home/robotics -s /bin/bash -g robotics robotics \
#         && usermod -aG dialout robotics \
#         && usermod -aG video robotics \
#         && touch "${HOME}/.bashrc" \
#         && chown -R robotics:robotics "${HOME}/.bashrc" \
#         && echo "source /opt/ros/humble/setup.bash" >> "${HOME}/.bashrc" \
#         && echo "source ${HOME}/Rover/install/setup.bash" >> "${HOME}/.bashrc"
    
#     # build ublox first so docker can cache it seperately
#     COPY --from=build_ublox /home/robotics/Rover /home/robotics/Rover
#     ADD ./src /home/robotics/Rover/src
#     ADD ./docker/entrypoint.sh /home/robotics/Rover/entrypoint
#     RUN chmod +x /home/robotics/Rover/entrypoint
    
#     RUN chown -R robotics:robotics /home/robotics
#     USER robotics
#     WORKDIR /home/robotics/Rover
    
#     # build the workspace
#     RUN source /opt/ros/humble/setup.bash && colcon build --packages-skip-regex ublox* \
#         && rm -rf /home/robotics/Rover/src
    
#     # ---------------------
#     # Main image
#     # ---------------------
    
#     FROM ros:humble-ros-core-jammy@sha256:ce60463faaaa1f41a2c28fe852d407f4e538c7cad815b73f030a5e841d73103d as main
    
#     # use bash instead of sh. allows us to use 'source' command.
#     SHELL ["/bin/bash", "-c"]
    
#     # install dependencies. delete cache after, and dont install recommended packages to keep image small.
#     RUN apt-get update \
#         && apt-get install -q -y --no-install-recommends \
#         python3-venv \
#         python3-serial \
#         python3-pip \
#         ffmpeg \
#         libsm6 \
#         libxext6 \
#         ros-humble-cv-bridge \
#         ros-humble-rosbag2 \
#         && rm -rf /var/lib/apt/lists/*
    
#     RUN pip3 install --no-cache-dir opencv-python sympy
    
#     COPY --from=build /home/robotics/Rover /home/robotics/Rover
    
#     # Create robotics user and setup user environment
#     RUN groupadd robotics \
#         && useradd -rm -d /home/robotics -s /bin/bash -g robotics robotics \
#         && usermod -aG dialout robotics \
#         && usermod -aG video robotics \
#         && echo "source /opt/ros/humble/setup.bash" >> "${HOME}/.bashrc" \
#         && echo "source ${HOME}/Rover/install/setup.bash" >> "${HOME}/.bashrc"
    
#     RUN chown -R robotics:robotics /home/robotics
#     USER robotics
#     WORKDIR /home/robotics/Rover