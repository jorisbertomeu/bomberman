//
// InputManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:09:39 2015 Joris Bertomeu
// Last update Thu Jun  4 17:22:55 2015 mari_f
//

#include	<InputManager.hh>

InputManager::InputManager()
{
  gdl::Input();
}

InputManager::~InputManager()
{

}

void			InputManager::addEvent(IEvent* event)
{
  this->_events.push_back(event);
}

void			InputManager::handleEvent(gdl::Input &input, Scene* scene)
{
  for(std::list<IEvent *>::iterator it = this->_events.begin(); it != this->_events.end(); it++)
    {
      (*it)->isCatch(input, scene);
    }
}
