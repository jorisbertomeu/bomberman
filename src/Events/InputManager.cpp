//
// InputManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:09:39 2015 Joris Bertomeu
// Last update Sat Jun 13 05:59:04 2015 Geoffrey Merran
//

#include	<InputManager.hh>

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void			InputManager::addEvent(IEvent* event)
{
  this->_events.push_back(event);
}

void			InputManager::handleEvent(gdl::Input &input, gdl::Clock &clock, SceneManager* sm, CameraManager & camera)
{
  for(std::list<IEvent *>::iterator it = this->_events.begin(); it != this->_events.end(); it++)
    {
      if ((*it)->isCatch(input, clock, sm, camera))
	return ;
    }
}

void			InputManager::removeEvents()
{
  this->_events.clear();
}
