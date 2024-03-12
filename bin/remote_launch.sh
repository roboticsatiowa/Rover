#!/usr/bin/env bash
set -eo pipefail


if tmux has-session -t ros2
    then tmux kill-session -t ros2
fi

tmux new-session -d -s ros2
tmux send-keys -t ros2 "source ~/Rover/install/setup.sh && ros2 launch rover rover.launch.py" C-m