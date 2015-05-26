//
// AEntity.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Mon May 25 14:06:53 2015 parallels
// Last update Tue May 26 12:09:51 2015 Nicolas Adès
//

#include <AEntity.hh>

AEntity::AEntity()
{

}

AEntity::~AEntity()
{

}

glm::vec3	AEntity::getPos()
{
  return (this->_pos);
}

AEntity::EntityType	AEntity::getType()
{
  return (this->_type);
}

void		AEntity::setPos(const glm::vec3 & pos)
{
  this->_pos = pos;
}
