//
// InputManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:09:39 2015 Joris Bertomeu
// Last update Fri May 29 16:22:26 2015 mari_f
//

#include	<InputManager.hh>

InputManager::InputManager()
{
  gdl::Input();
}

InputManager::~InputManager()
{

}

void		InputManager::DetectKey(gdl::Input &input)
{
  if (input.getKey(SDLK_UP))
    this->up();
  else if (input.getKey(SDLK_DOWN))
    this->down();
  else if (input.getKey(SDLK_RIGHT))
    this->right();
  else if (input.getKey(SDLK_LEFT))
    this->left();
}

void		InputManager::up()
{
  std::cout << "Up" << std::endl;
}

void		InputManager::down()
{
  std::cout << "down" << std::endl;
}

void		InputManager::right()
{
  std::cout << "right" << std::endl;
}

void		InputManager::left()
{
  std::cout << "left" << std::endl;
}

void		InputManager::jump()
{

}
