//
// MenuEvent.hh for  in /home/merran_g/work/rendu/bomberman
//
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
//
// Started on  Fri Jun 12 04:53:07 2015 Geoffrey Merran
// Last update Wed Jun 10 02:51:34 2015 Joris Bertomeu
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
  virtual bool			isCatch(gdl::Input &input, SceneManager*, CameraManager&);

private:
  void				up(SceneManager*);
  void				down(SceneManager*);
  void				space(SceneManager*);
  std::map<int, eventHandler>	_events;
};

#endif /* __MENU_EVENT_HH */
