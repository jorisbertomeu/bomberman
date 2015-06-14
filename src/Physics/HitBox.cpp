//
// HitBox.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Tue May 26 12:39:55 2015 Nicolas Adès
// Last update Sun Jun 14 19:53:33 2015 Geoffrey Merran
//

#include <HitBox.hh>
#include <AEntity.hh>
#include <Floor.hh>
#include <Scene.hh>
#include <Bomb.hh>

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
      this->_c2 = glm::vec3(20 + pos.x, pos.y, pos.z);
      this->_c3 = glm::vec3(20 + pos.x, pos.y, pos.z - 20);
      this->_c4 = glm::vec3(20 + pos.x, 20 + pos.y, pos.z - 20);
      this->_c5 = glm::vec3(pos.x, 20 + pos.y, pos.z - 20);
      this->_c6 = glm::vec3(pos.x, pos.y, pos.z - 20);
      this->_c7 = glm::vec3(pos.x, 20 + pos.y, pos.z);
      this->_c8 = glm::vec3(20 + pos.x, 20 + pos.y, pos.z);
    }
  else if (type == AEntity::BRICKWALL || type == AEntity::WOODWALL || type == AEntity::FIRE)
    {
      this->_c1 = glm::vec3(pos.x, pos.y, pos.z);
      this->_c2 = glm::vec3(20 + pos.x, pos.y, pos.z);
      this->_c3 = glm::vec3(20 + pos.x, pos.y, pos.z - 20);
      this->_c4 = glm::vec3(20 + pos.x, 20 + pos.y, pos.z - 20);
      this->_c5 = glm::vec3(pos.x, 20 + pos.y, pos.z - 20);
      this->_c6 = glm::vec3(pos.x, pos.y, pos.z - 20);
      this->_c7 = glm::vec3(pos.x, 20 + pos.y, pos.z);
      this->_c8 = glm::vec3(20 + pos.x, 20 + pos.y, pos.z);
    }
  else if (type == AEntity::BOMB)
    {
      this->_c1 = glm::vec3(pos.x, pos.y, pos.z);
      this->_c2 = glm::vec3(20 + pos.x, pos.y, pos.z);
      this->_c3 = glm::vec3(20 + pos.x, pos.y, pos.z - 20);
      this->_c4 = glm::vec3(20 + pos.x, 20 + pos.y, pos.z - 20);
      this->_c5 = glm::vec3(pos.x, 20 + pos.y, pos.z - 20);
      this->_c6 = glm::vec3(pos.x, pos.y, pos.z - 20);
      this->_c7 = glm::vec3(pos.x, 20 + pos.y, pos.z);
      this->_c8 = glm::vec3(20 + pos.x, 20 + pos.y, pos.z);
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

bool	Hitbox::checkCollisionForPoint(glm::vec3 point)
{
  if (((int)point.x >= (int)this->_c6.x &&
       (int)point.x <= (int)this->_c8.x &&
       (int)point.y >= (int)this->_c6.y &&
       (int)point.y <= (int)this->_c8.y &&
       (int)point.z >= (int)this->_c6.z &&
       (int)point.z <= (int)this->_c8.z))
    return (true);
  return (false);
}

bool	Hitbox::checkCollisionForPointForEntities(void *scenep, glm::vec3 point)
{
  Scene *scene = (Scene*) scenep;

  std::list<AEntity*> list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end(); it++) {
    if ((*it)->getType() != AEntity::WOODWALL && (*it)->getType() != AEntity::BRICKWALL // && (*it)->getType() != AEntity::BOMB
	)
      continue;
    if ((*it)->getType() == AEntity::BOMB && static_cast<Bomb*>(*it)->freshBomb(this))
      continue;
    if ((*it)->getHitbox()->checkCollisionForPoint(point)) {
      std::cout << "Type collised : " << (*it)->getType() << std::endl;
      return (true);
    } else {
      continue;
    }
  }
  return (false);
}

int	Hitbox::getCollisionType(void *scenep, glm::vec3 point)
{
  Scene *scene = (Scene*) scenep;

  std::list<AEntity*> list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end(); it++)
    {
      if ((*it)->getDestroy() || (*it)->getType() == AEntity::FIRE)
	continue;
      if ((*it)->getHitbox()->checkCollisionForPoint(point))
	return ((*it)->getType());
    }
  return (AEntity::UNKNOWN);
}

