//
// GameContext.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:47:58 2015 Joris Bertomeu
// Last update Wed Jun  3 16:35:31 2015 Geoffrey Merran
//

#include	<GameContext.hh>

GameContext::GameContext()
{

}

GameContext::~GameContext()
{

}

bool	GameContext::initialize(RenderManager *rm, const glm::vec2 &windowSize)
{
  this->_cameraManager.initialize(rm, windowSize);
  return (true);
}

Scene	*GameContext::getCurrentScene() const
{
  return (this->_sceneManager.getCurrentScene());
}

bool		GameContext::addScene(const std::string &path)
{
  return (this->_sceneManager.loadSceneFromFile(SceneManager::MAP, path));
}
