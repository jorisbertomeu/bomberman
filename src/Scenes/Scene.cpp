//
// Scene.cpp for  in /home/mediav_j/mabm/bomberman/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Jun  1 15:32:58 2015 Jérémy Mediavilla
// Last update Fri Jun 12 03:36:24 2015 Geoffrey Merran
//

#include	"Scene.hh"

Scene::Scene()
{

}

Scene::~Scene()
{

}

std::list<AEntity*>		Scene::getEntities()
{
  return (this->_entityList);
}

bool		Scene::addEntity(AEntity *entity)
{
  this->_entityList.push_back(entity);
  return(true);
}

void  	      	Scene::draw(RenderManager & rm)
{
  for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end(); it++)
    (*it)->draw(rm);
}

void		Scene::updateEntities(gdl::Clock & clock)
{
  for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end(); it++)
    (*it)->update(clock);
}

bool		Scene::save(RenderManager *rm)
{
  std::fstream	fs;

  fs.open("XMLfiles/save.xml", std::fstream::in | std::fstream::out | std::fstream::trunc);
  if (!fs.is_open())
    {
      std::cout << "Error on open while saving map.xml" << std::endl;
      return (false);
    }
  fs << "<scene>" << std::endl;
  fs << "  <texture_pack>" << std::endl;
  std::map<std::string, Texture *> textureList = rm->getTextureManager().getTextures();
  for (std::map<std::string, Texture*>::iterator it = textureList.begin(); it != textureList.end(); ++it)
    {
      (*it->second).save(fs);
    }
  fs << "  </texture_pack>" << std::endl;
  fs << "  <entities>" << std::endl;
  for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end(); ++it)
    {
      (*it)->save(fs);
    }
  fs << "  </entities>" << std::endl;
  fs << "/<scene>" << std::endl;
  fs.close();
  return (true);
}
