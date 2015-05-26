//
// ASolid.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Tue May 26 12:17:57 2015 Nicolas Adès
// Last update Tue May 26 15:47:19 2015 Nicolas Adès
//

#ifndef _ASOLID_H_
# define _ASOLID_H_

# include <AEntity.hh>
# include <HitBox.hh>

class		ASolid : public AEntity, HitBox
{
public:
  typedef enum		solidAbility
    {
      NONE_ABILITY = 0
    }			SolidAbility;
  typedef enum		solidBonus
    {
      NONE_BONUS = 0
    }			SolidBonus;

protected:
  HitBox	_hitBox;
  float		_friction;
  float		_speed;
  float		_range;
  bool		_move;
  ASolid::SolidAbility	_ability;
  ASolid::SolidBonus	_bonus;

public:
  explicit	ASolid();
  virtual	~ASolid();
  virtual bool	checkColision(ASolid *);
  virtual float	getFriction() const;
  virtual void	setFriction(const float &);
  virtual float	getSpeed() const;
  virtual void	setSpeed(const float &);
  virtual float getRange() const;
  virtual void	setRange(const float &);
  virtual bool	getMove() const;
  virtual void	setMove(const bool &);
  virtual ASolid::SolidAbility	getAbility() const;
  virtual void	setAbility(const ASolid::SolidAbility &);
  virtual ASolid::SolidBonus	getBonus() const;
  virtual void	setBonus(const ASolid::SolidBonus &);
};
#endif // _ASOLID_H_
