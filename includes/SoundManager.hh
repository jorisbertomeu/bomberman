//
// SoundManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:07:04 2015 Joris Bertomeu
// Last update Tue Jun  9 22:19:33 2015 Jérémy Mediavilla
//

#ifndef			_SOUNDMANAGER_HH_
# define		_SOUNDMANAGER_HH_

# include		<list>

# include		<Sound.hpp>

class			SoundManager
{
private:
  std::list<Sound>	_sounds;

public:
  explicit		SoundManager();
  virtual		~SoundManager();
  bool			initialize();
  bool			addSound(const Sound &);
  bool			addSoundFromFile(const std::string &);
};

#endif			/* _SOUNDMANAGER_HH_ */
