//
// GraphicManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 14:36:01 2015 Joris Bertomeu
// Last update Wed Jun  3 11:49:48 2015 Geoffrey Merran
//

#include	<GraphicManager.hh>
#include	<iostream>

GraphicManager::GraphicManager()
{

}

GraphicManager::~GraphicManager()
{

}

bool			GraphicManager::initialize(const glm::vec2 &windowSize, const std::string &name)
{
  std::cout << "Initialisation GraphicManager <" << windowSize.x << ", " << windowSize.y << "> with Title " << name << std::endl;
  if (!this->_context.getSdlContext().start(windowSize.x, windowSize.y, name))
    return (false);
  if (!this->_context.getShaders().load("./LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !this->_context.getShaders().load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER)
      || !this->_context.getShaders().build())
    return (false);
  glEnable(GL_DEPTH_TEST);
  return (true);
}

void			GraphicManager::stop()
{
  this->_context.getSdlContext().stop();
}

void			GraphicManager::flush()
{
  this->_context.getSdlContext().flush();
}

GraphicContext		GraphicManager::getContext() const
{
  return (this->_context);
}
