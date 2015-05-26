//
// CameraManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:05:59 2015 Joris Bertomeu
// Last update Tue May 26 17:50:04 2015 Geoffrey Merran
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

bool	CameraManager::initialize(RenderManager *rm)
{
  this->_renderManager = rm;
  std::cout << "Camera Initialized" << std::endl;
  return (true);
}

bool	CameraManager::moveTo(const glm::vec3 &pos) const
{
  (void) pos;
  return (true);
}

