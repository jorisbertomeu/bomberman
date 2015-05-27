//
// AEntity.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Mon May 25 14:12:07 2015 Nicolas Adès
// Last update Wed May 27 13:22:38 2015 Nicolas Adès
//

#ifndef _AENTITY_H_
# define _AENTITY_H_

# include <Game.hh>

# include <stdexcept>
# include <iostream>
# include <glm/glm.hpp>

class		AEntity
{
public:
  enum EntityType
    {
      UNKNOWN		= 0,
      BRICK_WALL	= 1,
      BOMBERMAN		= 2,
      BOMB		= 3,
      WOOD_WALL		= 4
    };

protected:
  glm::vec3	_pos;
  EntityType	_type;

public:
  explicit		AEntity();
  virtual		~AEntity();
  virtual glm::vec3	getPos();
  virtual AEntity::EntityType	getType();
  virtual void		setPos(const glm::vec3 &);

};

#endif // _AENTITY_H_
