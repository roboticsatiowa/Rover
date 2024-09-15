#! /usr/bin/env bash

set -eo pipefail

SCRIPT_DIR=$( cd "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd "$SCRIPT_DIR"

#make sure docker is installed
if ! command -v docker &> /dev/null; then
    echo "ERROR: Docker is not installed"
    exit 1
fi

docker build . -f docker/build.Dockerfile -t build-base:latest

docker compose -f docker/compose.yml build
echo "Rover built successfully"
# echo 
# echo "Pushing Rover files..."
# docker compose -f docker/compose.yml push --quiet || echo "Error: Push failed"
# echo "Rover pushed successfully"