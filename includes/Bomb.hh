//
// Bomb.hh for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:08:29 2015 Nicolas Adès
// Last update Wed Jun  3 21:29:29 2015 Geoffrey Merran
//

#ifndef _BOMB_H_
# define _BOMB_H_
# include <AEntity.hh>

class		Bomb : public AEntity
{
protected:
  int		_explodeTime;
  int		_damage;

public:
  Bomb(glm::vec3 pos);
  ~Bomb();

  void		explode() const;
  int		getDamage() const;
  void		setDamage(const int &);
  void		update();
  virtual void	draw(RenderManager & rm);
};

#endif // _BOMB_H_
