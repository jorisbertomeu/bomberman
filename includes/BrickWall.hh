//
// BrickWall.hh for  in /home/parallels/Tek2/CPP/bomberman
// 
// Made by Nicolas Adès
// Login   <parallels@epitech.net>
// 
// Started on  Wed May 27 13:18:15 2015 Nicolas Adès
// Last update Thu May 28 14:43:44 2015 Nicolas Adès
//

#ifndef _BRICKWALL_H_
# define _BRICKWALL_H_
# include <AEntity.hh>

class		BrickWall : public AEntity
{
public:
  BrickWall(glm::vec3 pos);
  ~BrickWall();

};

#endif // _BRICKWALL_H_
