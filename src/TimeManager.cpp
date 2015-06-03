//
// TimeManager.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Thu May 21 14:10:07 2015 Valérian Polizzi
// Last update Wed Jun  3 21:49:08 2015 Geoffrey Merran
//

#include "TimeManager.hh"

TimeManager::TimeManager()
{

}

TimeManager::~TimeManager()
{

}

gdl::Clock&		TimeManager::getClock()
{
  return (this->_clock);
}

void			TimeManager::delay() const
{
  double		waitingTime = (1000 / FPS) - this->_clock.getElapsed();
  if (waitingTime > 0)
    usleep(waitingTime);
}
