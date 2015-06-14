//
// WoodWall.hh for  in /home/parallels/Tek2/CPP/bomberman
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:15:36 2015 Nicolas Adès
// Last update Sun Jun 14 10:41:36 2015 Jérémy Mediavilla
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
  virtual void			update(gdl::Clock &, Scene *);
};

#endif // _WOODWALL_H_
