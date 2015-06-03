//
// RenderManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 14:23:22 2015 Joris Bertomeu
// Last update Thu Jun  4 00:16:42 2015 Geoffrey Merran
//

#include <RenderManager.hh>

RenderManager::RenderManager()
{

}

RenderManager::~RenderManager()
{

}

bool			RenderManager::initialize(const glm::vec2 &windowSize, const std::string &name)
{
  if (!this->_graphicManager.initialize(windowSize, name))
    return (false);
  return (true);
}

void			RenderManager::delay()
{
  this->_timeManager.delay();
}

bool			RenderManager::update()
{
  this->_graphicManager.getContext().getSdlContext().updateClock(this->_timeManager.getClock());
  return (true);
}

void			RenderManager::draw(Scene *scene)
{
  this->_graphicManager.getContext().getShaders().bind();
  scene->draw(*this);
  this->_graphicManager.flush();
}

void			RenderManager::stop()
{
  this->_graphicManager.stop();
}

GraphicManager&		RenderManager::getGraphicManager()
{
  return (this->_graphicManager);
}

ModelManager&		RenderManager::getModelManager()
{
  return (this->_modelManager);
}

TimeManager&		RenderManager::getTimeManager()
{
  return (this->_timeManager);
}
