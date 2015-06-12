//
// NewGameMenu.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 01:38:42 2015 Geoffrey Merran
// Last update Sat Jun 13 03:22:01 2015 Geoffrey Merran
//

#include <NewGameMenu.hh>

NewGameMenu::NewGameMenu(CameraManager & cm, const std::string & folderPath) : Scene(&cm)
{
  this->_buttons.push_back(new GameButton(glm::vec3(-300, -350, 100), std::string("assets/textures/left.tga"), LEFT));
  this->_buttons.back()->setScale(glm::vec3(100, 100, 100));
  this->_buttons.push_back(new GameButton(glm::vec3(0, -350, 100), std::string("assets/textures/ok.tga"), OK));
  this->_buttons.back()->setCurrent(true);
  this->_buttons.back()->setScale(glm::vec3(300, 100, 100));
  this->_buttons.push_back(new GameButton(glm::vec3(300, -350, 100), std::string("assets/textures/right.tga"), RIGHT));
  this->_buttons.back()->setScale(glm::vec3(100, 100, 100));
  this->_eventHandler = new NewGameEvent();
  for (std::list<GameButton*>::iterator it = this->_buttons.begin(); it != this->_buttons.end(); it++)
    {
      this->addEntity((*it));
    }
  Pavement*	background = new Pavement(glm::vec3(0, 0, 0), std::string("assets/textures/background.tga"));
  background->setScale(glm::vec3(2500, 1300, 0));
  this->addEntity(background);
}

NewGameMenu::~NewGameMenu()
{

}

void					NewGameMenu::initialize()
{
  this->_cm->moveTo(glm::vec3(0, 0, 1000), glm::vec3(0, 0, 0));
}

void					NewGameMenu::moveNextMap()
{
  (*this->getCurrent())->setCurrent(false);
  this->_buttons.back()->setCurrent(true);
}

void					NewGameMenu::movePrevMap()
{
  (*this->getCurrent())->setCurrent(false);
  this->_buttons.front()->setCurrent(true);
}

std::list<GameButton*>::iterator    	NewGameMenu::getCurrent()
{
  for (std::list<GameButton*>::iterator it = this->_buttons.begin(); it != this->_buttons.end(); it++)
    {
      if ((*it)->getCurrent())
	return (it);
    }
  return (this->_buttons.end());
}

void					NewGameMenu::selectMap(SceneManager* sm)
{

}

void					NewGameMenu::back(SceneManager* sm) const
{
  if (!sm->setCurrentScene("mainMenu"))
    std::cerr << "Error while loading scene: [mainMenu]." << std::endl;
}
