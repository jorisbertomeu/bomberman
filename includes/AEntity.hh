//
// AEntity.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:12:07 2015 Nicolas Adès
// Last update Fri Jun 12 18:55:22 2015 Jérémy Mediavilla
//

#ifndef _AENTITY_H_
# define _AENTITY_H_


# include <stdexcept>
# include <iostream>
# include <fstream>
# include <glm/glm.hpp>

class				AEntity;

# include <Game.hh>
# include <ASolid.hh>
# include <RenderManager.hh>
# include <HitBox.hh>

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
      FLOOR			= 5,
      BUTTON			= 6,
      BOT			= 7,
      RECTANGLE			= 8,
      PAVEMENT			= 9
    }				EntityType;

protected:
  glm::vec3			_pos;
  glm::vec3			_rotation;
  glm::vec3			_scale;

  std::string			_modelId;
  EntityType			_type;
  Hitbox			*_hitbox;

public:
  explicit			AEntity(glm::vec3 pos, EntityType type);
  explicit			AEntity(glm::vec3 pos, EntityType type, bool);
  virtual			~AEntity();

  glm::vec3			getPos() const;
  AEntity::EntityType		getType() const;
  void				setPos(const glm::vec3 &);
  void				setScale(const glm::vec3 & scale);
  glm::vec3			getScale();

  void				setModelId(const std::string &);
  std::string			getModelId() const;

  void				translate(const glm::vec3 & v);
  void				rotate(const glm::vec3 & axis, const float & angle);
  void				scale(const glm::vec3 & scale);
  glm::mat4			getTransformation();

  virtual void			draw(RenderManager & rm) = 0;
  virtual void			update(gdl::Clock &, Scene *) = 0;
  virtual void		       	save(std::fstream &);
  virtual Hitbox	       	*getHitbox() const;
};

#endif // _AENTITY_H_
