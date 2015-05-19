##
## Makefile for Makefile in /home/jobertomeu/Work/bomberman
## 
## Made by Joris Bertomeu
## Login   <bertom_j@epitech.net>
## 
## Started on  Sat Apr 12 20:15:17 2014 Joris Bertomeu
## Last update Tue May 19 12:05:40 2015 Joris Bertomeu
##

CXX		=	clang++ -Iincludes

CXXFLAGS	+=	-W -Wextra -Wall -ansi -pedantic -O3 -I./LibBomberman_linux_x64/includes/

RM		=	rm -f

SRC		=	src/main.cpp				\
			src/core/GameEngine.cpp			\
			src/GraphicManager.cpp			\
			src/RenderManager.cpp			\
			src/SoundManager.cpp			\
			src/TextureManager.cpp			\

OBJ		=	$(SRC:.cpp=.o)

NOM		=	bomberman

all:		$(NOM)

$(NOM):		$(OBJ)
		@echo -e "\n > COMPILATION DES .C BOMBERMAN EN COURS\n"
		$(CC) -o $(NOM) $(OBJ) -L./LibBomberman_linux_x64/libs/ -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread
		@echo -e "\n > COMPILATION DES .C BOMBERMAN TERMINEE"

clean:
		@echo -e "\t->>> SUPPRESSION DES .o <<<-"
		$(RM) $(OBJ)
		$(RM) $(OBJ_LOADING)

fclean:		clean
		$(RM) $(NOM)

re:		fclean all

.PHONY:		all clean fclean re
