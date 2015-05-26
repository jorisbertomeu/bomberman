//
// Sound.hpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:10:43 2015 Joris Bertomeu
// Last update Tue May 26 17:35:37 2015 Geoffrey Merran
//

#ifndef		_SOUND_HH_
# define	_SOUND_HH_

# include	<string>

class		Sound
{
  std::string	filename;

public:
  explicit	Sound(const std::string &filename) {
    (void) filename;
  }

  virtual	~Sound()  {

  }
};

#endif		/* _SOUND_HH_ */
