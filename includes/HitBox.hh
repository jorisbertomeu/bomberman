//
// HitBox.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Tue May 26 12:24:45 2015 Nicolas Adès
// Last update Tue May 26 12:46:54 2015 Nicolas Adès
//

#ifndef	 _HITBOX_H_
# define _HITBOX_H_

# include <AEntity.hh>
# include <glm/glm.hpp>
# include <iostream>
# include <Floor.hh>


class		HitBox
{ 
protected:

  AEntity::EntityType	_type;
  glm::vec3	_c1;
  glm::vec3	_c2;
  glm::vec3	_c3;
  glm::vec3	_c4;
  glm::vec3	_c5;
  glm::vec3	_c6;
  glm::vec3	_c7;
  glm::vec3	_c8;

public:
  HitBox(AEntity *entity);
  ~HitBox();

};

#endif // _HITBOX_H_
