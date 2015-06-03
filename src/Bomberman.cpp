//
// Bomberman.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 12:18:17 2015 Nicolas Adès
// Last update Wed Jun  3 18:03:23 2015 Nicolas Adès
//

#include <Bomberman.hh>
#include <Bomb.hh>
#include <SceneManager.hh>

Bomberman::Bomberman(glm::vec3 pos, const std::string &name) : AEntity(pos, AEntity::BOMBERMAN)
{
  std::cout << "New bomberman created : <" << pos.x <<", "<< pos.y << ", "<< pos.z <<"> " << name << std::endl;
  this->_name = name;
}

Bomberman::~Bomberman()
{

}

std::string	Bomberman::getName() const
{
  return (this->_name);
}

void		Bomberman::dropBomb()
{
  Bomb		newBomb(this->_pos);

  //addEntityToCurrentScene(newBomb);
}

void		Bomberman::moveRight()
{

}

void		Bomberman::moveLeft()
{

}

void		Bomberman::moveBack()
{

}

void		Bomberman::moveFront()
{

}

void		Bomberman::jump()
{

}

void	       	Bomberman::draw(const RenderManager & rm)
{
  gdl::Model*	model = rm.getModelManager().getModel("bomberman");

  model->draw(rm.getGraphicManager().getContext().getShaders(), this->getTransformation(), 0);
}
