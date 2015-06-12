//
// Scene.hh for  in /home/mediav_j/mabm/bomberman
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Tue Jun  9 19:35:50 2015 Jérémy Mediavilla
// Last update Fri Jun 12 04:27:09 2015 Geoffrey Merran
//

#ifndef			_SCENE_HH_
# define		_SCENE_HH_

# include		<list>
# include		<fstream>

class			Scene;

# include		<AEntity.hh>
# include		<RenderManager.hh>
# include		<CameraManager.hh>

class			Scene
{
private:
  std::list<AEntity*>	_entityList;
  std::string		_name;

public:
  explicit		Scene();
  virtual		~Scene();
  bool			addEntity(AEntity *);
  std::list<AEntity *>	getEntities();
  void			updateEntities(gdl::Clock & clock);
  void			draw(RenderManager & rm);
  bool			save(RenderManager *);
};

#endif		// _SCENE_HH_
