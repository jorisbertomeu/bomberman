##
## Makefile for  in /home/mediav_j/mabm/bomberman
## 
## Made by Jérémy Mediavilla
## Login   <mediav_j@epitech.net>
## 
## Started on  Wed Jun  3 11:50:33 2015 Jérémy Mediavilla
## Last update Fri Jun  5 14:42:41 2015 Valérian Polizzi
##

CXX		=	g++

CXXFLAGS	+=	-W -Wextra -Wall -I./LibBomberman_linux_x64/includes/ -I./libxml2/include/ -Iincludes -O3

RM		=	rm -f

SRC		=	src/main.cpp				\
			src/GameEngine.cpp			\
			src/GraphicManager.cpp			\
			src/GraphicContext.cpp			\
			src/RenderManager.cpp			\
			src/SoundManager.cpp			\
			src/TextureManager.cpp			\
			src/ModelManager.cpp			\
			src/TimeManager.cpp			\
			src/GameContext.cpp			\
			src/SceneManager.cpp			\
			src/CameraManager.cpp			\
			src/InputManager.cpp			\
			src/SceneFactory.cpp			\
			src/AEntity.cpp				\
			src/ASolid.cpp				\
			src/PhysicSolid.cpp			\
			src/HitBox.cpp				\
			src/Bomberman.cpp			\
			src/Bomb.cpp				\
			src/Floor.cpp				\
			src/WoodWall.cpp			\
			src/BrickWall.cpp			\
			src/ParserXML.cpp			\
			src/Scene.cpp				\
			src/SceneParser.cpp			\
			src/GameEvent.cpp			\
			src/CommonEvent.cpp			\
			src/GameMenu.cpp			\
			src/GameButton.cpp			\
			src/Bot.cpp				\

OBJ		=	$(SRC:.cpp=.o)

NOM		=	bomberman

all:		$(NOM)

$(NOM):		$(OBJ)
		@echo -e "\n > COMPILATION DES .C BOMBERMAN EN COURS\n"
		$(CXX) -o $(NOM) $(OBJ) -L./LibBomberman_linux_x64/libs/ -lgdl_gl -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -lstdc++ -lm -ldl -lGL -L./libxml2/.libs/ -lxml2
		@echo -e "\n > COMPILATION DES .C BOMBERMAN TERMINEE"

clean:
		@echo -e "\t->>> SUPPRESSION DES .o <<<-"
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NOM)

re:		fclean all

.PHONY:		all clean fclean re
