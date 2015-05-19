//
// GameEngine.hh for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 09:27:41 2015 Joris Bertomeu
// Last update Tue May 19 10:32:48 2015 Joris Bertomeu
//

#ifndef		_GAMEENGINE_HH_
# define	_GAMEENGINE_HH_

# include	<Game.hh>
# include	<Clock.hh>
# include	<Input.hh>
# include	<SdlContext.hh>
# include	<Geometry.hh>
# include	<Texture.hh>
# include	<BasicShader.hh>
# include	<Model.hh>

# include	<stdexcept>
# include	<iostream>

# include	<Parameters.hpp>

class		GameEngine : public gdl::Game
{
protected:
  Parameters	_parameters;
public:
  explicit	GameEngine(int ac, char **argv);
  virtual	~GameEngine();
  virtual bool	initialize();
  virtual bool	update();
  virtual void	draw();
  bool		run();
};

#endif		/* _GAMEENGINE_HH_ */
