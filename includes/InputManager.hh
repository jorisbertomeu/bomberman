//
// InputManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:08:29 2015 Joris Bertomeu
// Last update Wed May 20 21:25:17 2015 mari_f
//

#ifndef		_INPUTMANAGER_HH_
# define	_INPUTMANAGER_HH_

# include	<Clock.hh>
# include	<Input.hh>

class		InputManager
{
public:
  explicit	InputManager();
  virtual	~InputManager();
  void	       	up();
  void		down();
  void		right();
  void		left();
  void		jump();
  void		DetectKey();
};

#endif		/* _INPUTMANAGER_HH_ */
