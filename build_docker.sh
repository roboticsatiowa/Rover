#/usr/bin/env bash
set -euo pipefail

cd ./docker
for folder in $(ls -d *); do
    echo "Building $folder"
    cd $folder
    sudo docker build -t ${folder} .
    cd ..
done


# Run docker
# docker run -it --device=/dev/ttyUSB0 unitree_lidar 