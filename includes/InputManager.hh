//
// InputManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:08:29 2015 Joris Bertomeu
// Last update Fri Jun 12 04:42:12 2015 Geoffrey Merran
//

#ifndef		_INPUTMANAGER_HH_
# define	_INPUTMANAGER_HH_

# include	<iostream>
# include	<string>
# include	<list>

# include	<Clock.hh>
# include	<Input.hh>
# include	<SDL_keycode.h>
# include	<IEvent.hh>
# include	<Scene.hh>
# include	<CameraManager.hh>

class			InputManager
{
private:
  std::list<IEvent*>	_events;
public:
  explicit	InputManager();
  virtual	~InputManager();
  void		addEvent(IEvent*);
  void		handleEvent(gdl::Input &, Scene*, CameraManager &);
  void		removeEvents();
};

#endif		/* _INPUTMANAGER_HH_ */
