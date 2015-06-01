//
// Bomberman.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 12:18:17 2015 Nicolas Adès
// Last update Mon Jun  1 17:58:18 2015 Geoffrey Merran
//

#include <Bomberman.hh>

Bomberman::Bomberman(glm::vec3 pos, const std::string &name) : AEntity(pos, AEntity::BOMBERMAN)
{
  this->_name = name;
}

Bomberman::~Bomberman()
{

}

std::string	Bomberman::getName() const
{
  return (this->_name);
}

void		Bomberman::dropBomb()
{

}

void		Bomberman::moveRight()
{

}

void		Bomberman::moveLeft()
{

}

void		Bomberman::moveBack()
{

}

void		Bomberman::moveFront()
{

}

void		Bomberman::jump()
{

}

void		Bomberman::draw()
{

}
