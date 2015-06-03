//
// TimeManager.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Wed Jun  3 21:26:36 2015 Geoffrey Merran
// Last update Wed Jun  3 21:47:53 2015 Geoffrey Merran
//

#ifndef __TIME_MANAGER_HH
# define __TIME_MANAGER_HH
# define FPS 60

# include <unistd.h>
# include <Clock.hh>

class			TimeManager
{
public:
  TimeManager();
  ~TimeManager();

  gdl::Clock&		getClock();
  void			delay() const;

private:
  gdl::Clock		_clock;
};

#endif /* __TIME_MANAGER_HH */
