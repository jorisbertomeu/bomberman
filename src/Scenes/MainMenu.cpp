//
// MainMenu.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src/Scenes
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Mon Jun  8 09:29:53 2015 Valérian Polizzi
// Last update Tue Jun  9 20:52:02 2015 Geoffrey Merran
//

#include	<MainMenu.hh>

MainMenu::MainMenu()
{
    this->_p1 = new Pavement(glm::vec3(100, 200, 0), "wall_texture.tga");
    this->_p1->setScale(glm::vec3(800, 200, 60));
    this->addEntity(this->_p1);
}

MainMenu::~MainMenu()
{

}
