//
// EscapeMenu.cpp for  in /home/ades_n/Work/bomberman/src/Scenes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.eu>
//
// Started on  Fri Jun 12 11:12:51 2015 Nicolas Adès
// Last update Fri Jun 12 02:32:36 2015 Nicolas Adès
//

#include <EscapeMenu.hh>

EscapeMenu::EscapeMenu(CameraManager &cm) : Scene(&cm)
{
  this->_buttons.push_back(new GameButton(glm::vec3(0, 300, 0), std::string("assets/textures/resume.tga")));
  this->_buttons.front()->setCurrent(true);
  this->_buttons.push_back(new GameButton(glm::vec3(0, 0, 0), std::string("assets/textures/save.tga")));
  this->_buttons.push_back(new GameButton(glm::vec3(0, -300, 0), std::string("assets/textures/quit.tga")));
  this->_eventHandler = new EscapeEvent();
  for (std::list<GameButton*>::iterator it = this->_buttons.begin(); it != this->_buttons.end(); it++)
    {
      (*it)->setScale(glm::vec3(800, 200, 200));
      this->addEntity((*it));
    }
  this->_cursor = new GameButton(glm::vec3(-500, 300, 0), std::string("assets/textures/wall_texture.tga"));
  this->_cursor->setScale(glm::vec3(60, 60, 60));
  this->_cursor->setCurrent(true);
  this->addEntity(this->_cursor);
  Pavement*	background = new Pavement(glm::vec3(0, 0, 0), std::string("assets/textures/background.tga"));
  background->setScale(glm::vec3(2500, 2500, 0));
  this->addEntity(background);
}

EscapeMenu::~EscapeMenu()
{

}

void					EscapeMenu::initialize()
{
  this->_cm->moveTo(glm::vec3(0, 0, 1000), glm::vec3(0, 0, 0));
}

void					EscapeMenu::moveCursor()
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

GameButton*				EscapeMenu::getCursor() const
{
  return (this->_cursor);
}

std::list<GameButton*>::iterator	EscapeMenu::getCurrent()
{
  for (std::list<GameButton*>::iterator it = this->_buttons.begin(); it != this->_buttons.end(); it++)
    {
      if ((*it)->getCurrent())
	return (it);
    }
  return (this->_buttons.end());
}

int					EscapeMenu::getListSize() const
{
  return (this->_buttons.size());
}

void					EscapeMenu::selectButton(SceneManager *sm)
{
  if (!sm->setCurrentScene(std::string("gameScene")))
    std::cerr << "Error while loading scene Game" << std::endl;
}
