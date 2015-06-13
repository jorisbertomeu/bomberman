//
// LoadingEvent.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 23:40:01 2015 Geoffrey Merran
// Last update Sat Jun 13 23:56:24 2015 Geoffrey Merran
//

#ifndef __LOADING_EVENT_H
# define __LOADING_EVENT_H

class				LoadingEvent;

# include <IEvent.hh>
# include <LoadingScene.hh>

class				LoadingEvent : public IEvent
{
public:
  LoadingEvent();
  virtual			~LoadingEvent();
  virtual bool			isCatch(gdl::Input &input, gdl::Clock&, SceneManager*, CameraManager&);
};


#endif /* __LOADING_EVENT_H */
