//
// ModelManager.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Wed Jun  3 14:54:49 2015 Geoffrey Merran
// Last update Sun Jun 14 23:23:19 2015 Geoffrey Merran
//

#include <ModelManager.hh>

ModelManager::ModelManager()
{

}

ModelManager::~ModelManager()
{

}

bool				ModelManager::addModel(const std::string & path, const std::string & name, int online)
{
  gdl::Model*		       	model = new gdl::Model();

  if (!model->load(path))
    return (false);
  this->_modelMap[name] = new Model(path, online);
  this->_models[name] = model;
  std::cout << "[MODEL_LOADED] Model " << name << " loaded from " << path << "." << std::endl;
  return (true);
}

gdl::Model*			ModelManager::getModel(const std::string & name)
{
  std::map<std::string, gdl::Model*>::iterator it = this->_models.find(name);
  if (it == this->_models.end())
    return (NULL);
  return (this->_models[name]);
}

std::map<std::string, gdl::Model*>	ModelManager::getModels()
{
  return (this->_models);
}

void				ModelManager::save(std::fstream &fs)
{
  (void) fs;
  std::cout << "on save un model" << std::endl;
}

std::map<std::string, Model *>	ModelManager::getModelsMap() const
{
  return (this->_modelMap);
}
