#! /usr/bin/env bash

set -eo pipefail

SCRIPT_DIR=$( cd "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd "$SCRIPT_DIR"

#make sure docker is installed
if ! command -v docker &> /dev/null; then
    echo "ERROR: Docker is not installed"
    exit 1
fi

docker run \
    -it \
    --privileged \
    --net host \
    -v "$SCRIPT_DIR"/../..:/rover \
    uirover:latest "$1"

echo "Rover is running"

