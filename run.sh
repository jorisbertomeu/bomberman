#!/bin/sh

export LD_LIBRARY_PATH="`pwd`/LibBomberman_linux_x64/libs;`pwd`/fmod"
file=$(pwd)"/bomberman"
if [ -f "$file" ]
then
     $(pwd)/bomberman "$@"
else
    echo "Executable '$file' not found, I will try to recompile it .."; make -C .; $(pwd)"/run.sh"
fi
