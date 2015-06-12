//
// Floor.cpp for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Wed Jun  3 13:01:29 2015 Nicolas Adès
// Last update Wed Jun 10 06:55:15 2015 Joris Bertomeu
//

#include <Floor.hh>

Floor::Floor(const glm::vec3 & pos, const int & width, const int & heigth, Texture *texture) : Pavement(pos, texture), _width(width), _heigth(heigth)
{
  this->_scale = glm::vec3(1000, 10, this->_heigth);
  this->_pos = glm::vec3(483, pos.y - 30, 483);
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
