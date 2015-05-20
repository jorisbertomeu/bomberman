//
// GameEngine.cpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 09:32:34 2015 Joris Bertomeu
// Last update Tue May 19 14:52:13 2015 Joris Bertomeu
//

#include <GameEngine.hh>

GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{



bool	GameEngine::initialize()
{
  this->_renderManager.initialize(this->_parameters.getSize(), std::string("Bomberman"));
}

bool	GameEngine::update()
{

}

bool	GameEngine::draw()
{

}

bool	GameEngine::run()
{

}
