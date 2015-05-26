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

# include <glm/glm.hpp>
# include <iostream>

class		HitBox
{
public:
  HitBox();
  ~HitBox();

  glm::vec3	getDimensions();
  void		setDimensions(const glm::vec3 &);

protected:
  glm::vec3	_dimension;
};

#endif // _HITBOX_H_
