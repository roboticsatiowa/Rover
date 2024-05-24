#!/usr/bin/env bash
set -eo pipefail

SCRIPT_DIR=$( cd "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd "${SCRIPT_DIR}"/..

# TODO validate that the image has been built
if ( ! docker image inspect ethanholter/uirover:latest &> /dev/null); then
    echo "Image rover:latest not found. Please build the image first."
    exit 1
fi

# run container
mkdir -p bag/
docker compose -f docker/compose.yml run uirover-interactive
