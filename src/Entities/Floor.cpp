//
// Floor.cpp for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Wed Jun  3 13:01:29 2015 Nicolas Adès
// Last update Wed Jun 10 07:17:53 2015 Joris Bertomeu
//

#include <Floor.hh>

Floor::Floor(const glm::vec3 & pos, const int & width, const int & heigth, Texture *texture) : Pavement(pos, texture), _width(width), _heigth(heigth)
{
  this->_scale = glm::vec3(this->_width, 10, this->_heigth);
  this->_pos = glm::vec3(483, 0 - 25, 483);
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
