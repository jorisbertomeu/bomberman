//
// Balloon.cpp for  in /home/mari_f/final/src/Scenes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Sun Jun 14 01:21:58 2015 mari_f
// Last update Sun Jun 14 01:33:42 2015 mari_f
//


#include <Balloon.hh>

Balloon::Balloon(const glm::vec3 & pos, const std::string & texture, const float &range, const float &gap) : Pavement(pos, texture), _current(true)
{
  this->_dir = 1;
  this->_originalPos = pos;
  this->_gap = gap;
  this->_range = range;
}

Balloon::~Balloon()
{

}

void			Balloon::update(gdl::Clock & clock, Scene *scene)
{
  (void)scene;
  if (this->_current) {
    if (this->_dir == 1)
      this->translate(glm::vec3(0, this->_range, 0) * static_cast<float>(30 * clock.getElapsed()));
    else
      this->translate(glm::vec3(0, this->_range * -1.0f, 0) * static_cast<float>(30 * clock.getElapsed()));
    if (this->getPos().y > this->_originalPos.y + this->_gap)
      this->_dir = 0;
    else if (this->getPos().y < this->_originalPos.y - this->_gap)
      this->_dir = 1;
  }
}

void			Balloon::setCurrent(const bool & isCurrent)
{
  this->_current = isCurrent;
}

const bool &      	Balloon::getCurrent() const
{
  return (this->_current);
}

const int &	Balloon::getId() const
{
  return (this->_id);
}

void		Balloon::setRange(const float &range)
{
  this->_range = range;
}

void		Balloon::setGap(const float &gap)
{
  this->_gap = gap;
}
