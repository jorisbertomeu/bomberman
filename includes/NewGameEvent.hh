//
// NewGameEvent.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 01:30:57 2015 Geoffrey Merran
// Last update Sat Jun 13 02:23:03 2015 Geoffrey Merran
//

#ifndef __NEW_GAME_EVENT_HH
# define __NEW_GAME_EVENT_HH

# include <IEvent.hh>
# include <NewGameMenu.hh>

class					NewGameEvent : public IEvent
{
public:
  typedef void (NewGameEvent::*eventHandler)(SceneManager*);

  NewGameEvent();
  virtual			~NewGameEvent();
  virtual bool			isCatch(gdl::Input &input, gdl::Clock&, SceneManager*, CameraManager&);

private:
  void				resetKeyCatch();
  void				right(SceneManager*);
  void				left(SceneManager*);
  void				space(SceneManager*);
  void				escape(SceneManager*);

  float				_nextKeyCatch;
  std::map<int, eventHandler>	_events;
};

#endif /* __NEW_GAME_EVENT_HH */
