#!/usr/bin/env bash

docker kill rover-container &> /dev/null
docker system prune -a -f --volumes