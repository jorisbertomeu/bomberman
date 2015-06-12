//
// MainMenu.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src/Scenes
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Mon Jun  8 09:29:53 2015 Valérian Polizzi
// Last update Fri Jun 12 04:08:03 2015 Geoffrey Merran
// Last update Tue Jun  9 20:52:02 2015 Geoffrey Merran
//

#include	<MainMenu.hh>

MainMenu::MainMenu()
{
  this->_buttons.push_back(new GameButton(glm::vec3(0, 300, 0), std::string("assets/textures/play.tga")));
  this->_buttons.front()->setCurrent(true);
  this->_buttons.push_back(new GameButton(glm::vec3(0, -300, 0), std::string("assets/textures/load.tga")));
  this->_buttons.push_back(new GameButton(glm::vec3(0, 0, 0), std::string("assets/textures/quit.tga")));
  this->initialize();
}

MainMenu::~MainMenu()
{

}

void			MainMenu::initialize()
{
  for (std::list<GameButton*>::iterator it = this->_buttons.begin(); it != this->_buttons.end(); it++)
    {
      (*it)->setScale(glm::vec3(800, 200, 60));
      this->addEntity((*it));
    }
  this->_cursor = new GameButton(glm::vec3(-500, 300, 0), std::string("assets/textures/wall_texture.tga"));
  this->_cursor->setScale(glm::vec3(60, 60, 60));
  this->_cursor->setCurrent(true);
  this->addEntity(this->_cursor);
}

int			MainMenu::getListSize() const
{
  return (this->_buttons.size());
}

GameButton*		MainMenu::getCursor() const
{
  return (this->_cursor);
}

void			MainMenu::moveCursor()
{
  this->_cursor->setPos(glm::vec3(-500, 0, 0));
}
