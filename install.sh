#/usr/bin/env bash
set -euo pipefail

# check if distro is ubuntu
if [ "$(lsb_release -is)" != "Ubuntu" ]; then
    echo "ERROR: Must be running Ubuntu to install this project"
    exit 1
fi

# Check Ubuntu version is 22.04
if [ "$(lsb_release -cs)" != "jammy" ]; then
    echo "WARNING: You are running: Ubuntu $(lsb_release -rs). This project is designed for Ubuntu 22.04"
    input "Proceed at your own risk. Do you want to continue? [y/N]" CONTINUE
    if [ "$CONTINUE" != "y" ]; then
        echo "Exiting..."
        exit 1
    fi
    exit 1
fi

# Install ROS2 Humble

# check if ros distro is already installed but not humble
if [ ! -z $ROS_DISTRO && $ROS_DISTRO != "humble"]; then
    echo "ERROR: Another ROS distro detected. Please uninstall before continuing"
    exit 1
fi

if [ -z $ROS_DISTRO ]; then
    input "No ROS distro detected. Do you want to install ROS2 Humble? [Y/n]" INSTALL
    if [ "$INSTALL":-"y" == "y" ]; then
        sudo apt update -y
        sudo apt upgrade -y
        sudo apt install locales -y
        sudo locale-gen en_US en_US.UTF-8 -y
        sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 -y
        sudo apt install software-properties-common -y
        sudo add-apt-repository universe -y
        sudo apt update -y
        sudo apt install curl -y
        sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
        echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list >/dev/null
        sudo apt update -y
        sudo apt upgrade -y
        sudo apt install ros-humble-desktop -y
        source /opt/ros/humble/setup.bash
    fi
fi

# add ROS2 Humble sources to bashrc
input "add ROS2 Humble sources to bashrc? (Recommended) [Y/n]" ADD_SOURCE
if [ "$ADD_SOURCE":-"y" == "y" ]; then
    grep -q "source /opt/ros/humble/setup.bash" ${HOME}/.bashrc || echo "source /opt/ros/humble/setup.bash" >>${HOME}/.bashrc
fi

# add Domain ID to bashrc
input "add Domain ID to bashrc? (Recommended) [Y/n]" ADD_DOMAIN
if [ "$ADD_DOMAIN":-"y" == "y" ]; then
    grep -q "export ROS_DOMAIN_ID=69" ${HOME}/.bashrc || echo "export ROS_DOMAIN_ID=69" >>${HOME}/.bashrc
fi

# Misc dependencies
sudo apt install python3-rosdep2 tmux python3-venv python3-colcon-common-extensions -y

rosdep update
rosdep install --from-paths src --ignore-src -r -y

# Additional information

echo "Installation complete."; echo; echo

echo "Next steps:"
echo "    - To build the workspace, run: colcon build"
echo "    - to source the workspace, run: source install/setup.bash"
echo "    - To launch a package from the workspace, run: ros2 launch <package_name> <launch_file>"
echo "    - To run a node from the workspace, run: ros2 run <package_name> <node_name>"


# End of file



