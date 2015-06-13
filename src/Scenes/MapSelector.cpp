//
// MapSelector.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 03:47:52 2015 Geoffrey Merran
// Last update Sat Jun 13 04:42:06 2015 Geoffrey Merran
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
	      // pxml.loadFile("maps/" + filename);
	      // pxml.setNode("scene");
	      // pxml.setNode("parameters");
	      // std::cout << pxml.getValueOf("preview") << std::endl;
	    }
	}
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
