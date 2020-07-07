#!/bin/bash
if [ ! -e ${1}/lib.o ]; then
    echo "Compiling writer library"
    g++ -c -o ${1}/lib.o ${1}/music_lib.cpp
fi
