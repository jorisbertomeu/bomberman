//
// LoseScnene.cpp for Bomberman in /home/polizz_v/rendu/CPP/git/bomberman
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Sun Jun 14 17:55:30 2015 Valérian Polizzi
// Last update Sun Jun 14 19:14:13 2015 Valérian Polizzi
//

#include <LoseScene.hh>

LoseScene::LoseScene(CameraManager& cm) : Scene(&cm)
{
  Pavement *background = new Pavement(glm::vec3(0, 0, 0), std::string("assets/textures/lose.tga"));

  background->setScale(glm::vec3(2500, 1300, 0));
  this->addEntity(background);
  this->_eventHandler = new GameOverEvent();
}

LoseScene::~LoseScene()
{

}
