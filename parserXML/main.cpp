//
// main.cpp for  in /home/mediav_j/mabm/bomberman/parserXML
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Tue May 26 16:29:49 2015 Jérémy Mediavilla
// Last update Tue May 26 17:12:26 2015 Jérémy Mediavilla
//

#include <iostream>
#include "ParserXML.hh"

int	main(int ac, char **av)
{
  ParserXML	toto;

  (void)ac;
  if (toto.loadFile(av[1]) == false)
    return (std::cout << toto.getError() << std::endl, EXIT_FAILURE);
  if (toto.setNode("scene") == false)
    return (std::cout << toto.getError() << std::endl, EXIT_FAILURE);
  if (toto.setNode("parameters") == false)
    return (std::cout << toto.getError() << std::endl, EXIT_FAILURE);
  if (!toto.checkMultipleTag())
    return (std::cout << toto.getError() << std::endl, EXIT_FAILURE);
  std::cout << "author : " << toto.getValueOf("author") << std::endl;
  return (EXIT_SUCCESS);
}
