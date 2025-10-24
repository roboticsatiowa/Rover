#!/usr/bin/env bash

# this script enables a virtual CAN interface (vcan0) on the system to be
# used for testing CAN bus applications without physical hardware. You can
# view outgoing CAN messages using `candump vcan0` from the can-utils package.

sudo modprobe vcan
echo "vcan kernel module enabled"

if ! ip link | grep -q vcan; then
    sudo ip link add dev vcan0 type vcan
    echo "Created vcan0 network device"
else
    echo "vcan0 already exists"
fi

sudo ip link set up vcan0
echo "vcan0 enabled"
echo
echo "Virtual CANbus network device has been enabled. Run 'ip link show vcan0' to check"