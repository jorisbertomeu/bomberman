//
// ModelManager.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Wed Jun  3 14:39:54 2015 Geoffrey Merran
// Last update Sun Jun 14 21:00:09 2015 Jérémy Mediavilla
//

#ifndef _MODELMANAGER_HH_
# define _MODELMANAGER_HH_

# include <iostream>
# include <map>
# include <Model.hpp>
# include <Model.hh>

class					ModelManager
{
public:
  explicit				ModelManager();
					~ModelManager();

  bool					addModel(const std::string & path, const std::string & name, int online = 0);
  gdl::Model*				getModel(const std::string & name);
  void					save(std::fstream &);
  std::map<std::string, gdl::Model *>	getModels();
  std::map<std::string, Model *>	getModelsMap() const;

private:
  std::map<std::string, gdl::Model*>	_models;
  std::map<std::string, Model *>	_modelMap;
};

#endif /* _MODELMANAGER_HH_ */
