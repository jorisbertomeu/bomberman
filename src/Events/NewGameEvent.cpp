//
// NewGameEvent.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 01:34:22 2015 Geoffrey Merran
// Last update Sat Jun 13 04:03:31 2015 Geoffrey Merran
//

#include <NewGameEvent.hh>

NewGameEvent::NewGameEvent() : _nextKeyCatch(0.2)
{
  this->_events[SDLK_SPACE] = &NewGameEvent::space;
  this->_events[SDLK_RIGHT] = &NewGameEvent::right;
  this->_events[SDLK_LEFT] = &NewGameEvent::left;
  this->_events[SDLK_ESCAPE] = &NewGameEvent::escape;
}

NewGameEvent::~NewGameEvent()
{

}

bool				NewGameEvent::isCatch(gdl::Input &input, gdl::Clock& clock, SceneManager* sm, CameraManager& cm)
{
  (void) cm;
  if (this->_nextKeyCatch > 0.0f)
    {
      this->_nextKeyCatch -= clock.getElapsed();
      return (false);
    }
  for (std::map<int, NewGameEvent::eventHandler>::iterator found = this->_events.begin(); found != this->_events.end(); found++)
    {
      if (input.getKey((*found).first))
	{
	  (this->*this->_events[(*found).first])(sm);
	  this->resetKeyCatch();
	  return (true);
	}
    }
  return (false);
}

void				NewGameEvent::resetKeyCatch()
{
  this->_nextKeyCatch = 0.2;
}

void				NewGameEvent::right(SceneManager* sm)
{
  dynamic_cast<NewGameMenu*>(sm->getCurrentScene())->moveNextMap();
}

void				NewGameEvent::left(SceneManager* sm)
{
  dynamic_cast<NewGameMenu*>(sm->getCurrentScene())->movePrevMap();
}

void				NewGameEvent::space(SceneManager* sm)
{
  dynamic_cast<NewGameMenu*>(sm->getCurrentScene())->selectMap(sm);
}

void				NewGameEvent::escape(SceneManager* sm)
{
  dynamic_cast<NewGameMenu*>(sm->getCurrentScene())->back(sm);
}
