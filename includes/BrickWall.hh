//
// BrickWall.hh for  in /home/parallels/Tek2/CPP/bomberman
// 
// Made by Nicolas Adès
// Login   <parallels@epitech.net>
// 
// Started on  Wed May 27 13:18:15 2015 Nicolas Adès
// Last update Fri Jun 12 03:42:01 2015 Geoffrey Merran
//

#ifndef _BRICKWALL_H_
# define _BRICKWALL_H_
# include <AEntity.hh>

class				BrickWall : public AEntity
{
public:
  BrickWall(glm::vec3 pos);
  ~BrickWall();

  virtual void			draw(RenderManager & rm);
  virtual void			update(gdl::Clock &);
};

#endif // _BRICKWALL_H_
