//
// AEntity.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:12:07 2015 Nicolas Adès
// Last update Mon May 25 22:35:25 2015 Joris Bertomeu
//

#ifndef _AENTITY_H_
# define _AENTITY_H_

# include <Game.hh>

# include <stdexcept>
# include <iostream>
# include <glm/glm.hpp>
# include <ASolid.hh>

class		AEntity : public ASolid
{
public:
  enum EntityType
    {
      UNKNOWN		= 0,
      BRICKWALL	= 1,
      BOMBERMAN		= 2,
      BOMB		= 3,
      WOODWALL		= 4
    };

protected:
  glm::vec3	_pos;
  EntityType	_type;

public:
  explicit			AEntity(glm::vec3 pos, EntityType type);
  virtual			~AEntity();
  virtual glm::vec3		getPos();
  virtual AEntity::EntityType	getType();
  virtual void			setPos(const glm::vec3 &);

};

#endif // _AENTITY_H_
