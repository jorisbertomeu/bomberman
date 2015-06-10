//
// GameContext.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:47:58 2015 Joris Bertomeu
// Last update Wed Jun 10 02:54:17 2015 Joris Bertomeu
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
  this->_sceneManager.loadSceneFromFile(std::string("gameScene"), std::string("XMLfiles/ArchitectureXML.xml"));
  this->_sceneManager.setCurrentScene(std::string("mainMenu"), new MainMenu(this->_cameraManager));
  this->_inputManager.addEvent(new CommonEvent());
  this->_inputManager.addEvent(this->getCurrentScene()->getEventHandler());
  return (true);
}

Scene*		GameContext::getCurrentScene() const
{
  return (this->_sceneManager.getCurrentScene());
}

bool		GameContext::addScene(const std::string &path)
{
  return (this->_sceneManager.loadSceneFromFile(std::string("mainMap"), path));
}

void		GameContext::updateScene(gdl::Input & input)
{
  this->_inputManager.handleEvent(input, &this->_sceneManager, this->_cameraManager);
  this->getCurrentScene()->updateEntities(this->_renderManager->getTimeManager().getClock());
}
