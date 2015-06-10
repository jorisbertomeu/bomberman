//
// InputManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:08:29 2015 Joris Bertomeu
// Last update Wed Jun 10 03:57:58 2015 Joris Bertomeu
//

#ifndef		_INPUTMANAGER_HH_
# define	_INPUTMANAGER_HH_

# include	<iostream>
# include	<string>
# include	<list>

class			InputManager;

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
  void		handleEvent(gdl::Input &, SceneManager*, CameraManager &);
  void		removeEvents();
};

#endif		/* _INPUTMANAGER_HH_ */
