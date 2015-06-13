//
// Animation.cpp for  in /home/parallels/Tek2/CPP/bomberman/src/Rendering
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Tue May 26 14:52:09 2015 Nicolas Adès
// Last update Sun Jun 14 03:02:42 2015 Nicolas Adès
//

#include <Animation.hh>

Animation::Animation(const std::string &name, const bool &loop)
{
  this->_name = name;
  this->_loop = loop;
}

Animation::~Animation()
{

}

std::string		Animation::getName() const
{
  return (this->_name);
}

bool			Animation::getLoop() const
{
  return (this->_loop);
}
