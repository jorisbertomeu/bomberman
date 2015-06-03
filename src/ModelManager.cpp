//
// ModelManager.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Wed Jun  3 14:54:49 2015 Geoffrey Merran
// Last update Wed Jun  3 15:12:24 2015 Geoffrey Merran
//

#include "ModelManager.hh"

ModelManager::ModelManager()
{

}

ModelManager::~ModelManager()
{

}

bool				ModelManager::addModel(const std::string & path, const std::string & name)
{
  gdl::Model*		       	model = new gdl::Model();

  if (!model->load(path))
    return (false);
  this->_models[name] = model;
  return (true);
}

gdl::Model*			ModelManager::getModel(const std::string & name)
{
  std::map<std::string, gdl::Model*>::iterator it = this->_models.find(name);
  if (it == this->_models.end())
    return (NULL);
  return (this->_models[name]);
}