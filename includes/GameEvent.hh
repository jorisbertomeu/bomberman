//
// Event.hh for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:40:00 2015 mari_f
// Last update Mon Jun  8 12:33:07 2015 Valérian Polizzi
//

#ifndef				_GAMEEVENT_HH__
# define			_GAMEEVENT_HH__

# include			<string>
# include			<iostream>
# include			<map>
# include			<list>

# include			<SDL_keycode.h>

# include			<IEvent.hh>
# include			<Bomberman.hh>

class				GameEvent : public IEvent
{
public:
  typedef void (GameEvent::*eventHandler)(Scene*);

  GameEvent(void);
  virtual			~GameEvent(void);
  virtual bool			isCatch(gdl::Input &input, Scene*, CameraManager&);

private:
  void				up(Scene*);
  void				down(Scene*);
  void				right(Scene*);
  void				left(Scene*);
  void				click(Scene*);

  void				updatePlayerCamera(const glm::vec3 & point);

  CameraManager			_camera;
  std::map<int, eventHandler>	_events;
};

#endif				/* _GAMEEVENT_HH__ */
