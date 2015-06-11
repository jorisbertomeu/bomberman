//
// HitBox.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Tue May 26 12:39:55 2015 Nicolas Adès
// Last update Tue Jun  9 22:33:46 2015 Joris Bertomeu
//

#include <HitBox.hh>
#include <AEntity.hh>
#include <Floor.hh>
#include <Scene.hh>

Hitbox::Hitbox(void *entityp)
{
  updateHitbox(entityp);
}

Hitbox::~Hitbox()
{

}

void	Hitbox::updateHitbox(void *entityp)
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
  else if (type == AEntity::PAVEMENT)
    {
      this->_c1 = glm::vec3(pos.x + pos.x * dynamic_cast<Pavement*>(entity)->getScale().x / 2,
			    pos.y + pos.y * dynamic_cast<Pavement*>(entity)->getScale().y / 2,
			    pos.z + pos.z * dynamic_cast<Pavement*>(entity)->getScale().z / 2);
      this->_c2 = glm::vec3(this->_c1.x + dynamic_cast<Pavement*>(entity)->getWidth(),
			    this->_c1.y, this->_c1.z);
      this->_c3 = glm::vec3(this->_c1.x + dynamic_cast<Pavement*>(entity)->getWidth(),
			    this->_c1.y, this->_c1.z - dynamic_cast<Pavement*>(entity)->getDepth());
      this->_c4 = glm::vec3(this->_c1.x + dynamic_cast<Pavement*>(entity)->getWidth(),
			    this->_c1.y + dynamic_cast<Pavement*>(entity)->getHeigth(),
			    this->_c1.z - dynamic_cast<Pavement*>(entity)->getDepth());
      this->_c5 = glm::vec3(this->_c1.x, this->_c1.y + dynamic_cast<Pavement*>(entity)->getHeigth(),
			    this->_c1.z - dynamic_cast<Pavement*>(entity)->getDepth());
      this->_c6 = glm::vec3(this->_c1.x, this->_c1.y, this->_c1.z - dynamic_cast<Pavement*>(entity)->getDepth());
      this->_c7 = glm::vec3(this->_c1.x, this->_c1.y + dynamic_cast<Pavement*>(entity)->getHeigth(), this->_c1.z);
      this->_c8 = glm::vec3(this->_c1.x + dynamic_cast<Pavement*>(entity)->getWidth(),
			    this->_c1.y + dynamic_cast<Pavement*>(entity)->getHeigth(), this->_c1.z);
    }
}

bool	Hitbox::checkCollision(void *scenep)
{
  Scene *scene = (Scene*) scenep;

  std::list<AEntity*> list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end(); it++) {
    if ((*it)->getType() != AEntity::WOODWALL && (*it)->getType() != AEntity::BRICKWALL)
      continue;
    if ((*it)->getHitbox()->_c1.x >= this->_c6.x &&
	(*it)->getHitbox()->_c1.x <= this->_c8.x &&
	(*it)->getHitbox()->_c1.y >= this->_c6.y &&
	(*it)->getHitbox()->_c1.y <= this->_c8.y &&
	(*it)->getHitbox()->_c1.z >= this->_c6.z &&
	(*it)->getHitbox()->_c1.z <= this->_c8.z) {
      return (true);
    } else if ((*it)->getHitbox()->_c1.x >= this->_c6.x &&
	(*it)->getHitbox()->_c2.x <= this->_c8.x &&
	(*it)->getHitbox()->_c2.y >= this->_c6.y &&
	(*it)->getHitbox()->_c2.y <= this->_c8.y &&
	(*it)->getHitbox()->_c2.z >= this->_c6.z &&
	(*it)->getHitbox()->_c2.z <= this->_c8.z) {
      return (true);
    } else if ((*it)->getHitbox()->_c1.x >= this->_c6.x &&
	(*it)->getHitbox()->_c3.x <= this->_c8.x &&
	(*it)->getHitbox()->_c3.y >= this->_c6.y &&
	(*it)->getHitbox()->_c3.y <= this->_c8.y &&
	(*it)->getHitbox()->_c3.z >= this->_c6.z &&
	(*it)->getHitbox()->_c3.z <= this->_c8.z) {
      return (true);
    } else if ((*it)->getHitbox()->_c1.x >= this->_c6.x &&
	(*it)->getHitbox()->_c4.x <= this->_c8.x &&
	(*it)->getHitbox()->_c4.y >= this->_c6.y &&
	(*it)->getHitbox()->_c4.y <= this->_c8.y &&
	(*it)->getHitbox()->_c4.z >= this->_c6.z &&
	(*it)->getHitbox()->_c4.z <= this->_c8.z) {
      return (true);
    } else if ((*it)->getHitbox()->_c1.x >= this->_c6.x &&
	(*it)->getHitbox()->_c5.x <= this->_c8.x &&
	(*it)->getHitbox()->_c5.y >= this->_c6.y &&
	(*it)->getHitbox()->_c5.y <= this->_c8.y &&
	(*it)->getHitbox()->_c5.z >= this->_c6.z &&
	(*it)->getHitbox()->_c5.z <= this->_c8.z) {
      return (true);
    } else if ((*it)->getHitbox()->_c1.x >= this->_c6.x &&
	(*it)->getHitbox()->_c6.x <= this->_c8.x &&
	(*it)->getHitbox()->_c6.y >= this->_c6.y &&
	(*it)->getHitbox()->_c6.y <= this->_c8.y &&
	(*it)->getHitbox()->_c6.z >= this->_c6.z &&
	(*it)->getHitbox()->_c6.z <= this->_c8.z) {
      return (true);
    } else if ((*it)->getHitbox()->_c1.x >= this->_c6.x &&
	(*it)->getHitbox()->_c7.x <= this->_c8.x &&
	(*it)->getHitbox()->_c7.y >= this->_c6.y &&
	(*it)->getHitbox()->_c7.y <= this->_c8.y &&
	(*it)->getHitbox()->_c7.z >= this->_c6.z &&
	(*it)->getHitbox()->_c7.z <= this->_c8.z) {
      return (true);
    } else if ((*it)->getHitbox()->_c1.x >= this->_c6.x &&
	(*it)->getHitbox()->_c8.x <= this->_c8.x &&
	(*it)->getHitbox()->_c8.y >= this->_c6.y &&
	(*it)->getHitbox()->_c8.y <= this->_c8.y &&
	(*it)->getHitbox()->_c8.z >= this->_c6.z &&
	(*it)->getHitbox()->_c8.z <= this->_c8.z) {
      return (true);
    } else {
      continue;
    }
  }
  return (false);
}
