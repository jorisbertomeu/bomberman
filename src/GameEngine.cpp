//
// GameEngine.cpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 09:32:34 2015 Joris Bertomeu
// Last update Tue May 19 15:18:43 2015 Joris Bertomeu
//

#include <GameEngine.hh>

GameEngine::GameEngine(int ac, char **argv)
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
  this->_renderManager.initialize(this->_parameters.getSize(), std::string("Bomberman"));
  this->_gameContext.initialize(&(this->_renderManager));
}

bool	GameEngine::update()
{
  this->_renderManager.update();
}

void	GameEngine::draw()
{
  this->_renderManager.draw(this->_gameContext.getCurrentScene());
}

bool	GameEngine::run()
{
  this->_renderManager.start();
  while (this->update()) {

  }
}
