//
// Map.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 19:01:36 2015 Geoffrey Merran
// Last update Sat Jun 13 23:16:19 2015 Geoffrey Merran
//

#include <Map.hh>

Map::Map(std::string filename) : _loaded(false), _corrupted(false), _current(false), _filename("maps/" + filename), _author("mabm")
{

}

Map::~Map()
{

}

const bool &		Map::getCurrent() const
{
  return (this->_current);
}

void			Map::setCurrent(const bool & cur)
{
  this->_current = cur;
}

const std::string&     	Map::getFilename() const
{
  return (this->_filename);
}

const std::string&	Map::getFilepreview()
{
  if (!this->_loaded)
    {
      this->load();
      this->_loaded = true;
    }
  return (this->_filepreview);
}

const bool &	       	Map::isCorrupted()
{
  return (this->_corrupted);
}

void			Map::load()
{
  ParserXML	pxml;

  if (pxml.loadFile(this->_filename))
    {
      pxml.setNode("scene");
      pxml.setNode("parameters");
      this->_mapId = pxml.getValueOf("id");
      this->_author = pxml.getValueOf("author");
      if (this->_author == "")
	this->_author = "UNKNOWN";
      std::string	link = "http://vps177762.ovh.net/generatePreview.php?id=" + this->_mapId + "&text=" + this->_author;
      std::cout << "[PREVIEW LOADING] Downloading " << link << " to " << "maps/" << this->_mapId << ".tga" << std::endl;
      HttpRequest	req(link, "maps/" + this->_mapId + ".tga");
      if (!req.exec())
	{
	  std::cerr << "[PREVIEW LOADING ERROR] No preview found online" << std::endl;
	  this->_filepreview = "assets/textures/preview.tga";
	}
      else
	this->_filepreview = "maps/" + this->_mapId + ".tga";
    }
  else
    {
      this->_corrupted = true;
      this->_filepreview = "assets/textures/corrupted.tga";
    }
}
