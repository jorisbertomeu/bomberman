//
// AEntity.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:06:53 2015 parallels
// Last update Tue Jun  9 16:32:43 2015 Joris Bertomeu
//

#include <AEntity.hh>
#include <Bomberman.hh>

AEntity::AEntity(glm::vec3 pos, EntityType type) : _pos(pos), _modelId(""), _type(type)
{
  this->_rotation = glm::vec3(0, 0, 0);
  this->_scale = glm::vec3(1, 1, 1);
  printf("Type = %d\n", type);
  if (type != AEntity::PAVEMENT)
    this->_hitbox = new Hitbox(this);
}

AEntity::AEntity(glm::vec3 pos, EntityType type, bool custom) : _pos(pos), _modelId(""), _type(type)
{
  this->_rotation = glm::vec3(0, 0, 0);
  this->_scale = glm::vec3(1, 1, 1);
  if (!custom)
    this->_hitbox = new Hitbox(this);
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

glm::vec3		AEntity::getScale()
{
  return (this->_scale);
}

void			AEntity::translate(const glm::vec3 & v)
{
  this->_pos += v;
}

void			AEntity::rotate(const glm::vec3 & axis, const float & angle)
{
  this->_rotation += axis * angle;
}

void			AEntity::scale(const glm::vec3 & scale)
{
  this->_scale *= scale;
}

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

void			AEntity::save(std::fstream &fs)
{
  fs << "    <entity>" << std::endl;
  fs << "      <attribut>" << std::endl;
  fs << "        <speed>" << this->getSpeed() << "</speed>" << std::endl;
  fs << "        <jump>" << this->getJump() << "</jump>" << std::endl;
  fs << "        <weight>" << this->getWeight() << "</weight>" << std::endl;
  fs << "        <friction>" << this->getFriction() << "</friction>" << std::endl;
  fs << "        <move>" << this->getMove() << "</move>" << std::endl;
  fs << "        <ability>NONE</ability>" << std::endl;
  fs << "        <range>" << this->getRange() << "</range>" << std::endl;
  fs << "        <bonus>NONE</bonus>" << std::endl;
  fs << "      </attribut>" << std::endl;
  fs << "      <health>" << this->getHealth() << "</health>" << std::endl;
  if (this->getType() == 1)
    {
      fs << "      <type>BRICK_WALL</type>" << std::endl;
      fs << "      <name>NONE</name>" << std::endl;
    }
  else if (this->getType() == 2)
    {
      fs << "      <type>BOMBERMAN</type>" << std::endl;
      fs << "      <name>" << dynamic_cast<Bomberman *>(this)->getName() << "</name>" << std::endl;
    }
  else
    {
      fs << "      <type>UNKNOWN</type>" << std::endl;
      fs << "      <name>NONE</name>" << std::endl;
    }
  fs << "      <model>" << this->getModelId() << "</model>" << std::endl;
  fs << "      <texture>" << this->getTexture() << "</texture>" << std::endl;
  fs << "      <position>" << std::endl;
  fs << "        <x>" << this->getPos().x << "</x>" << std::endl;
  fs << "        <y>" << this->getPos().y << "</y>" << std::endl;
  fs << "        <z>" << this->getPos().z << "</z>" << std::endl;
  fs << "      </position>" << std::endl;
  fs << "      <size>" << std::endl;
  fs << "        <x>" << this->getScale().x << "</x>" << std::endl;
  fs << "        <y>" << this->getScale().y << "</y>" << std::endl;
  fs << "        <z>" << this->getScale().z << "</z>" << std::endl;
  fs << "      </size>" << std::endl;
  fs << "    </entity>" << std::endl;
}
