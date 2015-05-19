//
// GameContext.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:45:20 2015 Joris Bertomeu
// Last update Tue May 19 13:18:02 2015 Joris Bertomeu
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
  explicit	GameContext(RenderManager *);
  virtual	~GameContext();
  bool		initialize();
};

#endif		/* _GAMECONTEXT_HH_ */
