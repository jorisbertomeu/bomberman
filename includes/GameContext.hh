//
// GameContext.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:45:20 2015 Joris Bertomeu
// Last update Sat Jun 13 23:59:01 2015 Geoffrey Merran
//

#ifndef		_GAMECONTEXT_HH_
# define	_GAMECONTEXT_HH_

# include	<SceneManager.hh>
# include	<CameraManager.hh>
# include	<InputManager.hh>
# include	<CommonEvent.hh>
# include	<MainMenu.hh>
# include	<EscapeMenu.hh>
# include	<NewGameMenu.hh>
# include	<LoadingScene.hh>

class		GameContext
{
private:
  SceneManager	_sceneManager;
  CameraManager	_cameraManager;
  InputManager	_inputManager;
  RenderManager	*_renderManager;

public:
  explicit	GameContext();
  virtual	~GameContext();
  bool		initialize(RenderManager *, const glm::vec2 &, int*);
  Scene		*getCurrentScene() const;
  bool		addScene(const std::string &);
  void		updateScene(gdl::Input &);
};

#endif		/* _GAMECONTEXT_HH_ */
