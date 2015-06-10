//
// Bomb.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:08:09 2015 Nicolas Adès
// Last update Fri Jun 12 18:06:29 2015 Jérémy Mediavilla
//

#include <Bomb.hh>

Bomb::Bomb(glm::vec3 pos) : AEntity(pos, AEntity::BOMB)
{
  this->_explodeTime = 4;
  this->_damage = 50;
}

Bomb::~Bomb()
{

}

void		Bomb::explode() const
{

}

int		Bomb::getDamage() const
{
  return (this->_damage);
}

void		Bomb::setDamage(const int &damage)
{
  this->_damage = damage;
}

void		Bomb::update()
{
  this->_explodeTime -= 1;
}

void		Bomb::draw(RenderManager & rm)
{
  (void) rm;
}

void		Bomb::update(gdl::Clock & clock, Scene *scene)
{
  (void)scene;
  (void) clock;
}
