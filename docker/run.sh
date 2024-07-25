#!/usr/bin/env bash
set -eo pipefail

SCRIPT_DIR=$( cd "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd "${SCRIPT_DIR}"/..

# run container
mkdir -p bag/
docker pull ethanholter/uirover:latest -q
docker compose -f docker/compose.yml run uirover-interactive
