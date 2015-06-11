//
// AnimationManager.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Tue May 26 14:52:09 2015 Nicolas Adès
// Last update Sun Jun 14 03:02:42 2015 Nicolas Adès
//

#ifndef	ANIMATION_HH_
# define ANIMATION_HH_

#include <iostream>

class			Animation
{
private:
  std::string		_name;
  bool			_loop;
  
public:
  Animation(const std::string &name, const bool &loop);
  ~Animation();

  std::string		getName() const;
  bool			getLoop() const;
};

#endif // ANIMATION_HH_
