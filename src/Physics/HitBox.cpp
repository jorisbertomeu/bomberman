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

HitBox::HitBox(AEntity *entity)
{
  this->_type = entity->getType();
  glm::vec3	pos = entity->getPos();
  
  if (this->_type == AEntity::BOMBERMAN && this->_type == AEntity::BOT)
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
  else if (this->_type == AEntity::BRICKWALL && this->_type == AEntity::WOODWALL)
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
  else if (this->_type == AEntity::BOMB)
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
      this->_c2 = glm::vec3(dynamic_cast<Floor*>(entity)->getWidth(), 0, 0 - dynamic_cast<Floor*>(entity)->getHeigth());
      this->_c3 = glm::vec3(dynamic_cast<Floor*>(entity)->getWidth(), 0, 0);
      this->_c4 = glm::vec3(dynamic_cast<Floor*>(entity)->getWidth(), 30, 0);
      this->_c5 = glm::vec3(0, 30, 0);
      this->_c6 = glm::vec3(0, 0, 0);
      this->_c7 = glm::vec3(0, 30, 0 - dynamic_cast<Floor*>(entity)->getWidth());
      this->_c8 = glm::vec3(dynamic_cast<Floor*>(entity)->getWidth(), 30, 0 - dynamic_cast<Floor*>(entity)->
			    getHeigth());
    }
}

HitBox::~HitBox()
{

}

