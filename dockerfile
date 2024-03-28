FROM osrf/ros:humble-desktop

# make robotics user
RUN useradd -ms /bin/bash robotics; \
    usermod -aG sudo robotics; \
    echo "robotics ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

USER robotics
WORKDIR /home/robotics
