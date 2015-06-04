//
// Scene.cpp for  in /home/mediav_j/mabm/bomberman/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Jun  1 15:32:58 2015 Jérémy Mediavilla
// Last update Thu Jun  4 16:57:03 2015 mari_f
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

void		Scene::listAllEntities() const
{
  // for (std::list<AEntity>::iterator it = this->_entityList.begin(); it =! this->_entityList.end(); it++)  {
  //   if (*it->getType() == AEntity::BOMBERMAN)
  //     std::cout << "Bomberman Insered with pos <" << *it->getPos().x << ", " << *it.getPos()->y << ", " << *it.getPos()->z << ">" << std::endl;
  //   else if (*it->getType() == AEntity::BRICKWALL)
  //     std::cout << "Brickwall Insered with pos <" << *it->getPos().x << ", " << *it->getPos().y << ", " << *it->getPos().z << ">" << std::endl;

  // }
}

void  	      	Scene::draw(RenderManager & rm)
{
  for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end(); it++)
    (*it)->draw(rm);
}
