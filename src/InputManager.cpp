//
// InputManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:09:39 2015 Joris Bertomeu
// Last update Mon Jun  1 12:50:03 2015 mari_f
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
  //translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()));
}

void		InputManager::down()
{
  //translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()));
  std::cout << "down" << std::endl;
}

void		InputManager::right()
{
  //translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()));
  std::cout << "right" << std::endl;
}

void		InputManager::left()
{
  //translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()));
  std::cout << "left" << std::endl;
}

void		InputManager::jump()
{

}
