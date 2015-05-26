//
// SceneManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:00:00 2015 Joris Bertomeu
// Last update Tue May 26 18:05:29 2015 Jérémy Mediavilla
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
  // SceneParser	newScene;

  // newScene.load(filename);
  // this->_scenes.add(newScene.createNewScene());
  (void) type;
  (void) filename;
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
