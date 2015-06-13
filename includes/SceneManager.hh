//
// SceneManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:48:47 2015 Joris Bertomeu
// Last update Sat Jun 13 23:57:33 2015 Geoffrey Merran
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
  void				initialize(CameraManager* cm, RenderManager* rm, int *running);
  bool				loadSceneFromFile(const std::string &,
						  const std::string &);
  bool				setCurrentScene(std::string);
  bool				setCurrentScene(std::string, Scene *);
  Scene				*getCurrentScene() const;
  void				addEntityToCurrentScene(AEntity *);
  void				setInputManager(InputManager *);
  void				addScene(std::string, Scene*);
  bool				removeScene(const std::string &);
  void				stopGame();
};

#endif				/* _SCENEMANAGER_HH_ */
