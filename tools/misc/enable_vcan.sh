#!/usr/bin/env bash

# this script enables a virtual CAN interface (vcan0) on the system to be
# used for testing CAN bus applications without physical hardware. You can
# view outgoing CAN messages using `candump vcan0` from the can-utils package.

sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0