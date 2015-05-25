//
// GameEngine.hh for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 09:27:41 2015 Joris Bertomeu
// Last update Mon May 25 17:16:45 2015 Geoffrey Merran
//

#ifndef		_GAMEENGINE_HH_
# define	_GAMEENGINE_HH_

# include	<Game.hh>

# include	<stdexcept>
# include	<iostream>

# include	<Parameters.hpp>
# include	<RenderManager.hh>
# include	<GameContext.hh>

class		GameEngine : public gdl::Game
{
protected:
  Parameters	_parameters;
  RenderManager	_renderManager;
  GameContext	_gameContext;
  int		_running;

public:
  explicit	GameEngine(int ac, char **argv);
  virtual	~GameEngine();
  virtual bool	initialize();
  virtual bool	update();
  virtual void	draw();
  bool		run();
};

#endif		/* _GAMEENGINE_HH_ */
