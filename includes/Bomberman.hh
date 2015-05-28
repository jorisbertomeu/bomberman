//
// Bomberman.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <parallels@epitech.net>
// 
// Started on  Tue May 26 14:52:09 2015 Nicolas Adès
// Last update Thu May 28 14:43:20 2015 Nicolas Adès
//

#ifndef _BOMBERMAN_H_
# define _BOMBERMAN_H_

# include <AEntity.hh>

class		Bomberman : public AEntity
{
public:
  Bomberman(glm::vec3 pos, const std::string &name);
  ~Bomberman();
  
  std::string	getName() const;
  void		dropBomb();

protected:
  std::string	_name;
};

#endif // _BOMBERMAN_H_
