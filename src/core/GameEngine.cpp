//
// GameEngine.cpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 09:32:34 2015 Joris Bertomeu
// Last update Tue May 19 10:30:38 2015 Joris Bertomeu
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

}

bool	GameEngine::update()
{

}

void	GameEngine::draw()
{

}

bool	GameEngine::run()
{

}
