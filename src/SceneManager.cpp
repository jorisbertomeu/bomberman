//
// SceneManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:00:00 2015 Joris Bertomeu
// Last update Mon Jun  1 16:14:44 2015 Jérémy Mediavilla
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
  SceneParser	newScene;

  newScene.load(filename);
  // this->_scenes.insert(this->_scenes.begin(), std::pair<SceneManager::SCENE_TYPE, Scene>(type, newScene.getScene()));
  newScene.getScene();
  (void)type;
  return (true);
}

bool	SceneManager::setCurrentScene(AScene &scene)
{
  (void) scene;
  return (true);
}

AScene	*SceneManager::getCurrentScene() const
{
  return (this->_currentScene);
}
