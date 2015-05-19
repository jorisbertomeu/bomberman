//
// CameraManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:05:59 2015 Joris Bertomeu
// Last update Tue May 19 15:10:06 2015 Joris Bertomeu
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
}

bool	CameraManager::moveTo(const glm::vec3 &pos) const
{

}

