//
// Bomberman.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <parallels@epitech.net>
// 
// Started on  Tue May 26 14:52:09 2015 Nicolas Adès
// Last update Mon Jun  1 17:55:59 2015 Geoffrey Merran
//

#ifndef _BOMBERMAN_H_
# define _BOMBERMAN_H_

# include <AEntity.hh>

class		Bomberman : public AEntity
{
protected:
  std::string	_name;

public:
  Bomberman(glm::vec3 pos, const std::string &name);
  ~Bomberman();
  
  std::string	getName() const;
  void		dropBomb();
  void		moveRight();
  void		moveLeft();
  void		moveBack();
  void		moveFront();
  void		jump();
  virtual void 	draw();
};

#endif // _BOMBERMAN_H_
