//
// ModelManager.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Wed Jun  3 14:39:54 2015 Geoffrey Merran
// Last update Wed Jun  3 15:12:27 2015 Geoffrey Merran
//

#ifndef _MODELMANAGER_HH_
# define _MODELMANAGER_HH_

# include <map>
# include <Model.hh>

class					ModelManager
{
public:
  explicit				ModelManager();
					~ModelManager();

  bool					addModel(const std::string & path, const std::string & name);
  gdl::Model*				getModel(const std::string & name);

private:
  std::map<std::string, gdl::Model*>	_models;
};

#endif /* _MODELMANAGER_HH_ */
