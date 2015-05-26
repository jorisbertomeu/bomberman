//
// GameEngine.cpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 09:32:34 2015 Joris Bertomeu
// Last update Tue May 26 17:46:03 2015 Geoffrey Merran
//

#include <GameEngine.hh>

GameEngine::GameEngine(int ac, char **argv) : _running(1)
{
  try {
    this->_parameters.setParameters(ac, argv);
  } catch (const std::exception &e) {
    throw std::logic_error(e.what());
  }
}

GameEngine::~GameEngine()
{

}

bool	GameEngine::initialize()
{
  if (!this->_renderManager.initialize(this->_parameters.getSize(), std::string("Bomberman")))
    return (false);
  this->_gameContext.initialize(&(this->_renderManager));
  return (true);
}

bool	GameEngine::update()
{
  this->_renderManager.update();
  _running = 0;
  return (true);
}

void	GameEngine::draw()
{
  this->_renderManager.draw(this->_gameContext.getCurrentScene());
}

bool	GameEngine::run()
{
  this->_renderManager.start();
  while (this->_running)
    {
      this->update();
      sleep(1);
    }
  this->_renderManager.stop();
  return (true);
}
