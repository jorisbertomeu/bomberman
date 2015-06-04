//
// InputManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:09:39 2015 Joris Bertomeu
// Last update Thu Jun  4 12:06:34 2015 mari_f
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

void			InputManager::handleEvent(gdl::Input &input)
{
  for(std::list<IEvent *>::iterator it = this->_events.begin(); it != this->_events.end(); it++)
    {
      (*it)->isCatch(input);
    }
}

// void		InputManager::DetectKey(gdl::Input &input)
// {
//   if (input.getKey(SDLK_UP))
//     this->up();
//   else if (input.getKey(SDLK_DOWN))
//     this->down();
//   else if (input.getKey(SDLK_RIGHT))
//     this->right();
//   else if (input.getKey(SDLK_LEFT))
//     this->left();
// }
