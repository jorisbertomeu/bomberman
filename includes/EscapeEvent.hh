//
// MenuEvent.hh for  in /home/merran_g/work/rendu/bomberman
//
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
//
// Started on  Fri Jun 12 04:53:07 2015 Geoffrey Merran
// Last update Wed Jun 10 02:51:34 2015 Joris Bertomeu
//

#ifndef __ESCAPEEVENT_HH
# define __ESCAPEEVENT_HH

# include <IEvent.hh>
# include <EscapeMenu.hh>

class				EscapeEvent : public IEvent
{
public:
  typedef void (EscapeEvent::*eventHandler)(SceneManager*);

  EscapeEvent();
  virtual			~EscapeEvent();
  virtual bool			isCatch(gdl::Input &input, gdl::Clock&, SceneManager*, CameraManager&);

private:
  void				resetKeyCatch();
  void				up(SceneManager*);
  void				down(SceneManager*);
  void				space(SceneManager*);
  
  float				_nextKeyCatch;
  std::map<int, eventHandler>	_events;
};

#endif /* __ESCAPEEVENT_HH */
