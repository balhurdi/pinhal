#!/bin/bash

set -e

cd $(dirname $0)

C_FILES="\
src/main.c \
src/serializer.c \
src/args.c
"

mkdir -p build

compile() {
    gcc $C_FILES -o build/installer -lncurses -Wall -Werror --debug
}

time compile

SYSTEM_DRIVE_LIST=$(lsblk -d -o name | grep -v NAME | paste -s -d, /dev/stdin)
