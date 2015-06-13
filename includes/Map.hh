//
// Map.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 18:54:23 2015 Geoffrey Merran
// Last update Sat Jun 13 21:42:23 2015 Geoffrey Merran
//

#ifndef __MAP_H
# define __MAP_H
# include <ParserXML.hpp>
# include <HttpRequest.hh>
# include <iostream>

class			Map
{
public:
  Map(std::string filename);
  ~Map();

  const bool &		getCurrent() const;
  void			setCurrent(const bool &);
  const bool &	       	isCorrupted();
  const std::string&   	getFilename() const;
  const std::string&	getFilepreview() const;

private:
  bool			_corrupted;
  bool			_current;
  std::string		_filename;
  std::string		_author;
  std::string		_mapId;
  std::string		_filepreview;
};

#endif /* __MAP_H */
