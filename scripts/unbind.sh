#!/bin/bash

export RTE_SDK=`readlink -f $(dirname ${BASH_SOURCE[0]})/../../DPDK`

DEVS="5e:00.0 5e:00.1"

sudo $RTE_SDK/tools/pci_unbind.py --bind=ixgbe $DEVS
