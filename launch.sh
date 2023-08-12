#!/bin/bash

python3 run.py 192.168.137.1 55559 &

python3 run_video.py 192.168.137.1 55555 0 &
python3 run_video.py 192.168.137.1 55556 2 &
python3 run_video.py 192.168.137.1 55558 4 &
