# syntax=docker/dockerfile:1

FROM ros:humble-ros-core-jammy

# use bash instead of sh. allows us to use 'source' command.
SHELL ["/bin/bash", "-c"]

# setup robotics user
RUN useradd -ms /bin/bash robotics
RUN usermod -aG sudo robotics
RUN chown -R robotics:robotics /home/robotics/
RUN usermod -aG dialout robotics
RUN echo "robotics ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers
RUN echo "source /opt/ros/humble/setup.bash" >> /home/robotics/.bashrc
RUN apt update -y && apt upgrade -y
RUN apt-get install sudo -y
RUN apt install git -y

USER robotics

USER robotics
WORKDIR /home/robotics/Code
COPY . .
RUN . yes | install.sh