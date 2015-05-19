#!/bin/bash

export LD_LIBRARY_PATH=`pwd`/LibBomberman_linux_x64/libs
file=$(pwd)"/bomberman"
if [ -f "$file" ]
then
    ./bomberman
else
    echo "Executable '$file' not found, I will try to recompile it .."; make re; ./run.sh
fi