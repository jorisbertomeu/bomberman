//
// SceneManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:48:47 2015 Joris Bertomeu
// Last update Tue May 26 08:50:43 2015 Joris Bertomeu
//

#ifndef				_SCENEMANAGER_HH_
# define			_SCENEMANAGER_HH_

# include			<string>
# include			<map>

# include			<Scene.hh>
# include			<SceneParser.hh>

class				SceneManager
{
public:
  typedef	enum		e_scene_type
    {
      MENU			= 0,
      MAP
    }				SCENE_TYPE;

private:
  std::map<SCENE_TYPE, Scene*>	_scenes;
  Scene				*_currentScene;

public:
  explicit			SceneManager();
  virtual			~SceneManager();
  bool				loadSceneFromFile(SCENE_TYPE,
						  const std::string &);
  bool				setCurrentScene(Scene &);
  Scene				*getCurrentScene() const;
};

#endif				/* _SCENEMANAGER_HH_ */
