//
// HitBox.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Tue May 26 12:39:55 2015 Nicolas Adès
// Last update Tue Jun  9 19:04:53 2015 Joris Bertomeu
//

#include <HitBox.hh>
#include <AEntity.hh>
#include <Floor.hh>
#include <Scene.hh>

Hitbox::Hitbox(void *entityp)
{
  AEntity *entity = (AEntity *)entityp;
  AEntity::EntityType type = entity->getType();
  glm::vec3	pos = entity->getPos();
  if (type == AEntity::BOMBERMAN || type == AEntity::BOT)
    {
      this->_c1 = glm::vec3(pos.x, pos.y, pos.z);
      this->_c2 = glm::vec3(60 + pos.x, pos.y, pos.z);
      this->_c3 = glm::vec3(60 + pos.x, pos.y, pos.z - 60);
      this->_c4 = glm::vec3(60 + pos.x, 80 + pos.y, pos.z - 60);
      this->_c5 = glm::vec3(pos.x, 80 + pos.y, pos.z - 60);
      this->_c6 = glm::vec3(pos.x, pos.y, pos.z - 60);
      this->_c7 = glm::vec3(pos.x, 80 + pos.y, pos.z);
      this->_c8 = glm::vec3(60 + pos.x, 80 + pos.y, pos.z);
    }
  else if (type == AEntity::BRICKWALL || type == AEntity::WOODWALL)
    {
      this->_c1 = glm::vec3(pos.x, pos.y, pos.z);
      this->_c2 = glm::vec3(60 + pos.x, pos.y, pos.z);
      this->_c3 = glm::vec3(60 + pos.x, pos.y, pos.z - 60);
      this->_c4 = glm::vec3(60 + pos.x, 60 + pos.y, pos.z - 60);
      this->_c5 = glm::vec3(pos.x, 60 + pos.y, pos.z - 60);
      this->_c6 = glm::vec3(pos.x, pos.y, pos.z - 60);
      this->_c7 = glm::vec3(pos.x, 60 + pos.y, pos.z);
      this->_c8 = glm::vec3(60 + pos.x, 60 + pos.y, pos.z);
    }
  else if (type == AEntity::BOMB)
    {
      this->_c1 = glm::vec3(pos.x, pos.y, pos.z);
      this->_c2 = glm::vec3(60 + pos.x, pos.y, pos.z);
      this->_c3 = glm::vec3(60 + pos.x, pos.y, pos.z - 60);
      this->_c4 = glm::vec3(60 + pos.x, 60 + pos.y, pos.z - 60);
      this->_c5 = glm::vec3(pos.x, 60 + pos.y, pos.z - 60);
      this->_c6 = glm::vec3(pos.x, pos.y, pos.z - 60);
      this->_c7 = glm::vec3(pos.x, 60 + pos.y, pos.z);
      this->_c8 = glm::vec3(60 + pos.x, 60 + pos.y, pos.z);
    }
  else
    {
      printf("Entiti : %d\n", type);
      return;
      this->_c1 = glm::vec3(0, 0, 0 - dynamic_cast<Floor*>(entity)->getHeigth());
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

bool	Hitbox::checkCollision(void *scenep)
{
  Scene *scene = (Scene*) scenep;

  for (std::list<AEntity *>::iterator it = scene->getEntities().begin(); it != scene->getEntities().end(); ++it) {
    if (this->_c1.x >= (*it)->getHitbox()->_c2.x || this->_c2.x <= (*it)->getHitbox()->_c1.x || this->_c1.z >= (*it)->getHitbox()->_c2.z || this->_c6.z <= (*it)->getHitbox()->_c1.z)
      continue;
  }
}
