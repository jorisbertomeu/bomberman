//
// ASolid.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Tue May 26 12:38:07 2015 Nicolas Adès
// Last update Wed Jun  3 19:54:28 2015 Geoffrey Merran
//

#include <ASolid.hh>

ASolid::ASolid()
{

}

ASolid::~ASolid()
{

}

bool		ASolid::checkColision(ASolid *solid)
{
  (void) solid;
  return (true);
}

float		ASolid::getFriction() const
{
  return (this->_friction);
}

void		ASolid::setFriction(const float & friction)
{
  this->_friction = friction;
}

float		ASolid::getSpeed() const
{
  return (this->_speed);
}

void		ASolid::setSpeed(const float & speed)
{
  this->_speed = speed;
}

float		ASolid::getRange() const
{
  return (this->_range);
}

void		ASolid::setRange(const float &range)
{
  this->_range = range;
}

int		ASolid::getWeight() const
{
  return (this->_weight);
}

void		ASolid::setWeight(const int &weight)
{
  this->_weight = weight;
}

int		ASolid::getHealth() const
{
  return (this->_health);
}

void		ASolid::setHealth(const int &health)
{
  this->_health = health;
}

bool		ASolid::getMove() const
{
  return (this->_move);
}

void		ASolid::setMove(const bool & move)
{
  this->_move = move;
}

bool		ASolid::getJump() const
{
  return (this->_jump);
}

void		ASolid::setJump(const bool &jump)
{
  this->_jump = jump;
}

std::string	ASolid::getTexture() const
{
  return (this->_texture);
}

void		ASolid::setTexture(const std::string &texture)
{
  this->_texture = texture;
}

ASolid::SolidAbility	ASolid::getAbility() const
{
  return (this->_ability);
}

void	ASolid::setAbility(const ASolid::SolidAbility & ability)
{
  this->_ability = ability;
}

ASolid::SolidBonus	ASolid::getBonus() const
{
  return (this->_bonus);
}

void			ASolid::setBonus(const ASolid::SolidBonus & bonus)
{
  this->_bonus = bonus;
}
