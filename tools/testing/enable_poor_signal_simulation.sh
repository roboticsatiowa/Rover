#!/usr/bin/env bash

sudo tc qdisc add dev lo root netem delay 200ms loss 20% 50%