bool	Hitbox::checkCollision(void *scenep)
{
  Scene *scene = (Scene*) scenep;

  std::list<AEntity*> list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end(); it++) {
    if ((*it)->getDestroy())
      continue;
    if ((*it)->getType() != AEntity::WOODWALL && (*it)->getType() != AEntity::BRICKWALL
	&& (*it)->getType() != AEntity::BOMB)
      continue;
    if ((*it)->getType() == AEntity::BOMB && static_cast<Bomb*>(*it)->freshBomb(this))
      continue;
    if (this->checkCollisionForPoint((*it)->getHitbox()->_c1)) {
      return (true);
    } else if (this->checkCollisionForPoint((*it)->getHitbox()->_c2)) {
      return (true);
    } else if (this->checkCollisionForPoint((*it)->getHitbox()->_c3)) {
      return (true);
    } else if (this->checkCollisionForPoint((*it)->getHitbox()->_c4)) {
      return (true);
    } else if (this->checkCollisionForPoint((*it)->getHitbox()->_c5)) {
      return (true);
    } else if (this->checkCollisionForPoint((*it)->getHitbox()->_c6)) {
      return (true);
    } else if (this->checkCollisionForPoint((*it)->getHitbox()->_c7)) {
      return (true);
    } else if (this->checkCollisionForPoint((*it)->getHitbox()->_c8)) {
      return (true);
    } else {
      continue;
    }
  }
  return (false);
}

bool		Hitbox::checkCollisionForLine(void *scenep, glm::vec3 start, glm::vec3 end)
{
  std::list<glm::vec2>	posList;
  Scene		*scene = (Scene *)scenep;

  posList = this->directTrajectory(glm::vec2(start.x, start.z), glm::vec2(end.x, end.z));
  for (std::list<glm::vec2>::iterator it = posList.begin(); it != posList.end(); ++it) {
    if (this->checkCollisionForPointForEntities(scenep, glm::vec3((*it).x, end.y, (*it).y)))
      return (true);
  }
  return (false);
}

std::list<glm::vec2>		Hitbox::directTrajectory(glm::vec2 start, glm::vec2 end)
{
  std::list<glm::vec2> posList;

  float		a = 0;
  int		tmp = 0;
  int		dx;
  int		dy;
  int		x;
  int		y;

  dx = abs(end.x - start.x);
  dy = abs(end.y - start.y);
  if (start.x == end.x)
    {
      if (start.y < end.y + 1)
	while (start.y != end.y + 1)
	  {
	    posList.push_back(glm::vec2(start.x, start.y));
	    start.y++;
	  }
      else
	while (start.y != end.y)
	  {
	    posList.push_back(glm::vec2(start.x, start.y));
	    start.y--;
	  }
    }
  else if (start.y == end.y)
    {
      if (start.x < end.x + 1)
	while (start.x != end.x + 1)
	  {
	    posList.push_back(glm::vec2(start.x, start.y));
	    start.x++;
	  }
      else
	while (start.x != end.x + 1)
	  {
	    posList.push_back(glm::vec2(start.x, start.y));
	    start.x--;
	  }
    }
  else
    {
      if (dx >= dy && dx != 0 && dy != 0)
	{
	  if (start.x > end.x)
	    {
	      tmp = start.x;
	      start.x = end.x;
	      end.x = tmp;

	      tmp = start.y;
	      start.y = end.y;
	      end.y = tmp;
	    }
	  a = ((float)(end.y - start.y) / (end.x - start.x));
	  for (int i = 0; i < (dx + 1); i++)
	    {
	      x = i + start.x;
	      y = start.y + (a * i);
	      posList.push_back(glm::vec2(x, y));
	    }
	}
      if (dx < dy && dy != 0 && dx != 0)
	{
	  if (start.y > end.y)
	    {
	      tmp = start.y;
	      start.y = end.y;
	      end.y = tmp;

	      tmp = start.x;
	      start.x = end.x;
	      end.x = tmp;
	    }
	  a = ((float)(end.x - start.x) / (end.y - start.y));
	  for (int i = 0; i < (dy + 1); i++)
	    {
	      x = start.x + (i * a);
	      y = i + start.y;
	      posList.push_back(glm::vec2(x, y));
	    }
	}
      if (dx == 0)
	{
	  if (start.x > end.x)
	    {
	      tmp = start.x;
	      start.x = end.x;
	      end.x = tmp;
	    }
	  for (int i = start.y; i < (end.y + 1); i++)
	    {
	      x = start.x;
	      posList.push_back(glm::vec2(x, i));
	    }
	}
      if (dy == 0)
	{
	  if (start.y > end.y)
	    {
	      tmp = start.y;
	      start.y = end.y;
	      end.y = tmp;
	    }
	  for (int i = start.x; i < (end.x + 1); i++)
	    {
	      x = i;
	      y = start.y;
	      posList.push_back(glm::vec2(x, y));
	    }
	}
    }
  return (posList);
  (void)a;
}
