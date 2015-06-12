//
// MainMenu.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src/Scenes
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Mon Jun  8 09:29:53 2015 Valérian Polizzi
// Last update Fri Jun 12 23:00:32 2015 mari_f
//

#include	<MainMenu.hh>

MainMenu::MainMenu(CameraManager & cm) : Scene(&cm)
{
  this->_buttons.push_back(new GameButton(glm::vec3(0, 50, 0), std::string("assets/textures/play.tga")));
  this->_buttons.front()->setCurrent(true);
  this->_buttons.push_back(new GameButton(glm::vec3(0, -150, 0), std::string("assets/textures/load.tga")));
  this->_buttons.push_back(new GameButton(glm::vec3(0, -350, 0), std::string("assets/textures/quit.tga")));
  this->_eventHandler = new MenuEvent();
  for (std::list<GameButton*>::iterator it = this->_buttons.begin(); it != this->_buttons.end(); it++)
    {
      (*it)->setScale(glm::vec3(300, 100, 100));
      this->addEntity((*it));
    }
  this->_cursor = new GameButton(glm::vec3(-300, 50, 0), std::string("assets/textures/wall_texture.tga"));
  this->_cursor->setScale(glm::vec3(60, 60, 0));
  this->_cursor->setCurrent(false);
  this->addEntity(this->_cursor);
  Pavement*	background = new Pavement(glm::vec3(0, 0, 0), std::string("assets/textures/background.tga"));
  background->setScale(glm::vec3(2500, 1300, 0));
  this->addEntity(background);
}

MainMenu::~MainMenu()
{

}

void			MainMenu::initialize()
{
  this->_cm->moveTo(glm::vec3(0, 0, 1000), glm::vec3(0, 0, 0));
}

int			MainMenu::getListSize() const
{
  return (this->_buttons.size());
}

GameButton*		MainMenu::getCursor() const
{
  return (this->_cursor);
}

std::list<GameButton*>::iterator 	MainMenu::getCurrent()
{
  for (std::list<GameButton*>::iterator it = this->_buttons.begin(); it != this->_buttons.end(); it++)
    {
      if ((*it)->getCurrent())
	return (it);
    }
  return (this->_buttons.end());
}

void			MainMenu::moveCursor()
{
  std::list<GameButton*>::iterator it = this->getCurrent();
  glm::vec3 pos;

  (*it)->setCurrent(false);
  if (++it == this->_buttons.end())
    {
      this->_buttons.front()->setCurrent(true);
      pos = this->_buttons.front()->getPos();
    }
  else
    {
      (*it)->setCurrent(true);
      pos = (*it)->getPos();
    }
  pos.x = -500;
  this->_cursor->setPos(pos);
}

void			MainMenu::selectButton(SceneManager *sm)
{
  if (!sm->setCurrentScene(std::string("gameScene")))
    std::cerr << "Error while loading scene Game" << std::endl;
}
