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
  this->_acceleration = 0;
}

PhysicSolid::~PhysicSolid()
{

}

float	PhysicSolid::getAcceleration()
{
  return (this->_acceleration);
}

void		PhysicSolid::setAcceleration(const float & acceleration)
{
  this->_acceleration = acceleration;
  if (this->_acceleration >= 1.5)
    this->_acceleration = 1.5;
}

float		PhysicSolid::getWeight()
{
  return (this->_weight);
}

void		PhysicSolid::setWeight(const float & weight)
{
  this->_weight = weight;
}
