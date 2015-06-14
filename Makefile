##
## Makefile for $ in /home/mediav_j/mabm/bomberman
## 
## Made by Jérémy Mediavilla
## Login   <mediav_j@epitech.net>
## 
## Started on  Tue Jun  9 19:35:05 2015 Jérémy Mediavilla
## Last update Sun Jun 14 07:51:24 2015 Geoffrey Merran
##

CXX		=	g++

CXXFLAGS	+=	-W -Wextra -Wall -I./LibBomberman_linux_x64/includes/ -I./libxml2/include/ -Iincludes -I./fmod/includes `pkg-config --cflags libcurl`

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
			src/Rendering/AnimationManager.cpp	\
			src/Rendering/Animation.cpp		\
			src/Scenes/SceneManager.cpp		\
			src/Scenes/ParserXML.cpp		\
			src/Scenes/Scene.cpp			\
			src/Scenes/SceneParser.cpp		\
			src/Scenes/EscapeMenu.cpp		\
			src/Scenes/MainMenu.cpp			\
			src/Scenes/NewGameMenu.cpp		\
			src/Scenes/MapSelector.cpp		\
			src/Scenes/Map.cpp			\
			src/Scenes/LoadingScene.cpp		\
			src/Physics/ASolid.cpp			\
			src/Physics/PhysicSolid.cpp		\
			src/Physics/HitBox.cpp			\
			src/Entities/AEntity.cpp		\
			src/Entities/Bomberman.cpp		\
			src/Entities/Bomb.cpp			\
			src/Entities/Floor.cpp			\
			src/Entities/WoodWall.cpp		\
			src/Entities/BrickWall.cpp		\
			src/Entities/GameButton.cpp		\
			src/Entities/Pavement.cpp		\
			src/Entities/Cloud.cpp			\
			src/Entities/MapPreviewer.cpp		\
			src/Entities/Balloon.cpp		\
			src/Events/GameEvent.cpp		\
			src/Events/CommonEvent.cpp		\
			src/Events/InputManager.cpp		\
			src/Events/MenuEvent.cpp		\
			src/Events/EscapeEvent.cpp		\
			src/Events/NewGameEvent.cpp		\
			src/Events/LoadingEvent.cpp		\
			src/Bot.cpp				\
			src/HttpRequest.cpp			\

OBJ		=	$(SRC:.cpp=.o)

NOM		=	bomberman

all:		$(NOM)

$(NOM):		$(OBJ)
		@echo -e "\n > COMPILATION DES .C BOMBERMAN EN COURS\n"
		$(CXX) -o $(NOM) $(OBJ) -L./LibBomberman_linux_x64/libs/ -lgdl_gl -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -lstdc++ -lm -ldl -lGL -L./libxml2/.libs/ -lxml2 -L./fmod/ -lfmod `pkg-config --libs libcurl`
		@echo -e "\n > COMPILATION DES .C BOMBERMAN TERMINEE"

clean:
		@echo -e "\t->>> SUPPRESSION DES .o <<<-"
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NOM)

re:		fclean all

.PHONY:		all clean fclean re
