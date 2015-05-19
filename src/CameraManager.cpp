//
// CameraManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:05:59 2015 Joris Bertomeu
// Last update Tue May 19 13:19:42 2015 Joris Bertomeu
//

#include	<CameraManager.hh>

CameraManager::CameraManager(RenderManager *renderManager)
{
  this->_renderManager = renderManager;
}

CameraManager::~CameraManager()
{

}

bool	CameraManager::moveTo(const glm::vec3 &pos) const
{

}

