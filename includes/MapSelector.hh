//
// MapSelector.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 03:48:15 2015 Geoffrey Merran
// Last update Sat Jun 13 20:57:49 2015 Geoffrey Merran
//

#ifndef __MAP_SELECTOR_HH
# define __MAP_SELECTOR_HH
# include <iostream>
# include <dirent.h>
# include <list>
# include <Map.hh>

class				MapSelector
{
public:
  MapSelector(const std::string &);
  ~MapSelector();

  bool				hasFoundMap() const;
  void			        nextMap();
  void				prevMap();
  std::list<Map>::iterator	getCurrent();
  std::list<std::string>	get3Maps();

private:
  std::list<Map>		_maps;
};

#endif /* __MAP_SELECTOR_HH */
