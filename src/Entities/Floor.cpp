//
// Floor.cpp for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Wed Jun  3 13:01:29 2015 Nicolas Adès
// Last update Sun Jun 14 11:13:23 2015 Jérémy Mediavilla
//

#include <Floor.hh>

Floor::Floor(const glm::vec3 & pos, const int & width, const int & heigth, Texture *texture) : Pavement(pos, texture), _width(width), _heigth(heigth)
 {
  this->setFriction(0.015);
  this->_scale = glm::vec3(this->_width, 10, this->_heigth);
  this->_pos = glm::vec3(this->_width / 2 - ((3.7 / (this->_width / 1000)) * this->_width / 2) / 100,
			 0 - 25,
			 this->_heigth / 2 - ((3.7 / (this->_heigth / 1000)) * this->_heigth / 2) / 100);
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
