//
// MenuEvent.cpp for  in /home/merran_g/work/rendu/bomberman
//
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
//
// Started on  Fri Jun 12 04:55:54 2015 Geoffrey Merran
// Last update Wed Jun 10 04:49:00 2015 Joris Bertomeu
//

#include <MenuEvent.hh>

MenuEvent::MenuEvent()
{
  this->_events[SDLK_UP] = &MenuEvent::up;
  this->_events[SDLK_DOWN] = &MenuEvent::down;
  this->_events[SDLK_SPACE] = &MenuEvent::space;
}

MenuEvent::~MenuEvent()
{

}

bool			MenuEvent::isCatch(gdl::Input &input, SceneManager* sm, CameraManager& cm)
{
  Scene			*scene = sm->getCurrentScene();

  (void) cm;
  for (std::map<int, MenuEvent::eventHandler>::iterator found = this->_events.begin(); found != this->_events.end(); found++)
    {
      if (input.getKey((*found).first))
	{
	  (this->*this->_events[(*found).first])(sm);
	  return (true);
	}
    }
  return (false);
}

void			MenuEvent::up(SceneManager* sm)
{
}

void			MenuEvent::down(SceneManager* sm)
{
  dynamic_cast<MainMenu*>(sm->getCurrentScene())->moveCursor();
}

void			MenuEvent::space(SceneManager* sm)
{
  dynamic_cast<MainMenu*>(sm->getCurrentScene())->selectButton(sm);
}
