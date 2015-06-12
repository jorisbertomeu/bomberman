//
// SceneManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:48:47 2015 Joris Bertomeu
// Last update Fri Jun 12 22:41:27 2015 Geoffrey Merran
//

#ifndef				_SCENEMANAGER_HH_
# define			_SCENEMANAGER_HH_

# include			<string>
# include			<map>

class				SceneManager;

# include			<Scene.hh>
# include			<SceneParser.hh>
# include			<RenderManager.hh>
# include			<InputManager.hh>

class				SceneManager
{
public:
  typedef	enum		e_scene_type
    {
      MENU			= 0,
      MAP
    }				SCENE_TYPE;

private:
  std::map<std::string, Scene*>	_scenes;
  Scene				*_currentScene;
  RenderManager			*_renderManager;
  InputManager			*_inputManager;
  CameraManager			*_cm;
  int				*_running;

public:
  explicit			SceneManager();
  virtual			~SceneManager();
  void				initialize(CameraManager* cm, RenderManager* rm);
  bool				loadSceneFromFile(const std::string &,
						  const std::string &);
  bool				setCurrentScene(std::string);
  bool				setCurrentScene(std::string, Scene *);
  Scene				*getCurrentScene() const;
  void				addEntityToCurrentScene(AEntity *);
  void				setInputManager(InputManager *);
};

#endif				/* _SCENEMANAGER_HH_ */
