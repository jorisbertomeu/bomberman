//
// Bomberman.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <parallels@epitech.net>
// 
// Started on  Tue May 26 14:52:09 2015 Nicolas Adès
// Last update Wed May 27 13:03:38 2015 Nicolas Adès
//

#ifndef _BOMBERMAN_H_
# define _BOMBERMAN_H_
# include <AEntity.hh>

class		Bomberman : public AEntity
{
public:
  Bomberman();
  ~Bomberman();
  
  std::string	getName() const;
  void		dropBomb();

protected:
  std::string	_name;
};

#endif // _BOMBERMAN_H_
