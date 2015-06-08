//
// MainMenu.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src/Scenes
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Mon Jun  8 09:29:53 2015 Valérian Polizzi
// Last update Mon Jun  8 09:36:57 2015 Valérian Polizzi
//

#include	<MainMenu.hh>

MainMenu::MainMenu()
{
    this->_p1 = new Pavement(glm::vec3(100, 200, 0), std::string("wall_texture.tga"), glm::vec3(800, 200, 60));
    this->addEntity(this->_p1);
}

MainMenu::~MainMenu()
{

}
