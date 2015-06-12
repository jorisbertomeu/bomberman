//
// GameContext.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:47:58 2015 Joris Bertomeu
// Last update Fri Jun 12 03:35:43 2015 Geoffrey Merran
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
  this->_inputManager.addEvent(new CommonEvent());
  this->_inputManager.addEvent(new GameEvent());
  this->_sceneManager.setCurrentScene(new MainMenu());
  return (true);
}

Scene		*GameContext::getCurrentScene() const
{
  return (this->_sceneManager.getCurrentScene());
}

bool		GameContext::addScene(const std::string &path)
{
  (void)path;
  return (this->_sceneManager.loadSceneFromFile(SceneManager::MAP, path));
}

void		GameContext::updateScene(gdl::Input & input)
{
  this->_inputManager.handleEvent(input, this->getCurrentScene(), this->_cameraManager);
  this->getCurrentScene()->updateEntities(this->_renderManager->getTimeManager().getClock());
}
