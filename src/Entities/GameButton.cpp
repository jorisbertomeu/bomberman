//
// GameButton.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Fri Jun  5 14:43:04 2015 Valérian Polizzi
// Last update Fri Jun 12 04:07:39 2015 Geoffrey Merran
//

#include "GameButton.hh"

GameButton::GameButton(const glm::vec3 & pos, const std::string & texture) : Pavement(pos, texture), _current(false)
{

}

GameButton::~GameButton()
{

}

void			GameButton::update(gdl::Clock & clock)
{
  if (this->_current)
    this->rotate(glm::vec3(1, 0, 0), (50 * clock.getElapsed()));
}

void			GameButton::setCurrent(const bool & isCurrent)
{
  this->_current = isCurrent;
}

const bool &      	GameButton::getCurrent()
{
  return (this->_current);
}
