//
// GameEngine.cpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 09:32:34 2015 Joris Bertomeu
// Last update Wed May 20 11:54:52 2015 Geoffrey Merran
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
