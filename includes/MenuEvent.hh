//
// MenuEvent.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Fri Jun 12 04:53:07 2015 Geoffrey Merran
// Last update Fri Jun 12 05:15:11 2015 Geoffrey Merran
//

#ifndef __MENU_EVENT_HH
# define __MENU_EVENT_HH

# include <IEvent.hh>
# include <MainMenu.hh>

class				MenuEvent : public IEvent
{
public:
  typedef void (MenuEvent::*eventHandler)(Scene*);

  MenuEvent();
  virtual			~MenuEvent();
  virtual bool			isCatch(gdl::Input &input, Scene*, CameraManager&);

private:
  void				up(Scene*);
  void				down(Scene*);
  void				space(Scene*);

  std::map<int, eventHandler>	_events;
};

#endif /* __MENU_EVENT_HH */
