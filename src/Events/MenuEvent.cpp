//
// MenuEvent.cpp for  in /home/merran_g/work/rendu/bomberman
//
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
//
// Started on  Fri Jun 12 04:55:54 2015 Geoffrey Merran
// Last update Sun Jun 14 18:44:53 2015 Valérian Polizzi
//

#include <MenuEvent.hh>

MenuEvent::MenuEvent() : _nextKeyCatch(0.2f)
{
  this->_events[SDLK_UP] = &MenuEvent::up;
  this->_events[SDLK_DOWN] = &MenuEvent::down;
  this->_events[SDLK_SPACE] = &MenuEvent::space;
}

MenuEvent::~MenuEvent()
{

}

bool			MenuEvent::isCatch(gdl::Input &input, gdl::Clock &clock, SceneManager* sm, CameraManager& cm)
{
  (void) cm;
  if (this->_nextKeyCatch > 0.0f)
    {
      this->_nextKeyCatch -= clock.getElapsed();
      return (false);
    }
  for (std::map<int, MenuEvent::eventHandler>::iterator found = this->_events.begin(); found != this->_events.end(); found++)
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

void			MenuEvent::resetKeyCatch()
{
  this->_nextKeyCatch = 0.2;
}

void			MenuEvent::up(SceneManager* sm)
{
  dynamic_cast<MainMenu*>(sm->getCurrentScene())->moveCursorUp();
}

void			MenuEvent::down(SceneManager* sm)
{
  dynamic_cast<MainMenu*>(sm->getCurrentScene())->moveCursorDown();
}

void			MenuEvent::space(SceneManager* sm)
{
  dynamic_cast<MainMenu*>(sm->getCurrentScene())->selectButton(sm);
}
