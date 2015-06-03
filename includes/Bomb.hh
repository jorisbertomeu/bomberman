//
// Bomb.hh for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:08:29 2015 Nicolas Adès
// Last update Wed Jun  3 13:11:42 2015 Nicolas Adès
//

#ifndef _BOMB_H_
# define _BOMB_H_
# include <AEntity.hh>

class		Bomb : public AEntity
{
protected:
  float		_explodeTime;

public:
  Bomb(glm::vec3 pos);
  ~Bomb();

  void		explode();
  virtual void	draw();
};

#endif // _BOMB_H_
