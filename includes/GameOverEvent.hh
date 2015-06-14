//
// GameOverEvent.hh for Bomberman in /home/polizz_v/rendu/CPP/git/bomberman
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Sun Jun 14 18:15:15 2015 Valérian Polizzi
// Last update Sun Jun 14 19:03:58 2015 Valérian Polizzi
//

#ifndef _GAMEOVEREVENT_HH_
# define _GAMEOVEREVENT_HH_

# include <IEvent.hh>
# include <map>
# include <SDL_keycode.h>

class GameOverEvent : public IEvent
{
public:
  typedef void (GameOverEvent::*eventHandler)(SceneManager*);

  GameOverEvent();
  virtual                       ~GameOverEvent();
  virtual bool                  isCatch(gdl::Input &input, gdl::Clock&, SceneManager*, CameraManager&);

private:
  void                          resetKeyCatch();
  void                          space(SceneManager*);

  float                         _nextKeyCatch;
  std::map<int, eventHandler>   _events;
};

#endif
