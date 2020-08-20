#!/bin/bash
for file in `ls *cpp`; do
    echo "${file}"
    ./compiler.sh "${file%\.cpp}"
done

