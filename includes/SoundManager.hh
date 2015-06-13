//
// SoundManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:07:04 2015 Joris Bertomeu
// Last update Wed Jun 10 21:40:13 2015 Joris Bertomeu
//

#ifndef			_SOUNDMANAGER_HH_
# define		_SOUNDMANAGER_HH_

# include		<list>

# include		<Sound.hpp>
# include		<ThreadC.hpp>

class			SoundManager
{
private:
  std::list<Sound*>	_sounds;
  FMOD_SYSTEM		*_system;

public:
  explicit		SoundManager();
  virtual		~SoundManager();
  bool			initialize();
  bool			addSound(Sound *);
  bool			addSoundFromFile(const std::string &, const Sound::SoundType &);
  FMOD_SYSTEM		*getSystem() const;
  Sound			*getSoundOf(Sound::SoundType type);
};

#endif			/* _SOUNDMANAGER_HH_ */
