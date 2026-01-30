#!/bin/bash

set -e

cd "$(dirname "$0")"

aports_clone_and_sync() {
    git submodule update --init --recursive 
}

build_image() {
    mkdir -p iso
    docker build -t pinhal-builder .
    # docker cp $(docker create pinhal-builder):/iso 

}

aports_clone_and_sync
build_image