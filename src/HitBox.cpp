//
// HitBox.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Tue May 26 12:39:55 2015 Nicolas Adès
// Last update Tue May 26 12:42:03 2015 Nicolas Adès
//

#include <HitBox.hh>

HitBox::HitBox()
{

}

HitBox::~HitBox()
{

}

glm::vec3	HitBox::getDimensions()
{
  return (this->_dimension);
}

void		HitBox::setDimensions(const glm::vec3 & dimension)
{
  this->_dimension = dimension;
}
