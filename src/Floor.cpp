//
// Floor.cpp for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed Jun  3 13:01:29 2015 Nicolas Adès
// Last update Wed Jun  3 13:07:14 2015 Nicolas Adès
//

#include <Floor.hh>

Floor::Floor(glm::vec3 pos, int width, int heigth) : AEntity(pos, AEntity::FLOOR)
{
  this->_width = width;
  this->_heigth = heigth;
}

Floor::~Floor()
{

}

int	Floor::getWidth() const
{
  return (this->_width);
}

int	Floor::getHeigth() const
{
  return (this->_heigth);
}

void	Floor::draw()
{

}
