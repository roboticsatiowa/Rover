#/bin/bash

cd ./docker
for folder in $(ls -d *); do
    echo "Building $folder"
    cd $folder
    sudo docker build -t ${folder} .
    cd ..
done