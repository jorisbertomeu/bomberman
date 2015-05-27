//
// AEntity.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:06:53 2015 parallels
// Last update Sat Jun  6 15:52:32 2015 Geoffrey Merran
//

#include <AEntity.hh>

AEntity::AEntity(glm::vec3 pos, EntityType type) : _pos(pos), _modelId(""), _type(type)
{
  this->_rotation = glm::vec3(0, 0, 0);
  this->_scale = glm::vec3(1, 1, 1);
}

AEntity::~AEntity()
{

}

glm::vec3		AEntity::getPos() const
{
  return (this->_pos);
}

AEntity::EntityType	AEntity::getType() const
{
  return (this->_type);
}

void			AEntity::setPos(const glm::vec3 & pos)
{
  this->_pos = pos;
}

void			AEntity::setScale(const glm::vec3 & scale)
{
  this->_scale = scale;
}

// void			AEntity::translate(const glm::vec3 &v)
// {
//   this->_pos += v;
// }

glm::mat4	       	AEntity::getTransformation()
{
  glm::mat4		transform(1);

  transform = glm::translate(transform, this->_pos);
  transform = glm::rotate(transform, this->_rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, this->_rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, this->_rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, this->_scale);
  return (transform);
}

void			AEntity::setModelId(const std::string &model)
{
  this->_modelId = model;
}

std::string	       	AEntity::getModelId() const
{
  return (this->_modelId);
}
