# syntax=docker/dockerfile:1

FROM ros:humble-ros-core-jammy

# use bash instead of sh. allows us to use 'source' command.
SHELL ["/bin/bash", "-c"]

# setup robotics user
RUN useradd -ms /bin/bash robotics -p "$(openssl passwd -1 rover123)"
RUN usermod -aG sudo robotics
RUN chown -R robotics:robotics /home/robotics/
RUN usermod -aG dialout robotics
RUN echo "robotics ALL=(ALL:ALL) NOPASSWD: ALL" | sudo tee /etc/sudoers.d/robotics
RUN apt update -y && apt upgrade -y
RUN yes | apt-get install sudo
RUN apt install git -y

USER robotics

RUN echo "source /opt/ros/humble/setup.bash" >> "${HOME}/.bashrc"
RUN echo "export ROS_DOMAIN_ID=69" >> "${HOME}/.bashrc"
RUN echo "source ${HOME}/Rover/install/setup.bash" >> "${HOME}/.bashrc"

WORKDIR /home/robotics/Rover
COPY . .
RUN yes | source install.sh