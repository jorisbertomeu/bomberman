//
// GameEngine.hh for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 09:27:41 2015 Joris Bertomeu
// Last update Wed Jun 10 03:53:06 2015 Joris Bertomeu
//

#ifndef		_GAMEENGINE_HH_
# define	_GAMEENGINE_HH_

# include	<stdexcept>
# include	<iostream>

# include	<Game.hh>
# include	<Input.hh>

class		GameEngine;

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
  gdl::Input	_input;

public:
  explicit	GameEngine(int ac, char **argv);
  virtual	~GameEngine();
  virtual bool	initialize();
  virtual bool	update();
  virtual void	draw();
  bool		run();
};

#endif		/* _GAMEENGINE_HH_ */
