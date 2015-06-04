//
// Event.hh for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:40:00 2015 mari_f
// Last update Thu Jun  4 13:12:43 2015 mari_f
//

#ifndef				_EVENT_HH__
# define			_EVENT_HH__

# include			<IEvent.hh>
# include			<string>
# include			<iostream>
# include			<Input.hh>
# include			<SDL_keycode.h>

class Event : public IEvent
{
public:
  enum Keys {
    UP,
    DOWN,
    RIGHT,
    LEFT,
    NO
  };

  Event(void);
  virtual ~Event(void);
  virtual bool		isCatch(gdl::Input &input);
};

#endif
