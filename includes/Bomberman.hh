//
// Bomberman.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <parallels@epitech.net>
// 
// Started on  Tue May 26 14:52:09 2015 Nicolas Adès
// Last update Sun Jun 14 03:02:42 2015 Geoffrey Merran
//

#ifndef _BOMBERMAN_H_
# define _BOMBERMAN_H_

class		Bomberman;

# include <Clock.hh>
# include <AEntity.hh>
# include <Scene.hh>
# include <ModelManager.hh>

class		Bomberman : public AEntity
{
public:
  enum Dir
    {
      UP = 1,
      RIGHT = 2,
      DOWN = 3,
      LEFT = 4
    };

  Bomberman(glm::vec3 pos, const std::string &name, ModelManager&);
  ~Bomberman();

  std::string	getName() const;
  void		dropBomb(Scene*);
  void		moveRight(gdl::Clock&);
  void		moveLeft(gdl::Clock&);
  void		moveBack(gdl::Clock&);
  void		moveFront(gdl::Clock&);
  void		jump();
  void		isReleased(Scene *, gdl::Clock&);
  void		isTurningBack(const int &);
  void		initialize();

  virtual void 	draw(RenderManager & rm);
  virtual void 	update(gdl::Clock &, Scene *);

protected:
  bool		_init;
  std::string	_currentAnim;
  std::string	_animToDisplay;
  ModelManager  _modelManager;
  int		_nbBombs;
  int		_fireRange;
  std::string	_name;
  Dir		_dir;
};

#endif // _BOMBERMAN_H_
