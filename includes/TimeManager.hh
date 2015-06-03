//
// TimeManager.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Wed Jun  3 21:26:36 2015 Geoffrey Merran
// Last update Wed Jun  3 23:58:29 2015 Geoffrey Merran
//

#ifndef __TIME_MANAGER_HH
# define __TIME_MANAGER_HH
# define FPS 60

# include <iostream>
# include <unistd.h>
# include <Clock.hh>

class			TimeManager
{
public:
  TimeManager();
  ~TimeManager();

  gdl::Clock&		getClock();
  void			delay() const;
  void			printFps();

private:
  gdl::Clock		_clock;
  int			_fpsTimeCounter;
  int			_fpsPrevTime;
  int			_fps;
};

#endif /* __TIME_MANAGER_HH */
