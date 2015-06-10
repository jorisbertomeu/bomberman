##
## Makefile for $ in /home/mediav_j/mabm/bomberman
## 
## Made by Jérémy Mediavilla
## Login   <mediav_j@epitech.net>
## 
## Started on  Tue Jun  9 19:35:05 2015 Jérémy Mediavilla
## Last update Tue Jun  9 21:33:37 2015 mari_f
##

CXX		=	g++

CXXFLAGS	+=	-W -Wextra -Wall -I./LibBomberman_linux_x64/includes/ -I./libxml2/include/ -Iincludes -O3

RM		=	rm -f

SRC		=	src/main.cpp				\
			src/GameEngine.cpp			\
			src/GraphicContext.cpp			\
			src/GameContext.cpp			\
			src/Rendering/GraphicManager.cpp	\
			src/Rendering/RenderManager.cpp		\
			src/Rendering/SoundManager.cpp		\
			src/Rendering/TextureManager.cpp	\
			src/Rendering/ModelManager.cpp		\
			src/Rendering/TimeManager.cpp		\
			src/Rendering/CameraManager.cpp		\
			src/Scenes/SceneManager.cpp		\
			src/Scenes/SceneFactory.cpp		\
			src/Scenes/ParserXML.cpp		\
			src/Scenes/Scene.cpp			\
			src/Scenes/SceneParser.cpp		\
			src/Scenes/GameMenu.cpp			\
			src/Scenes/MainMenu.cpp			\
			src/Physics/ASolid.cpp			\
			src/Physics/PhysicSolid.cpp		\
			src/Physics/HitBox.cpp			\
			src/Entities/AEntity.cpp		\
			src/Entities/Bomberman.cpp		\
			src/Entities/Bomb.cpp			\
			src/Entities/Floor.cpp			\
			src/Entities/WoodWall.cpp		\
			src/Entities/BrickWall.cpp		\
			src/Events/GameEvent.cpp		\
			src/Events/CommonEvent.cpp		\
			src/Events/InputManager.cpp		\
			src/Bot.cpp				\
			src/Pavement.cpp			\

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
