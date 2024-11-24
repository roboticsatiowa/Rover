#!/usr/bin/env bash
# Author: Ethan Holter
Author: Ethan Holter

echo "This script deletes all docker containers and images. Very
often if the raspberry pi is killed ungracefully while building, 
docker will begin to behave strangely because of its image caching. 
This script will fix that by providing a clean slate. It will also fix
most other docker-related issues but at the expense of losing all data.

This is NOT reversible. USE WITH CAUTION."
echo

read -p "Are you sure you want to delete all docker containers, images, and volumes? [y/N] " -n 1 -r
echo

if [[ ! $REPLY =~ ^[Yy]$ ]]
then
    echo "Exiting..."
    exit 1
fi

docker kill rover-container &> /dev/null
docker system prune -a -f --volumes

echo "Operation complete"