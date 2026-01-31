#!/bin/bash

set -e

cd $(dirname $0)

C_FILES="\
src/main.c \
src/serializer.c \
"

mkdir -p build

compile() {
    gcc $C_FILES -o build/installer -Wall -Werror
}

time compile

