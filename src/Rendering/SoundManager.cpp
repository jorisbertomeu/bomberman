//
// SoundManager.cpp for  in /home/merran_g/work/rendu/bomberman
//
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
//
// Started on  Tue May 26 17:39:02 2015 Geoffrey Merran
// Last update Sun Jun 14 12:48:46 2015 Jérémy Mediavilla
//

#include <SoundManager.hh>

SoundManager::SoundManager()
{
  FMOD_System_Create(&(this->_system));
  FMOD_System_Init(this->_system, 1, FMOD_INIT_NORMAL, NULL);
}

SoundManager::~SoundManager()
{

}

bool		SoundManager::initialize()
{
  return (true);
}

bool		SoundManager::addSound(Sound *sound)
{
  std::cout << "Sound added" << std::endl;
  this->_sounds.push_back(sound);
  return (true);
}

bool		SoundManager::addSoundFromFile(const std::string &filename, const Sound::SoundType &type)
{
  Sound		*sound;

  sound = new Sound(type, false, filename, this->_system);
  this->addSound(sound);
  return (true);
}

FMOD_SYSTEM	*SoundManager::getSystem() const
{
  return (this->_system);
}

Sound		*SoundManager::getSoundOf(Sound::soundType type)
{
  if (this->_sounds.size() == 0)
    return (NULL);
  for (std::list<Sound*>::iterator it = this->_sounds.begin(); it != this->_sounds.end(); ++it) {
    if ((*it)->getType() == type)
      {
	return ((*it));
      }
  }
  return (NULL);
}
