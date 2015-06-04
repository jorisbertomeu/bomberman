//
// Event.hh for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:40:00 2015 mari_f
// Last update Thu Jun  4 14:41:26 2015 mari_f
//

#ifndef				_EVENT_HH__
# define			_EVENT_HH__

# include			<IEvent.hh>
# include			<string>
# include			<iostream>
# include			<Input.hh>
# include			<SDL_keycode.h>
# include			<Scene.hh>
# include			<map>

class CommonEvent : public IEvent
{
public:
  typedef void (CommonEvent::*eventHandler)(Scene*);

  CommonEvent(void);
  void		escape(Scene*);
  virtual ~CommonEvent(void);
  virtual bool		isCatch(gdl::Input &input, Scene*);

  std::map<int, eventHandler>	_events;
};

#endif