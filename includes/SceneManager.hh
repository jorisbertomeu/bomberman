//
// SceneManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:48:47 2015 Joris Bertomeu
// Last update Tue May 26 09:46:29 2015 Joris Bertomeu
//

#ifndef				_SCENEMANAGER_HH_
# define			_SCENEMANAGER_HH_

# include			<string>
# include			<map>

# include			<Scene.hh>
# include			<SceneParser.hh>
# include			<RenderManager.hh>

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
  RenderManager			*_renderManager;

public:
  explicit			SceneManager();
  virtual			~SceneManager();
  bool				loadSceneFromFile(SCENE_TYPE,
						  const std::string &);
  bool				setCurrentScene(Scene &);
  Scene				*getCurrentScene() const;
  void				addEntityToCurrentScene(AEntity *);
  void				setRenderManager(RenderManager *);
};

#endif				/* _SCENEMANAGER_HH_ */
