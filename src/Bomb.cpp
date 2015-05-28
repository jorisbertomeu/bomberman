//
// Bomb.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:08:09 2015 Nicolas Adès
// Last update Thu May 28 15:26:36 2015 Nicolas Adès
//

#include <Bomb.hh>

Bomb::Bomb(glm::vec3 pos) : AEntity(pos, AEntity::BOMB)
{
  this->_explodeTime = 4;
}

Bomb::~Bomb()
{

}

void		Bomb::explode()
{

}
