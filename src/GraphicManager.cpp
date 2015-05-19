//
// GraphicManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 14:36:01 2015 Joris Bertomeu
// Last update Tue May 19 14:36:37 2015 Joris Bertomeu
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
}
