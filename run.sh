#!/bin/sh
## run.sh for  in /home/mediav_j/mabm/bomberman
## 
## Made by Jérémy Mediavilla
## Login   <mediav_j@epitech.net>
## 
## Started on  Wed Jun  3 11:50:58 2015 Jérémy Mediavilla
## Last update Wed Jun  3 11:51:00 2015 Jérémy Mediavilla
##
#!/bin/bash

export LD_LIBRARY_PATH=`pwd`/LibBomberman_linux_x64/libs
file=$(pwd)"/bomberman"
if [ -f "$file" ]
then
    $(pwd)/bomberman "$@"
else
    echo "Executable '$file' not found, I will try to recompile it .."; make -C re; $(pwd)"/run.sh"
fi
