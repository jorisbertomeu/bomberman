//
// WoodWall.hh for  in /home/parallels/Tek2/CPP/bomberman
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:15:36 2015 Nicolas Adès
// Last update Wed Jun  3 21:29:33 2015 Geoffrey Merran
//

#ifndef _WOODWALL_H_
# define _WOODWALL_H_
# include <AEntity.hh>

class		WoodWall : public AEntity
{
public:
  WoodWall(glm::vec3 pos);
  ~WoodWall();

  virtual void			draw(RenderManager & rm);
};

#endif // _WOODWALL_H_
