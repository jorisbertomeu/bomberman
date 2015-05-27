//
// PhysicSolid.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Tue May 26 12:42:29 2015 Nicolas Adès
// Last update Tue May 26 12:46:20 2015 Nicolas Adès
//

#include <PhysicSolid.hh>

PhysicSolid::PhysicSolid()
{

}

PhysicSolid::~PhysicSolid()
{

}

glm::vec3	PhysicSolid::getAcceleration()
{
  return (this->_acceleration);
}

void		PhysicSolid::setAcceleration(const glm::vec3 & acceleration)
{
  this->_acceleration = acceleration;
}

float		PhysicSolid::getWeight()
{
  return (this->_weight);
}

void		PhysicSolid::setWeight(const float & weight)
{
  this->_weight = weight;
}
