//
// main.cpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 09:26:22 2015 Joris Bertomeu
// Last update Mon May 25 17:10:00 2015 Geoffrey Merran
//

#include <GameEngine.hh>

int	main(int ac, char *argv[])
{
  GameEngine	*gameEngine;

  try  {
    gameEngine = new GameEngine(ac, argv);
    gameEngine->initialize();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return (-1);
  }
  gameEngine->run();
  delete gameEngine;
}
