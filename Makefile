##
## Makefile for Makefile in /home/jobertomeu/Work/bomberman
## 
## Made by Joris Bertomeu
## Login   <bertom_j@epitech.net>
## 
## Started on  Sat Apr 12 20:15:17 2014 Joris Bertomeu
## Last update Wed May 20 20:05:38 2015 mari_f
##

CXX		=	clang++ -Iincludes

CXXFLAGS	+=	-W -Wextra -Wall -ansi -pedantic -O3 -I./LibBomberman_linux_x64/includes/

RM		=	rm -f

SRC		=	src/main.cpp				\
			src/GameEngine.cpp			\
			src/GraphicManager.cpp			\
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
		$(CC) -o $(NOM) $(OBJ) -L./LibBomberman_linux_x64/libs/ -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread -lstdc++ -lm
		@echo -e "\n > COMPILATION DES .C BOMBERMAN TERMINEE"

clean:
		@echo -e "\t->>> SUPPRESSION DES .o <<<-"
		$(RM) $(OBJ)
		$(RM) $(OBJ_LOADING)

fclean:		clean
		$(RM) $(NOM)

re:		fclean all

.PHONY:		all clean fclean re
