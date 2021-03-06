//
// SceneManager.cpp for  in /home/mediav_j/mabm/bomberman
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Tue Jun  9 19:36:17 2015 Jérémy Mediavilla
// Last update Sun Jun 14 22:48:03 2015 Jérémy Mediavilla
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

void   	SceneManager::initialize(CameraManager* cm, RenderManager *rm, int* running)
{
  this->_cm = cm;
  this->_renderManager = rm;
  this->_running = running;
}

bool	SceneManager::loadSceneFromFile(const std::string &sceneId,
					const std::string &filename)
{
  SceneParser	newSceneParser;
  Scene		*newScene;

  newSceneParser.load(filename);
  std::cout << "[MAP_LOADING] NEW MAP LOADED FROM: " << filename << std::endl;
  newScene = newSceneParser.getScene(this->_renderManager, this->_cm);
  newScene->setEventHandler(new GameEvent());
  this->_scenes.insert(std::pair<std::string, Scene*>(sceneId, newScene));
  newScene->save(this->_renderManager);
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
      this->_currentScene->initialize();
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
  this->_currentScene->initialize();
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

void	SceneManager::addScene(std::string sceneId, Scene* scene)
{
  this->_scenes.insert(std::pair<std::string, Scene*>(sceneId, scene));
}

bool	SceneManager::removeScene(const std::string &sceneId)
{
  for(std::map<std::string, Scene *>::iterator it = this->_scenes.begin(); it != this->_scenes.end(); ++it) {
    if ((*it).first == sceneId) {
      this->_scenes.erase(it);
      return (true);
    }
  }
  return (false);
}

void	SceneManager::stopGame()
{
  *this->_running = 0;
}

Scene		*SceneManager::getScene(const std::string &id)
{
   for(std::map<std::string, Scene *>::iterator it = this->_scenes.begin(); it != this->_scenes.end(); ++it) {
     if ((*it).first == id)
       return ((*it).second);
   } 
   return (NULL);
}

