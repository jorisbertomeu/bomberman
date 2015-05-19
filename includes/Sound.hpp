//
// Sound.hpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:10:43 2015 Joris Bertomeu
// Last update Tue May 19 11:17:24 2015 Joris Bertomeu
//

#ifndef		_SOUND_HH_
# define	_SOUND_HH_

# include	<string>

class		Sound
{
  std::string	filename;

public:
  explicit	Sound(const std::string &filename) {

  }

  virtual	~Sound()  {

  }
};

#endif		/* _SOUND_HH_ */
