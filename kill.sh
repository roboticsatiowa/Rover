#!/bin/bash

# Find and kill instances of run_video.py and run.py

# Search and kill run_video.py instances
pids=$(pgrep -f run_video.py)
if [ -n "$pids" ]; then
    echo "Killing run_video.py instances..."
    kill $pids
    echo "Killed run_video.py instances."
else
    echo "No run_video.py instances found."
fi

# Search and kill run.py instances
pids=$(pgrep -f run.py)
if [ -n "$pids" ]; then
    echo "Killing run.py instances..."
    kill $pids
    echo "Killed run.py instances."
else
    echo "No run.py instances found."
fi