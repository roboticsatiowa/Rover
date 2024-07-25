#!/usr/bin/env bash
set -eo pipefail

SCRIPT_DIR=$( cd "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

#make sure docker is installed
if ! command -v docker &> /dev/null; then
    echo "ERROR: Docker is not installed"
    exit 1
fi

# switch to top level dir, build image for arm64, push to dockerhub
(cd "$SCRIPT_DIR/.." && docker buildx build . --platform=linux/arm64 --file=docker/dockerfile -t ethanholter/uirover:latest -t ethanholter/uirover:$(date +%s) --push)

echo "[$(date)] Build complete"