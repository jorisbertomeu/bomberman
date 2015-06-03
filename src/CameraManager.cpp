//
// CameraManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:05:59 2015 Joris Bertomeu
// Last update Wed Jun  3 18:03:09 2015 Geoffrey Merran
//

#include	<CameraManager.hh>
#include	<iostream>

CameraManager::CameraManager()
{
  this->_renderManager = NULL;
}

CameraManager::~CameraManager()
{

}

bool	CameraManager::initialize(RenderManager *rm, const glm::vec2 &windowSize)
{
  this->_renderManager = rm;
  this->_projection = glm::perspective(60.0f, static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y), 0.1f, 1000.0f);
  std::cout << "Camera Initialized" << std::endl;
  this->moveTo(glm::vec3(0, 600, 800));
  return (true);
}

bool	CameraManager::moveTo(const glm::vec3 &pos)
{
  this->_transformation = glm::lookAt(pos, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  this->_renderManager->getGraphicManager().getContext().getShaders().bind();
  this->_renderManager->getGraphicManager().getContext().getShaders().setUniform("view", this->_transformation);
  this->_renderManager->getGraphicManager().getContext().getShaders().setUniform("projection", this->_projection);
  return (true);
}

