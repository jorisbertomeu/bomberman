//
// Floor.cpp for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed Jun  3 13:01:29 2015 Nicolas Adès
// Last update Wed Jun  3 23:24:24 2015 Geoffrey Merran
//

#include <Floor.hh>

Floor::Floor(const glm::vec3 & pos, const int & width, const int & heigth) : AEntity(pos, AEntity::FLOOR), _width(width), _heigth(heigth)
{

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

void	Floor::draw(RenderManager & rm)
{
  (void) rm;
}
