//
// Event.hh for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:40:00 2015 mari_f
// Last update Sun Jun 14 08:47:26 2015 Geoffrey Merran
//

#ifndef				_GAMEEVENT_HH__
# define			_GAMEEVENT_HH__

# include			<string>
# include			<iostream>
# include			<map>

class				GameEvent;

# include			<IEvent.hh>
# include			<Bomberman.hh>

class				GameEvent : public IEvent
{
public:
  typedef void (GameEvent::*eventHandler)(SceneManager*);

  GameEvent(void);
  virtual			~GameEvent(void);
  virtual bool			isCatch(gdl::Input &input, gdl::Clock&, SceneManager*, CameraManager&);

private:
  void				up(SceneManager*);
  void				down(SceneManager*);
  void				right(SceneManager*);
  void				left(SceneManager*);
  void				space(SceneManager*);
  void				escape(SceneManager*);
  void				updatePlayerCamera(const glm::vec3 & point);

  gdl::Clock			_clock;
  CameraManager			_camera;
  std::map<int, eventHandler>	_events;
};

#endif				/* _GAMEEVENT_HH__ */
