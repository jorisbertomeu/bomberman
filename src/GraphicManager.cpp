//
// GraphicManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 14:36:01 2015 Joris Bertomeu
// Last update Mon May 25 17:22:40 2015 Geoffrey Merran
//

#include	<GraphicManager.hh>
#include	<iostream>

GraphicManager::GraphicManager()
{

}

GraphicManager::~GraphicManager()
{

}

bool	GraphicManager::initialize(const glm::vec2 &windowSize, const std::string &name)
{
  std::cout << "Initialisation GraphicManager <" << windowSize.x << ", " << windowSize.y << "> with Title " << name << std::endl;
  if (!this->_context.getSdlContext().start(windowSize.x, windowSize.y, name))
    throw(std::logic_error("Sdl Context Error: initialization"));
  glEnable(GL_DEPTH_TEST);
  return (true);
}

void  	GraphicManager::stop()
{
  this->_context.getSdlContext().stop();
}
