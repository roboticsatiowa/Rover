#!/bin/bash

if ! [ -d ${HOME}/Downloads ]; then
    mkdir ${HOME}/Downloads
fi

cd ${HOME}/Downloads/
wget https://github.com/PointCloudLibrary/pcl/releases/download/pcl-1.14.0/source.tar.gz
tar xvf source.tar.gz
cd pcl && mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j2
sudo make -j2 install
