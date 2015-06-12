//
// TimeManager.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Thu May 21 14:10:07 2015 Valérian Polizzi
// Last update Fri Jun 12 18:39:17 2015 Geoffrey Merran
//

#include <TimeManager.hh>

TimeManager::TimeManager() : _fpsTimeCounter(0), _fps(0)
{

}

TimeManager::~TimeManager()
{

}

gdl::Clock&		TimeManager::getClock()
{
  return (this->_clock);
}

void			TimeManager::printFps()
{
  this->_fps++;
  this->_fpsTimeCounter += (this->_clock.getElapsed() * 1000);
  if (this->_fpsTimeCounter >= 1000)
    {
      std::cout << "FPS: " << this->_fps / (this->_fpsTimeCounter / 1000) << std::endl;
      this->_fps = 0;
      this->_fpsTimeCounter = 0;
    }
}

void			TimeManager::delay() const
{
  double		waitingTime = (1000 / FPS) - (this->_clock.getElapsed() * 1000);

  if (waitingTime > 0)
    usleep(waitingTime * 1000);
}
