//
// MainMenu.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src/Scenes
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Mon Jun  8 09:29:53 2015 Valérian Polizzi
// Last update Mon Jun  8 11:41:31 2015 Valérian Polizzi
//

#include	<MainMenu.hh>

MainMenu::MainMenu()
{
    this->_p1 = new Pavement(glm::vec3(0, 300, 0), std::string("play.tga"));
    this->_p1->setScale(glm::vec3(800, 200, 60));
    this->_p2 = new Pavement(glm::vec3(0, 0, 0), std::string("wall_texture.tga"));
    this->_p2->setScale(glm::vec3(800, 200, 60));
    this->addEntity(this->_p1);
    this->addEntity(this->_p2);
}

MainMenu::~MainMenu()
{

}
