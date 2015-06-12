//
// MenuEvent.hh for  in /home/merran_g/work/rendu/bomberman
//
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
//
// Started on  Fri Jun 12 04:53:07 2015 Geoffrey Merran
// Last update Fri Jun 12 20:58:49 2015 Geoffrey Merran
//

#ifndef __MENU_EVENT_HH
# define __MENU_EVENT_HH

# include <IEvent.hh>
# include <MainMenu.hh>

class				MenuEvent : public IEvent
{
public:
  typedef void (MenuEvent::*eventHandler)(SceneManager*);

  MenuEvent();
  virtual			~MenuEvent();
  virtual bool			isCatch(gdl::Input &input, gdl::Clock&, SceneManager*, CameraManager&);

private:
  void				resetKeyCatch();
  void				up(SceneManager*);
  void				down(SceneManager*);
  void				space(SceneManager*);

  float				_nextKeyCatch;
  std::map<int, eventHandler>	_events;
};

#endif /* __MENU_EVENT_HH */
