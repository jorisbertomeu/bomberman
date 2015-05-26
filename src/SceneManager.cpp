//
// SceneManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:00:00 2015 Joris Bertomeu
// Last update Tue May 26 08:58:01 2015 Joris Bertomeu
//

#include	<SceneManager.hh>

SceneManager::SceneManager() :
  _currentScene(NULL)
{

}

SceneManager::~SceneManager()
{

}

bool	SceneManager::loadSceneFromFile(SceneManager::SCENE_TYPE type,
					const std::string &filename)
{
  SceneParser	newSceneParser;
  Scene		*newScene = new Scene();

  newSceneParser.load(filename);
  // this->_scenes.insert(this->_scenes.begin(), std::pair<SceneManager::SCENE_TYPE, Scene>(type, newScene.getScene()));
  newScene = newSceneParser.getScene();
  newScene->listAllEntities();
  this->_scenes.insert(std::pair<SceneManager::SCENE_TYPE, Scene*>(type, newScene));
  this->_currentScene = newScene;
  return (true);
}

bool	SceneManager::setCurrentScene(Scene &scene)
{
  (void) scene;
  return (true);
}

Scene	*SceneManager::getCurrentScene() const
{
  return (this->_currentScene);
}
