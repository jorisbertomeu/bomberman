//
// RenderManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 14:23:22 2015 Joris Bertomeu
// Last update Mon Jun  1 16:54:19 2015 Geoffrey Merran
//

#include <RenderManager.hh>

RenderManager::RenderManager()
{

}

RenderManager::~RenderManager()
{

}

bool	RenderManager::initialize(const glm::vec2 &windowSize, const std::string &name)
{
  if (!this->_graphicManager.initialize(windowSize, name))
    return (false);
  return (true);
}

bool	RenderManager::start()
{
  return (true);
}

bool	RenderManager::update()
{
  return (true);
}

void	RenderManager::draw(AScene *scene)
{
  scene->draw();
}

void	RenderManager::stop()
{
  this->_graphicManager.stop();
}
