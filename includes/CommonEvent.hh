//
// Event.hh for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:40:00 2015 mari_f
// Last update Sat Jun  6 19:50:50 2015 Geoffrey Merran
//

#ifndef				_COMMON_EVENT_HH
# define			_COMMON_EVENT_HH

# include			<string>
# include			<iostream>
# include			<map>

# include			<SDL_keycode.h>

# include			<IEvent.hh>

class				CommonEvent : public IEvent
{
public:
  typedef void (CommonEvent::*eventHandler)(Scene*);

  CommonEvent(void);
  virtual			~CommonEvent(void);

  void				escape(Scene*);
  virtual bool			isCatch(gdl::Input &input, Scene*, CameraManager&);

private:
  std::map<int, eventHandler>	_events;
};

#endif /* _COMMON_EVENT_HH */
