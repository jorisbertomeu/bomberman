//
// GameContext.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:47:58 2015 Joris Bertomeu
// Last update Sun Jun 14 19:18:24 2015 Valérian Polizzi
//

#include	<GameContext.hh>

GameContext::GameContext()
{

}

GameContext::~GameContext()
{

}

bool		GameContext::initialize(RenderManager *rm, const glm::vec2 &windowSize, int* running)
{
  this->_renderManager = rm;
  this->_sceneManager.initialize(&this->_cameraManager, rm, running);
  this->_sceneManager.setInputManager(&(this->_inputManager));
  this->_cameraManager.initialize(rm, windowSize);
  this->_renderManager->setCameraManager(&this->_cameraManager);
    this->_sceneManager.addScene("escapeMenu", new EscapeMenu(this->_cameraManager));
  this->_sceneManager.addScene("newGame", new NewGameMenu(this->_cameraManager, "maps/"));
  this->_sceneManager.addScene("loadMap", new NewGameMenu(this->_cameraManager, "saves/"));
  this->_sceneManager.addScene("loadingScene", new LoadingScene(this->_cameraManager));
  this->_sceneManager.setCurrentScene("WinScene", new WinScene(this->_cameraManager));
  this->_sceneManager.setCurrentScene("LoseScene", new LoseScene(this->_cameraManager));
  this->_sceneManager.setCurrentScene("mainMenu", new MainMenu(this->_cameraManager));
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
  this->_inputManager.handleEvent(input, this->_renderManager->getTimeManager().getClock(),&this->_sceneManager, this->_cameraManager);
  this->getCurrentScene()->updateEntities(this->_renderManager->getTimeManager().getClock());
}
