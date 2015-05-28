//
// Bomb.hh for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:08:29 2015 Nicolas Adès
// Last update Thu May 28 15:26:20 2015 Nicolas Adès
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
};

#endif // _BOMB_H_
