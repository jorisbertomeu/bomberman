//
// PhysicSolid.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Tue May 26 12:33:04 2015 Nicolas Adès
// Last update Tue May 26 12:46:19 2015 Nicolas Adès
//

#ifndef _PHYSICSOLID_H_
# define _PHYSICSOLID_H_

# include <ASolid.hh>

class		PhysicSolid : public ASolid
{
public:
  PhysicSolid();
  ~PhysicSolid();
  glm::vec3	getAcceleration();
  void		setAcceleration(const glm::vec3 &);
  float		getWeight();
  void		setWeight(const float &);

protected:
  glm::vec3	_acceleration;
  float		_weight;
};

#endif // _PHYSICSOLID_H_
