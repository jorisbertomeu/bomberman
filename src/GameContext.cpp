//
// GameContext.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:47:58 2015 Joris Bertomeu
// Last update Tue Jun  9 12:25:57 2015 Joris Bertomeu
//

#include	<GameContext.hh>

GameContext::GameContext()
{

}

GameContext::~GameContext()
{

}

bool		GameContext::initialize(RenderManager *rm, const glm::vec2 &windowSize)
{
  this->_renderManager = rm;
  this->_sceneManager.setRenderManager(rm);
  this->_cameraManager.initialize(rm, windowSize);
  return (true);
}

Scene		*GameContext::getCurrentScene() const
{
  return (this->_sceneManager.getCurrentScene());
}

bool		GameContext::addScene(const std::string &path)
{
  this->_inputManager.addEvent(new CommonEvent());
  this->_inputManager.addEvent(new GameEvent());
  return (this->_sceneManager.setCurrentScene(new MainMenu()));
  //return (this->_sceneManager.loadSceneFromFile(SceneManager::MAP, path));
}

void		GameContext::updateScene(gdl::Input & input)
{
  this->_inputManager.handleEvent(input, this->getCurrentScene(), this->_cameraManager);
}
