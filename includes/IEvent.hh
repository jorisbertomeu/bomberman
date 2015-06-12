//
// IEvent.hh for  in /home/mari_f/testtt/src
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:34:31 2015 mari_f
// Last update Fri Jun 12 20:46:12 2015 Geoffrey Merran
//

#ifndef			_IEVENT_HH__
# define		_IEVENT_HH__

# include	       	<SDL_keycode.h>
# include		<Input.hh>
# include		<Clock.hh>

class			IEvent;

# include		<SceneManager.hh>
# include		<CameraManager.hh>

class			IEvent
{
public:
  virtual		~IEvent() {};
  virtual bool	       	isCatch(gdl::Input &input, gdl::Clock&, SceneManager*, CameraManager&) = 0;
};

#endif
