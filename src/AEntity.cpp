//
// AEntity.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Mon May 25 14:06:53 2015 parallels
// Last update Wed Jun  3 12:03:05 2015 Geoffrey Merran
//

#include <AEntity.hh>

AEntity::AEntity(glm::vec3 pos, EntityType type, const std::string & path)
{
  this->_pos = pos;
  this->_type = type;
  this->_modelPath = path;
}

AEntity::~AEntity()
{

}

glm::vec3	AEntity::getPos() const
{
  return (this->_pos);
}

AEntity::EntityType	AEntity::getType() const
{
  return (this->_type);
}

void		AEntity::setPos(const glm::vec3 & pos)
{
  this->_pos = pos;
}

void		AEntity::draw()
{

}

std::string     AEntity::getModelPath() const
{
  return (this->_modelPath);
}

void		AEntity::setModelPath(const std::string & path)
{
  this->_modelPath = path;
}
