//
// Scene.hh for  in /home/mediav_j/mabm/bomberman/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Jun  1 15:29:00 2015 Jérémy Mediavilla
// Last update Tue May 26 08:18:38 2015 Joris Bertomeu
//

#ifndef			_SCENE_HH_
# define		_SCENE_HH_

# include		<list>
# include		<AEntity.hh>

class			Scene
{
private:
  std::list<AEntity*>	_entityList;

public:
  explicit		Scene();
  virtual		~Scene();
  bool			addEntity(AEntity *);
  void			listAllEntities() const;
};

#endif		// _SCENE_HH_
