//
// Event.hh for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:40:00 2015 mari_f
// Last update Sat Jun  6 14:22:03 2015 Geoffrey Merran
//

#ifndef				_EVENT_HH__
# define			_EVENT_HH__

# include			<string>
# include			<iostream>
# include			<IEvent.hh>
# include			<Input.hh>
# include			<SDL_keycode.h>
# include			<Scene.hh>
# include			<map>
# include			<list>
# include			<AEntity.hh>
# include			<Bomberman.hh>

class				GameEvent : public IEvent
{
public:
  typedef void (GameEvent::*eventHandler)(Scene*);

  GameEvent(void);
  virtual ~GameEvent(void);

  void		up(Scene*);
  void		down(Scene*);
  void		right(Scene*);
  void		left(Scene*);
  virtual bool 	isCatch(gdl::Input &input, Scene*);

  std::map<int, eventHandler>	_events;
};

#endif
