//
// SceneManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:00:00 2015 Joris Bertomeu
// Last update Tue Jun  9 12:38:23 2015 Joris Bertomeu
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
