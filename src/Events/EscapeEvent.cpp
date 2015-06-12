//
// MenuEvent.cpp for  in /home/merran_g/work/rendu/bomberman
//
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
//
// Started on  Fri Jun 12 04:55:54 2015 Geoffrey Merran
// Last update Wed Jun 10 09:22:54 2015 Joris Bertomeu
//

#include <EscapeEvent.hh>

EscapeEvent::EscapeEvent()
{
  this->_events[SDLK_UP] = &EscapeEvent::up;
  this->_events[SDLK_DOWN] = &EscapeEvent::down;
  this->_events[SDLK_SPACE] = &EscapeEvent::space;
}

EscapeEvent::~EscapeEvent()
{

}

bool			EscapeEvent::isCatch(gdl::Input &input, gdl::Clock& clock, SceneManager* sm, CameraManager& cm)
{
  Scene			*scene = sm->getCurrentScene();

  (void) cm;
  if (this->_nextKeyCatch > 0.0f)
    {
      this->_nextKeyCatch -= clock.getElapsed();
      return (false);
    }
  for (std::map<int, EscapeEvent::eventHandler>::iterator found = this->_events.begin(); found != this->_events.end(); found++)
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

void			EscapeEvent::resetKeyCatch()
{
  this->_nextKeyCatch = 0.35;
}

void			EscapeEvent::up(SceneManager* sm)
{
}

void			EscapeEvent::down(SceneManager* sm)
{
  dynamic_cast<EscapeMenu*>(sm->getCurrentScene())->moveCursor();
}

void			EscapeEvent::space(SceneManager* sm)
{
  dynamic_cast<EscapeMenu*>(sm->getCurrentScene())->selectButton(sm);
}
