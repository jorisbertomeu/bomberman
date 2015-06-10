//
// SceneManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:48:47 2015 Joris Bertomeu
// Last update Wed Jun 10 02:44:04 2015 Joris Bertomeu
//

#ifndef				_SCENEMANAGER_HH_
# define			_SCENEMANAGER_HH_

# include			<string>
# include			<map>

class				SceneManager;

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
  std::map<std::string, Scene*>	_scenes;
  Scene				*_currentScene;
  RenderManager			*_renderManager;

public:
  explicit			SceneManager();
  virtual			~SceneManager();
  bool				loadSceneFromFile(const std::string &,
						  const std::string &);
  bool				setCurrentScene(std::string);
  bool				setCurrentScene(std::string, Scene *);
  Scene				*getCurrentScene() const;
  void				addEntityToCurrentScene(AEntity *);
  void				setRenderManager(RenderManager *);
};

#endif				/* _SCENEMANAGER_HH_ */
