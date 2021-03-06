//
// Bomb.hh for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:08:29 2015 Nicolas Adès
// Last update Sun Jun 14 17:38:26 2015 Geoffrey Merran
//

#ifndef _BOMB_H_
# define _BOMB_H_
# include <AEntity.hh>
# include <Fire.hh>

class		Bomb : public AEntity
{
protected:
  float		_explodeTime;
  int		_damage;
  bool		_exploded;
  void		*_parent;

public:
  Bomb(void *ptr, glm::vec3 pos);
  ~Bomb();

  void		explode(Scene*);
  int		getDamage() const;
  void		setDamage(const int &);
  virtual void	draw(RenderManager & rm);
  virtual void 	update(gdl::Clock &, Scene *);
  bool		freshBomb(void *ptr) const;
};

#endif // _BOMB_H_
