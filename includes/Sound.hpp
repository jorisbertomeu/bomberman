//
// Sound.hpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:10:43 2015 Joris Bertomeu
// Last update Wed Jun 10 10:58:03 2015 Joris Bertomeu
//

#ifndef				_SOUND_HH_
# define			_SOUND_HH_

# include			<string>
# include			<fmod.h>
# include			<iostream>

class				Sound
{
public:
  typedef enum			soundType
    {
      UNKNOWN			= 0,
      WALK			= 1,
      EXPLOSION			= 2,
      WALK_STOP			= 3,
      DESTRUCTION		= 4,
      DEAD			= 5,
      AMBIANT			= 6,
      JUMP			= 7
    }				SoundType;

protected:
  std::string			_filename;
  bool				_online;
  SoundType			_type;
  FMOD_SOUND			*_rawSound;
  FMOD_SYSTEM			*_system;

public:
  explicit			Sound(const Sound::SoundType &type, const bool &online, const std::string &filename, FMOD_SYSTEM *system) {
    this->_filename = filename;
    this->_online = online;
    this->_type = type;
    this->_system = system;
    if (this->_type == Sound::AMBIANT) {
      if (FMOD_System_CreateSound(this->_system, filename.c_str(), FMOD_2D | FMOD_CREATESTREAM, 0, &(this->_rawSound)) != FMOD_OK) {
	std::cerr << "Unable to load sound " << filename << std::endl;
	this->_rawSound = NULL;
      }
    } else
      if (FMOD_System_CreateSound(this->_system, filename.c_str(), FMOD_CREATESAMPLE, 0, &(this->_rawSound)) != FMOD_OK) {
	std::cerr << "Unable to load sound " << filename << std::endl;
	this->_rawSound = NULL;
      }
  }

  virtual			~Sound() {

  }

  std::string			getFilename() const {
    return (this->_filename);
  }

  bool				getOnline() const {
    return (this->_online);
  }

  SoundType			getType() const {
    return (this->_type);
  }

  void				setFilename(const std::string &filename) {
    this->_filename = filename;
  }

  void				setOnline(const bool & online) {
    this->_online = online;
  };

  void				setType(const SoundType &type) {
    this->_type = type;
  };

  void				play() {
    if (this->_rawSound) {
      std::cerr << "Unable to play Sound" << std::endl;
      return;
    }
    FMOD_System_PlaySound(this->_system, this->_rawSound, NULL, 0, NULL);
  };
};

#endif				/* _SOUND_HH_ */
