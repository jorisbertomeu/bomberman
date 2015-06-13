//
// HitBox.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Tue May 26 12:24:45 2015 Nicolas Adès
// Last update Sun Jun 14 05:33:36 2015 Jérémy Mediavilla
//

#ifndef	 _HITBOX_H_
# define _HITBOX_H_

# include <glm/glm.hpp>
# include <iostream>
# include <list>


//# include <AEntity.hh>

class		Hitbox
{
public:

  glm::vec3	_c1;
  glm::vec3	_c2;
  glm::vec3	_c3;
  glm::vec3	_c4;
  glm::vec3	_c5;
  glm::vec3	_c6;
  glm::vec3	_c7;
  glm::vec3	_c8;

public:
  explicit	Hitbox(void *);
  bool		checkCollision(void *);
  void		updateHitbox(void *);
  bool		checkCollisionForPoint(glm::vec3);
  virtual	~Hitbox();
  bool		checkCollisionForPointForEntities(void *, glm::vec3);
};

#endif
