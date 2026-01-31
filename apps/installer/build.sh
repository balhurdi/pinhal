#!/bin/bash

set -e

cd $(dirname $0)

mkdir -p build

gcc src/main.c -o build/installer