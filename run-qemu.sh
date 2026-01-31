#!/bin/bash

set -e

cd "$(dirname "$0")"
mkdir -p vm-drives

DRIVE_SIZE=10G
MEM_VALUE=512
ISO_PATH=iso/alpine-pinhal-3.23-x86_64.iso
DRIVE_PATH=vm-drives/alpine.qcow2

# Create disk
qemu-img create -f qcow2 $DRIVE_PATH $DRIVE_SIZE
# Run vm
qemu-system-x86_64 -m 512 -nic user -boot once=d -cdrom $ISO_PATH -drive file=$DRIVE_PATH -display sdl -enable-kvm
