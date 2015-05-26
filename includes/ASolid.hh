//
// ASolid.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Tue May 26 12:17:57 2015 Nicolas Adès
// Last update Tue May 26 12:48:31 2015 Nicolas Adès
//

#ifndef _ASOLID_H_
# define _ASOLID_H_

# include <AEntity.hh>
# include <HitBox.hh>

class		ASolid : public AEntity, HitBox
{
public:
  explicit	ASolid();
  virtual	~ASolid();
  virtual bool	checkColision(ASolid *);

protected:
  HitBox	_hitBox;
  float		_friction;
};
#endif // _ASOLID_H_
