//
// Scene.cpp for  in /home/mediav_j/mabm/bomberman/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Mon Jun  1 15:32:58 2015 Jérémy Mediavilla
// Last update Mon Jun  1 15:35:23 2015 Jérémy Mediavilla
//

#include	"Scene.hh"

Scene::Scene()
{

}

Scene::~Scene()
{

}

bool		Scene::addEntity(const AEntity &entity)
{
  this->_entityList.push_back(entity);
  return(true);
}
