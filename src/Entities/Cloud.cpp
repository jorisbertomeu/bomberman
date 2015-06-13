//
// GameButton.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Fri Jun  5 14:43:04 2015 Valérian Polizzi
// Last update Wed Jun 10 15:43:26 2015 Joris Bertomeu
//

#include <Cloud.hh>

Cloud::Cloud(const glm::vec3 & pos, const std::string & texture, const float &range, const float &gap) : Pavement(pos, texture), _current(true)
{
  this->_dir = 1;
  this->_originalPos = pos;
  this->_gap = gap;
  this->_range = range;
}

Cloud::~Cloud()
{

}

void			Cloud::update(gdl::Clock & clock, Scene *scene)
{
  (void)scene;
  if (this->_current) {
    if (this->_dir == 1)
      this->translate(glm::vec3(this->_range, 0, 0) * static_cast<float>(50 * clock.getElapsed()));
    else
      this->translate(glm::vec3(this->_range * -1.0f, 0, 0) * static_cast<float>(50 * clock.getElapsed()));
    if (this->getPos().x > this->_originalPos.x + this->_gap)
      this->_dir = 0;
    else if (this->getPos().x < this->_originalPos.x - this->_gap)
      this->_dir = 1;
  }
}

void			Cloud::setCurrent(const bool & isCurrent)
{
  this->_current = isCurrent;
}

const bool &      	Cloud::getCurrent() const
{
  return (this->_current);
}

const int &	Cloud::getId() const
{
  return (this->_id);
}

void		Cloud::setRange(const float &range)
{
  this->_range = range;
}

void		Cloud::setGap(const float &gap)
{
  this->_gap = gap;
}
