//
// RenderManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 14:23:22 2015 Joris Bertomeu
// Last update Mon May 25 17:22:45 2015 Geoffrey Merran
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
  this->_graphicManager.initialize(windowSize, name);
}

bool	RenderManager::start()
{

}

bool	RenderManager::update()
{

}

void	RenderManager::draw(AScene *scene)
{

}

void	RenderManager::stop()
{
  this->_graphicManager.stop();
}
