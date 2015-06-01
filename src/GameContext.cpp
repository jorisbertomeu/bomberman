//
// GameContext.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:47:58 2015 Joris Bertomeu
// Last update Mon Jun  1 16:03:44 2015 Jérémy Mediavilla
//

#include	<GameContext.hh>

GameContext::GameContext()
{

}

GameContext::~GameContext()
{

}

bool	GameContext::initialize(RenderManager *rm)
{
  this->_cameraManager.initialize(rm);
  return (true);
}

AScene	*GameContext::getCurrentScene() const
{
  return (this->_sceneManager.getCurrentScene());
}

bool		GameContext::addScene(const std::string &path)
{
  return (this->_sceneManager.loadSceneFromFile(SceneManager::MAP, path));
}
