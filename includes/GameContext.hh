//
// GameContext.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:45:20 2015 Joris Bertomeu
// Last update Wed Jun  3 11:36:49 2015 Geoffrey Merran
//

#ifndef		_GAMECONTEXT_HH_
# define	_GAMECONTEXT_HH_

# include	<SceneManager.hh>
# include	<CameraManager.hh>
# include	<InputManager.hh>
# include	<SceneFactory.hh>

class		GameContext
{
private:
  SceneManager	_sceneManager;
  CameraManager	_cameraManager;
  InputManager	_inputManager;
  SceneFactory	_sceneFactory;

public:
  explicit	GameContext();
  virtual	~GameContext();
  bool		initialize(RenderManager *, const glm::vec2 &);
  AScene	*getCurrentScene() const;
  bool		addScene(const std::string &);
};

#endif		/* _GAMECONTEXT_HH_ */
