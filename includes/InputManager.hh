//
// InputManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:08:29 2015 Joris Bertomeu
// Last update Thu Jun  4 12:06:24 2015 mari_f
//

#ifndef		_INPUTMANAGER_HH_
# define	_INPUTMANAGER_HH_

# include	<Clock.hh>
# include	<Input.hh>
# include	<SDL_keycode.h>
# include	<iostream>
# include	<string>
# include	<list>
# include	<Event.hh>

class			InputManager
{
private:
  std::list<IEvent*>	_events;
public:
  explicit	InputManager();
  virtual	~InputManager();
  void		addEvent(IEvent*);
  void		handleEvent(gdl::Input &);
};

#endif		/* _INPUTMANAGER_HH_ */
