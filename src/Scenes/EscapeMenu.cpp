//
// EscapeMenu.cpp for  in /home/ades_n/Work/bomberman/src/Scenes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.eu>
//
// Started on  Fri Jun 12 11:12:51 2015 Nicolas Adès
// Last update Sat Jun 13 19:21:11 2015 mari_f
//

#include <EscapeMenu.hh>

EscapeMenu::EscapeMenu(CameraManager &cm) : Scene(&cm)
{
  Cloud		*cloud;
  this->_buttons.push_back(new GameButton(glm::vec3(0, 50, 0), std::string("assets/textures/resume.tga"), RESUME));
  this->_buttons.front()->setCurrent(true);
  this->_buttons.push_back(new GameButton(glm::vec3(0, -150, 0), std::string("assets/textures/save.tga"), SAVE));
  this->_buttons.push_back(new GameButton(glm::vec3(0, -350, 0), std::string("assets/textures/quit.tga"), QUIT));

    cloud = new Cloud(glm::vec3(-500, -300, 0), std::string("assets/textures/cloud.tga"));
  cloud->setScale(glm::vec3(250, 150, 0));
  this->addEntity(cloud);
  cloud = new Cloud(glm::vec3(-700, 300, 0), std::string("assets/textures/cloud.tga"), 0.5f, 40.0f);
  cloud->setScale(glm::vec3(400, 240, 0));
  this->addEntity(cloud);
  cloud = new Cloud(glm::vec3(500, 250, 0), std::string("assets/textures/cloud.tga"), 0.7f, 60.0f);
  cloud->setScale(glm::vec3(150, 100, 0));
  this->addEntity(cloud);
  cloud = new Cloud(glm::vec3(400, -200, 0), std::string("assets/textures/cloud.tga"), 0.2f, 10.0f);
  cloud->setScale(glm::vec3(170, 110, 0));
  this->addEntity(cloud);
  cloud = new Cloud(glm::vec3(300, -500, 0), std::string("assets/textures/cloud.tga"), 0.5f, 10.0f);
  cloud->setScale(glm::vec3(230, 180, 0));
  this->addEntity(cloud);

  this->_eventHandler = new EscapeEvent();
  for (std::list<GameButton*>::iterator it = this->_buttons.begin(); it != this->_buttons.end(); it++)
    {
      (*it)->setScale(glm::vec3(300, 100, 100));
      this->addEntity((*it));
    }
  this->_cursor = new GameButton(glm::vec3(-250, 50, 0), std::string("assets/textures/hat.tga"));
  this->_cursor->setScale(glm::vec3(120, 120, 0));
  this->_cursor->setCurrent(false);
  this->addEntity(this->_cursor);
  Pavement*	background = new Pavement(glm::vec3(0, 0, 0), std::string("assets/textures/background.tga"));
  background->setScale(glm::vec3(2500, 1300, 0));
  this->addEntity(background);
}

EscapeMenu::~EscapeMenu()
{

}

void					EscapeMenu::initialize()
{
  this->_cm->moveTo(glm::vec3(0, 0, 1000), glm::vec3(0, 0, 0));
}

void					EscapeMenu::moveCursorDown()
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
  pos.x = -250;
  this->_cursor->setPos(pos);
}

void					EscapeMenu::moveCursorUp()
{
  std::list<GameButton*>::iterator it = this->getCurrent();
  glm::vec3 pos;

  (*it)->setCurrent(false);
  if (it == this->_buttons.begin())
    {
      this->_buttons.back()->setCurrent(true);
      pos = this->_buttons.back()->getPos();
    }
  else
    {
      it--;
      (*it)->setCurrent(true);
      pos = (*it)->getPos();
    }
  pos.x = -250;
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
  std::string				nextScene = "";

  switch ((*this->getCurrent())->getId())
    {
    case RESUME:
      nextScene = "gameScene";
      break;
    case SAVE:
      nextScene = "save";
      break;
    case QUIT:
      nextScene = "mainMenu";
      if (!sm->removeScene(std::string("gameScene")))
	std::cerr << "Error while removing scene Game" << std::endl;
      break;
    }
  if (!sm->setCurrentScene(nextScene))
    std::cerr << "Error while loading scene: [" << nextScene << "]." << std::endl;
}
