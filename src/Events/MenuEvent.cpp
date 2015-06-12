//
// MenuEvent.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Fri Jun 12 04:55:54 2015 Geoffrey Merran
// Last update Fri Jun 12 05:20:19 2015 Geoffrey Merran
//

#include <MenuEvent.hh>

MenuEvent::MenuEvent()
{
  this->_events[SDLK_UP] = &MenuEvent::up;
  this->_events[SDLK_DOWN] = &MenuEvent::down;
}

MenuEvent::~MenuEvent()
{

}

bool			MenuEvent::isCatch(gdl::Input &input, Scene* scene, CameraManager& cm)
{
  (void) cm;
  for (std::map<int, MenuEvent::eventHandler>::iterator found = this->_events.begin(); found != this->_events.end(); found++)
    {
      if (input.getKey((*found).first))
	{
	  (this->*this->_events[(*found).first])(scene);
	  return (true);
	}
    }
  return (false);
}

void			MenuEvent::up(Scene* scene)
{
}

void			MenuEvent::down(Scene* scene)
{
  dynamic_cast<MainMenu*>(scene)->moveCursor();
}
