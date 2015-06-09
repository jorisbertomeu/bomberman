//
// SoundManager.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Tue May 26 17:39:02 2015 Geoffrey Merran
// Last update Tue Jun  9 22:19:22 2015 Jérémy Mediavilla
//

#include <SoundManager.hh>

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{

}

bool		SoundManager::initialize()
{
  return (true);
}

bool		SoundManager::addSound(const Sound &sound)
{
  this->_sounds.push_back(sound);
  return (true);
}

bool		SoundManager::addSoundFromFile(const std::string &filename)
{
  (void) filename;
  return (true);
}
