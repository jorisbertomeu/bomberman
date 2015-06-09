//
// ASolid.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Tue May 26 12:17:57 2015 Nicolas Adès
// Last update Tue Jun  9 19:10:25 2015 Jérémy Mediavilla
//

#ifndef _ASOLID_H_
# define _ASOLID_H_

# include <HitBox.hh>
# include <PhysicSolid.hh>

class				ASolid : public HitBox, PhysicSolid
{
public:
  typedef enum			solidAbility
    {
      NONE_ABILITY		= 0
    }				SolidAbility;
  typedef enum			solidBonus
    {
      NONE_BONUS		= 0
    }				SolidBonus;

protected:
  HitBox			_hitBox;
  float				_friction;
  float				_speed;
  float				_range;
  int				_weight;
  int				_health;
  bool				_move;
  bool				_jump;
  std::string			_texture;
  glm::vec3			_size;
  ASolid::SolidAbility		_ability;
  ASolid::SolidBonus		_bonus;

public:
  explicit			ASolid();
  virtual			~ASolid();
  virtual bool			checkColision(ASolid *);
  virtual float			getFriction() const;
  virtual void			setFriction(const float &);
  virtual float			getSpeed() const;
  virtual void			setSpeed(const float &);
  virtual float			getRange() const;
  virtual void			setRange(const float &);
  virtual int			getWeight() const;
  virtual void			setWeight(const int &);
  virtual int			getHealth() const;
  virtual void			setHealth(const int &);
  virtual bool			getMove() const;
  virtual void			setMove(const bool &);
  virtual bool			getJump() const;
  virtual void			setJump(const bool &);
  virtual std::string		getTexture() const;
  virtual void			setTexture(const std::string &);
  virtual ASolid::SolidAbility	getAbility() const;
  virtual void			setAbility(const ASolid::SolidAbility &);
  virtual ASolid::SolidBonus	getBonus() const;
  virtual void			setBonus(const ASolid::SolidBonus &);
  virtual glm::vec3		getSize();
  virtual void			setSize(const glm::vec3 &);
};
#endif // _ASOLID_H_
