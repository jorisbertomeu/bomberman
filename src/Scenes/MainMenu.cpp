//
// MainMenu.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src/Scenes
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Mon Jun  8 09:29:53 2015 Valérian Polizzi
// Last update Wed Jun 10 11:13:38 2015 Valérian Polizzi
// Last update Tue Jun  9 20:52:02 2015 Geoffrey Merran
//

#include	<MainMenu.hh>

MainMenu::MainMenu()
{
    this->_p1 = new Pavement(glm::vec3(0, 300, 0), std::string("play2.tga"));
    this->_p1->setScale(glm::vec3(800, 200, 60));
    this->_p2 = new Pavement(glm::vec3(0, 0, 0), std::string("quit2.tga"));
    this->_p2->setScale(glm::vec3(800, 200, 60));
    this->addEntity(this->_p1);
    this->addEntity(this->_p2);
}

MainMenu::~MainMenu()
{

}
