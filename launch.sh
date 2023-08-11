#!/bin/bash

python3 run_video.py 192.168.1.13 55555 0 &
python3 run_video.py 192.168.1.13 55556 2 &
python3 run_video.py 192.168.1.13 55558 3 &

python3 run.py 192.168.1.13 55557 &