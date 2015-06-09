//
// HitBox.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Tue May 26 12:39:55 2015 Nicolas Adès
// Last update Tue Jun  9 16:34:38 2015 Joris Bertomeu
//

#include <HitBox.hh>
#include <AEntity.hh>
#include <Floor.hh>

Hitbox::Hitbox(void *entityp)
{
  AEntity *entity = (AEntity *)entityp;
  AEntity::EntityType type = entity->getType();
  glm::vec3	pos = entity->getPos();
  printf("HITBOX\n");
  if (type == AEntity::BOMBERMAN || type == AEntity::BOT)
    {
      this->_c1 = glm::vec3(pos.x, pos.y, pos.z);
      this->_c2 = glm::vec3(40 + pos.x, pos.y, pos.z);
      this->_c3 = glm::vec3(40 + pos.x, pos.y, 10 + pos.z);
      this->_c4 = glm::vec3(40 + pos.x, 20 + pos.y, 10 + pos.z);
      this->_c5 = glm::vec3(pos.x, 20 + pos.y, 10 + pos.z);
      this->_c6 = glm::vec3(pos.x, pos.y, 10 + pos.z);
      this->_c7 = glm::vec3(pos.x, 20 + pos.y, pos.z);
      this->_c8 = glm::vec3(40 + pos.x, 10 + pos.y, pos.z);
    }
  else if (type == AEntity::BRICKWALL || type == AEntity::WOODWALL)
    {
      this->_c1 = glm::vec3(pos.x, pos.y, pos.z);
      this->_c2 = glm::vec3(60 + pos.x, pos.y, pos.z);
      this->_c3 = glm::vec3(60 + pos.x, pos.y, 30 + pos.z);
      this->_c4 = glm::vec3(60 + pos.x, 40 + pos.y, 30 + pos.z);
      this->_c5 = glm::vec3(pos.x, 40 + pos.y, 30 + pos.z);
      this->_c6 = glm::vec3(pos.x, pos.y, 30 + pos.z);
      this->_c7 = glm::vec3(pos.x, 40 + pos.y, pos.z);
      this->_c8 = glm::vec3(60 + pos.x, 30 + pos.y, pos.z);
    }
  else if (type == AEntity::BOMB)
    {
      this->_c1 = glm::vec3(pos.x, pos.y, pos.z);
      this->_c2 = glm::vec3(40 + pos.x, pos.y, pos.z);
      this->_c3 = glm::vec3(40 + pos.x, pos.y, 10 + pos.z);
      this->_c4 = glm::vec3(40 + pos.x, 20 + pos.y, 10 + pos.z);
      this->_c5 = glm::vec3(pos.x, 20 + pos.y, 10 + pos.z);
      this->_c6 = glm::vec3(pos.x, pos.y, 10 + pos.z);
      this->_c7 = glm::vec3(pos.x, 20 + pos.y, pos.z);
      this->_c8 = glm::vec3(40 + pos.x, 10 + pos.y, pos.z);
    }
  else
    {
      this->_c1 = glm::vec3(0, 0, 0 - dynamic_cast<Floor*>(entity)->getHeigth());
      printf("HITBOX NOPE");
      this->_c2 = glm::vec3(dynamic_cast<Floor*>(entity)->getWidth(), 0, 0 - dynamic_cast<Floor*>(entity)->getHeigth());
      this->_c3 = glm::vec3(dynamic_cast<Floor*>(entity)->getWidth(), 0, 0);
      this->_c4 = glm::vec3(dynamic_cast<Floor*>(entity)->getWidth(), 30, 0);
      this->_c5 = glm::vec3(0, 30, 0);
      this->_c6 = glm::vec3(0, 0, 0);
      this->_c7 = glm::vec3(0, 30, 0 - dynamic_cast<Floor*>(entity)->getWidth());
      this->_c8 = glm::vec3(dynamic_cast<Floor*>(entity)->getWidth(), 30, 0 - dynamic_cast<Floor*>(entity)->getHeigth());
    }
}

Hitbox::~Hitbox()
{

}

