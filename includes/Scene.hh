//
// Scene.hh for  in /home/mediav_j/mabm/bomberman
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Tue Jun  9 19:35:50 2015 Jérémy Mediavilla
// Last update Fri Jun 12 05:00:58 2015 Geoffrey Merran
//

#ifndef			_SCENE_HH_
# define		_SCENE_HH_

# include		<list>
# include		<fstream>

class			Scene;

# include		<AEntity.hh>
# include		<RenderManager.hh>
# include		<CameraManager.hh>
# include		<IEvent.hh>

class			Scene
{
protected:
  std::list<AEntity*>	_entityList;
  std::string		_name;
  IEvent*		_eventHandler;

public:
  explicit		Scene();
  virtual		~Scene();

  bool			addEntity(AEntity *);
  std::list<AEntity *>	getEntities();
  void			updateEntities(gdl::Clock & clock);
  IEvent*		getEventHandler();

  void			draw(RenderManager & rm);
  bool			save(RenderManager *);
};

#endif		// _SCENE_HH_
