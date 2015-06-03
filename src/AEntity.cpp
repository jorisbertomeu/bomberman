//
// AEntity.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Mon May 25 14:06:53 2015 parallels
// Last update Wed Jun  3 16:06:15 2015 Geoffrey Merran
//

#include <AEntity.hh>

AEntity::AEntity(glm::vec3 pos, EntityType type)
{
  this->_pos = pos;
  this->_type = type;
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

void			AEntity::draw(const RenderManager & rm)
{
  (void) rm;
}

glm::mat4	       	AEntity::getTransformation()
{
  glm::mat4		transform(1);

  transform = glm::rotate(transform, this->_rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, this->_rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, this->_rotation.z, glm::vec3(0, 0, 1));
  transform = glm::translate(transform, this->_pos);
  transform = glm::scale(transform, this->_scale);
  return (transform);
}
