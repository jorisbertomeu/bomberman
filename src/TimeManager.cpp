//
// TimeManager.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Thu May 21 14:10:07 2015 Valérian Polizzi
// Last update Fri May 22 14:28:37 2015 Valérian Polizzi
//

#include "TimeManager.hh"

TimeManager::TimeManager()
{
  this->initialize();
}

TimeManager::~TimeManager()
{
}

int		TimeManager::initialize()
{
  this->PauseTime();
  return (0);
}

void		TimeManager::setCurrentTime(unsigned int ms)
{
  _currentTime = ms;
}

unsigned int	TimeManager::getCurrentTime() const
{
  return (_currentTime);
}

void		TimeManager::updateFps()
{

}

int		TimeManager::update()
{
  return (0);
}

void		TimeManager::PauseTime()
{
  _isPaused = true;
}

void		TimeManager::RunTime()
{
  _isPaused = false;
}
