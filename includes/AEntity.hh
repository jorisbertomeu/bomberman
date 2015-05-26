//
// AEntity.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:12:07 2015 Nicolas Adès
// Last update Tue May 26 10:28:16 2015 Joris Bertomeu
//

#ifndef _AENTITY_H_
# define _AENTITY_H_

# include <Game.hh>

# include <stdexcept>
# include <iostream>
# include <glm/glm.hpp>
# include <ASolid.hh>

class				AEntity;

# include <RenderManager.hh>

class				AEntity : public ASolid
{
public:
  typedef enum			entityType
    {
      UNKNOWN			= 0,
      BRICKWALL			= 1,
      BOMBERMAN			= 2,
      BOMB			= 3,
      WOODWALL			= 4,
      FLOOR			= 5
    }				EntityType;

protected:
  glm::vec3			_pos;
  glm::vec3			_rotation;
  glm::vec3			_scale;

  std::string			_modelId;
  EntityType			_type;

public:
  explicit			AEntity(glm::vec3 pos, EntityType type);
  virtual			~AEntity();
  virtual glm::vec3		getPos() const;
  virtual AEntity::EntityType	getType() const;
  virtual void			setPos(const glm::vec3 &);
  virtual void			draw(const RenderManager & rm);
  virtual glm::mat4	       	getTransformation();
  virtual void			setModelId(const std::string &);
};

#endif // _AENTITY_H_
