#! /usr/bin/env bash

set -eo pipefail

SCRIPT_DIR=$( cd "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd "$SCRIPT_DIR"

#make sure docker is installed
if ! command -v docker &> /dev/null; then
    echo "ERROR: Docker is not installed"
    exit 1
fi

# check if built already
if ! docker images | grep -q "build-base"; then
    echo "ERROR: Rover has not been built yet"
    exit 1
fi

docker compose -f docker/compose.yml up

echo "Rover is running"