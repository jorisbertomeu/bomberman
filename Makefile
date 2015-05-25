##
## Makefile for Makefile in /home/jobertomeu/Work/bomberman
## 
## Made by Joris Bertomeu
## Login   <bertom_j@epitech.net>
## 
## Started on  Sat Apr 12 20:15:17 2014 Joris Bertomeu
## Last update Mon May 25 17:26:01 2015 Geoffrey Merran
##

CC		=	g++

CXXFLAGS	+=	-W -Wextra -Wall -ansi -pedantic -O3 -I./LibBomberman_linux_x64/includes/ -Iincludes

RM		=	rm -f

SRC		=	src/main.cpp				\
			src/GameEngine.cpp			\
			src/GraphicManager.cpp			\
			src/GraphicContext.cpp			\
			src/RenderManager.cpp			\
			src/SoundManager.cpp			\
			src/TextureManager.cpp			\
			src/GameContext.cpp			\
			src/SceneManager.cpp			\
			src/CameraManager.cpp			\
			src/InputManager.cpp			\
			src/SceneFactory.cpp			\
			src/AScene.cpp				\

OBJ		=	$(SRC:.cpp=.o)

NOM		=	bomberman

all:		$(NOM)

$(NOM):		$(OBJ)
		@echo -e "\n > COMPILATION DES .C BOMBERMAN EN COURS\n"
		$(CC) -o $(NOM) $(OBJ) -L./LibBomberman_linux_x64/libs/ -lgdl_gl -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -lstdc++ -lm -ldl -lGL
		@echo -e "\n > COMPILATION DES .C BOMBERMAN TERMINEE"

clean:
		@echo -e "\t->>> SUPPRESSION DES .o <<<-"
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NOM)

re:		fclean all

.PHONY:		all clean fclean re
