//
// Scene.hh for  in /home/mediav_j/mabm/bomberman/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Mon Jun  1 15:29:00 2015 Jérémy Mediavilla
// Last update Mon Jun  1 15:35:24 2015 Jérémy Mediavilla
//

#ifndef			_SCENE_HH_
# define		_SCENE_HH_

# include		<list>
# include		<AEntity.hh>

class			Scene
{
private:
  std::list<AEntity>	_entityList;

public:
  explicit		Scene();
  virtual		~Scene();
  bool			addEntity(const AEntity &);
};

#endif		// _SCENE_HH_
