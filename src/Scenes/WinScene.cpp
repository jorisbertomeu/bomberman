//
// WinScene.cpp for Bomberman in /home/polizz_v/rendu/CPP/git/bomberman
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Sun Jun 14 15:50:54 2015 Valérian Polizzi
// Last update Sun Jun 14 19:15:03 2015 Valérian Polizzi
//

#include		<WinScene.hh>

WinScene::WinScene(CameraManager& cm) : Scene(&cm)
{
  Pavement *background = new Pavement(glm::vec3(0, 0, 0), std::string("assets/textures/win.tga"));

  background->setScale(glm::vec3(2500, 1300, 0));
  this->addEntity(background);
  this->_eventHandler = new GameOverEvent();
}

WinScene::~WinScene()
{
}
