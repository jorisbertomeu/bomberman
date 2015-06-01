//
// SceneManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:48:47 2015 Joris Bertomeu
// Last update Mon Jun  1 16:07:54 2015 Jérémy Mediavilla
//

#ifndef				_SCENEMANAGER_HH_
# define			_SCENEMANAGER_HH_

# include			<string>
# include			<map>

# include			<AScene.hh>
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
  std::map<SCENE_TYPE, AScene>	_scenes;
  AScene			*_currentScene;

public:
  explicit			SceneManager();
  virtual			~SceneManager();
  bool				loadSceneFromFile(SCENE_TYPE,
						  const std::string &);
  bool				setCurrentScene(AScene &);
  AScene			*getCurrentScene() const;
};

#endif				/* _SCENEMANAGER_HH_ */
