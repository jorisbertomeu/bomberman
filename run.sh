## run.sh for  in /home/jobertomeu/Work/bomberman
## 
## Made by Joris Bertomeu
## Login   <jobertomeu@epitech.net>
## 
## Started on  Tue May 19 09:56:14 2015 Joris Bertomeu
## Last update Tue May 26 17:27:12 2015 Geoffrey Merran
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
