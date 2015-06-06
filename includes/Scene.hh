//
// Scene.hh for  in /home/mediav_j/mabm/bomberman
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Tue Jun  9 19:35:50 2015 Jérémy Mediavilla
// Last update Tue Jun  9 19:35:50 2015 Jérémy Mediavilla
//

#ifndef			_SCENE_HH_
# define		_SCENE_HH_

# include		<list>
# include		<fstream>

class			Scene;

# include		<AEntity.hh>
# include		<RenderManager.hh>

class			Scene
{
private:
  std::list<AEntity*>	_entityList;

public:
  explicit		Scene();
  virtual		~Scene();
  bool			addEntity(AEntity *);
  void			listAllEntities() const;
  std::list<AEntity *>	getEntities();
  void			draw(RenderManager & rm);
  bool			save();
};

#endif		// _SCENE_HH_
