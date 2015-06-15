//
// MapSelector.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 03:47:52 2015 Geoffrey Merran
// Last update Sun Jun 14 23:28:29 2015 Geoffrey Merran
//

#include <MapSelector.hh>

MapSelector::MapSelector(const std::string & folderPath)
{
  DIR*				dir;
  struct dirent*		ent;
  ParserXML			pxml;

  if ((dir = opendir(folderPath.c_str())) != NULL)
    {
      while ((ent = readdir(dir)) != NULL)
	{
	  std::string filename(ent->d_name);
	  if (filename.substr(filename.find_last_of(".") + 1) == "xml")
	    {
	      std::cout << "[MAP FOUND] : " << filename << std::endl;
	      filename = folderPath + filename;
	      this->_maps.push_back(Map(filename));
	    }
	}
      if (this->hasFoundMap())
	this->_maps.front().setCurrent(true);
      closedir(dir);
    }
}

MapSelector::~MapSelector()
{

}

bool				MapSelector::hasFoundMap() const
{
  if (this->_maps.empty())
    return (false);
  return (true);
}

std::list<Map>::iterator	MapSelector::getCurrent()
{
  for (std::list<Map>::iterator it = this->_maps.begin(); it != this->_maps.end(); it++)
    {
      if ((*it).getCurrent())
	return (it);
    }
  return (this->_maps.end());
}

void			        MapSelector::nextMap()
{
  std::list<Map>::iterator	it = this->getCurrent();
  std::list<Map>::iterator	n = this->_maps.end();

  n--;
  if (it != n)
    (*it).setCurrent(false);
  if (++it != this->_maps.end())
    {
      (*it).setCurrent(true);
      std::cout << "[MAP SELECT] " << (*it).getFilename() << std::endl;
    }
}

void				MapSelector::prevMap()
{
  std::list<Map>::iterator	it = this->getCurrent();

  if (it != this->_maps.begin())
    {
      (*it--).setCurrent(false);
      (*it).setCurrent(true);
      std::cout << "[MAP SELECT] " << (*it).getFilename() << std::endl;
    }
}

std::list<std::string>		MapSelector::get3Maps()
{
  std::list<std::string>	texturesList;

  if (!this->hasFoundMap())
    {
      texturesList.push_back("hidden");
      texturesList.push_back("hidden");
      texturesList.push_back("hidden");
      return (texturesList);
    }

  std::list<Map>::iterator	it = this->getCurrent();
  int				i = 0;
  if (it == this->_maps.begin())
    {
      texturesList.push_back("hidden");
      i++;
    }
  else
    it--;
  while (i < 3)
    {
      if (it == this->_maps.end())
	{
	  texturesList.push_back("hidden");
	  i = 3;
	}
      else
	texturesList.push_back((*it).getFilepreview());
      it++;
      i++;
    }
  return (texturesList);
}

