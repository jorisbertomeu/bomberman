//
// Floor.cpp for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed Jun  3 13:01:29 2015 Nicolas Adès
// Last update Wed Jun 10 20:22:48 2015 Geoffrey Merran
//

#include <Floor.hh>

Floor::Floor(const glm::vec3 & pos, const int & width, const int & heigth, const std::string & textPath) : Pavement(pos, textPath), _width(width), _heigth(heigth)
{
  this->_scale = glm::vec3(this->_width, 10, this->_heigth);
  this->_pos = glm::vec3(pos.x, pos.y - 30, pos.z);
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
