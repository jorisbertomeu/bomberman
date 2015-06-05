//
// Bot.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:12:07 2015 Nicolas Adès
// Last update Wed Jun  3 21:27:49 2015 Geoffrey Merran
//

#include <Bot.hh>

Bot::Bot(glm::vec3, const std::string &name) : AEntity(pos, AEntity::BOT)
{
  std::cout << "New Bot created : <" << pos.x <<", "<< pos.y << ", "<< pos.z <<"> " << name << std::endl;
  this->_name = name;
}

Bot::~Bot()
{

}

std::string	Bot::getName() const
{
  return (this->_name);
}


std::string	Bot::getColor() const
{
  return (this->_color);
}

void		Bot::setColor(const std::string &color)
{
  this->_color = color;
}
