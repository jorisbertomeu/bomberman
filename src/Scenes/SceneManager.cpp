//
// SceneManager.cpp for  in /home/mediav_j/mabm/bomberman
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Tue Jun  9 19:36:17 2015 Jérémy Mediavilla
// Last update Wed Jun 10 12:02:35 2015 Joris Bertomeu
//

#include	<SceneManager.hh>
#include	<Pavement.hh>
#include	<CommonEvent.hh>
#include	<GameEvent.hh>

SceneManager::SceneManager() :
  _currentScene(NULL)
{
  this->_renderManager = NULL;
}

SceneManager::~SceneManager()
{

}

void	SceneManager::setRenderManager(RenderManager *rm)
{
  this->_renderManager = rm;
}

bool	SceneManager::loadSceneFromFile(const std::string &sceneId,
					const std::string &filename)
{
  SceneParser	newSceneParser;
  Scene		*newScene = new Scene();

  newSceneParser.load(filename);
  newScene = newSceneParser.getScene(this->_renderManager);
  newScene->setEventHandler(new GameEvent());
  this->_scenes.insert(std::pair<std::string, Scene*>(sceneId, newScene));
  //this->_currentScene = newScene;
  // newScene->save(this->_renderManager);
  return (true);
}

bool	SceneManager::setCurrentScene(std::string sceneId)
{
  for(std::map<std::string, Scene *>::iterator it = this->_scenes.begin(); it != this->_scenes.end(); ++it) {
    if ((*it).first == sceneId) {
      this->_currentScene = (*it).second;
      this->_inputManager->removeEvents();
      this->_inputManager->addEvent(new CommonEvent());
      this->_inputManager->addEvent(this->getCurrentScene()->getEventHandler());
      return (true);
    }
  }
  return (false);
}

bool	SceneManager::setCurrentScene(std::string sceneId, Scene *scene)
{
  this->_scenes.insert(std::pair<std::string, Scene*>(sceneId, scene));
  this->_currentScene = scene;
  this->_inputManager->removeEvents();
  this->_inputManager->addEvent(new CommonEvent());
  this->_inputManager->addEvent(this->getCurrentScene()->getEventHandler());
  return (true);
}

Scene	*SceneManager::getCurrentScene() const
{
  return (this->_currentScene);
}

void	SceneManager::addEntityToCurrentScene(AEntity *entity_)
{
  this->_currentScene->addEntity(entity_);
}

void	SceneManager::setInputManager(InputManager *im)
{
  this->_inputManager = im;
}
