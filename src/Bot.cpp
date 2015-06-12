//
// Bot.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:12:07 2015 Nicolas Adès
// Last update Fri Jun 12 17:04:27 2015 Jérémy Mediavilla
//

#include <Bot.hh>

Bot::Bot(glm::vec3 pos, const std::string &name) : Bomberman(pos, name)
{
  std::cout << "New Bot created : <" << pos.x <<", "<< pos.y << ", "<< pos.z <<"> " << name << std::endl;
  this->_name = name;
}

Bot::~Bot()
{

}

// std::string	Bot::getName() const
// {
//   return (this->_name);
// }


std::string	Bot::getColor() const
{
  return (this->_color);
}

void		Bot::setColor(const std::string &color)
{
  this->_color = color;
}

void		Bot::ia(SceneManager *sm)
{
  Scene		*scene;

  scene = sm->getCurrentScene();
}
