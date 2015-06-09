//
// SceneManager.cpp for  in /home/mediav_j/mabm/bomberman
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Tue Jun  9 19:36:17 2015 Jérémy Mediavilla
// Last update Tue Jun  9 19:36:17 2015 Jérémy Mediavilla
//

#include	<SceneManager.hh>
#include	<Pavement.hh>

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

bool	SceneManager::loadSceneFromFile(SceneManager::SCENE_TYPE type,
					const std::string &filename)
{
  SceneParser	newSceneParser;
  Scene		*newScene = new Scene();

  newSceneParser.load(filename);
  newScene = newSceneParser.getScene(this->_renderManager);
  newScene->listAllEntities();
  this->_scenes.insert(std::pair<SceneManager::SCENE_TYPE, Scene*>(type, newScene));
  this->_currentScene = newScene;
  newScene->save();
  return (true);
}

bool	SceneManager::setCurrentScene(Scene *scene)
{
  this->_currentScene = scene;
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
