//
// MainMenu.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src/Scenes
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Mon Jun  8 09:29:53 2015 Valérian Polizzi
// Last update Sat Jun 13 02:17:30 2015 Geoffrey Merran
//

#include	<MainMenu.hh>

MainMenu::MainMenu(CameraManager & cm) : Scene(&cm)
{
  this->_buttons.push_back(new GameButton(glm::vec3(0, 50, 0), std::string("assets/textures/play.tga"), MainMenu::PLAY));
  this->_buttons.front()->setCurrent(true);
  this->_buttons.push_back(new GameButton(glm::vec3(0, -150, 0), std::string("assets/textures/load.tga"), MainMenu::LOAD));
  this->_buttons.push_back(new GameButton(glm::vec3(0, -350, 0), std::string("assets/textures/quit.tga"), MainMenu::QUIT));
  this->_eventHandler = new MenuEvent();
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

void			MainMenu::moveCursorDown()
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

void			MainMenu::moveCursorUp()
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

void			MainMenu::selectButton(SceneManager *sm)
{
  std::string		nextScene;

  switch ((*this->getCurrent())->getId())
    {
    case PLAY:
      nextScene = "newGame";
      break;
    case LOAD:
      nextScene = "loadMap";
      break;
    case QUIT:
      sm->stopGame();
      return ;
      break;
    }
  if (!sm->setCurrentScene(nextScene))
    std::cerr << "Error while loading scene: " << nextScene << std::endl;
}
