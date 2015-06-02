##
## Makefile for Makefile in /home/jobertomeu/Work/bomberman
## 
## Made by Joris Bertomeu
## Login   <bertom_j@epitech.net>
## 
## Started on  Sat Apr 12 20:15:17 2014 Joris Bertomeu
## Last update Tue Jun  2 12:31:02 2015 Nicolas Adès
##

CXX		=	g++

CXXFLAGS	+=	-W -Werror -Wextra -Wall -I./LibBomberman_linux_x64/includes/ -I/usr/include/libxml2/ -Iincludes

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
			src/AEntity.cpp				\
			src/ASolid.cpp				\
			src/PhysicSolid.cpp			\
			src/HitBox.cpp				\
			src/Bomberman.cpp			\
			src/Bomb.cpp				\
			src/WoodWall.cpp			\
			src/BrickWall.cpp			\
			src/ParserXML.cpp			\
			src/Scene.cpp				\
			src/SceneParser.cpp			\

OBJ		=	$(SRC:.cpp=.o)

NOM		=	bomberman

all:		$(NOM)

$(NOM):		$(OBJ)
		@echo -e "\n > COMPILATION DES .C BOMBERMAN EN COURS\n"
		$(CXX) -o $(NOM) $(OBJ) -L./LibBomberman_linux_x64/libs/ -lgdl_gl -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -lstdc++ -lm -ldl -lGL `xml2-config --cflags` `xml2-config --libs`
		@echo -e "\n > COMPILATION DES .C BOMBERMAN TERMINEE"

clean:
		@echo -e "\t->>> SUPPRESSION DES .o <<<-"
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NOM)

re:		fclean all

.PHONY:		all clean fclean re
