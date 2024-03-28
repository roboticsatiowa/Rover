# syntax=docker/dockerfile:1

FROM osrf/ros:humble-desktop

# use bash instead of sh. allows us to use 'source' command.
SHELL ["/bin/bash", "-c"] 

# setup robotics user
RUN useradd -ms /bin/bash robotics; \
    usermod -aG sudo robotics; \
    sudo chown -R robotics:robotics /home/robotics/; \
    sudo usermod -aG dialout robotics; \
    echo "robotics ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers; \
    echo "source /opt/ros/humble/setup.bash" >> /home/robotics/.bashrc
USER robotics

USER robotics
WORKDIR /home/robotics
