//
// Bomberman.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 12:18:17 2015 Nicolas Adès
// Last update Thu Jun  4 00:20:14 2015 Geoffrey Merran
//

#include <Bomberman.hh>
#include <Bomb.hh>
#include <SceneManager.hh>

Bomberman::Bomberman(glm::vec3 pos, const std::string &name) : AEntity(pos, AEntity::BOMBERMAN)
{
  std::cout << "New bomberman created : <" << pos.x <<", "<< pos.y << ", "<< pos.z <<"> " << name << std::endl;
  this->_name = name;
  this->_scale = glm::vec3(0.3, 0.3, 0.3);
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
  SceneManager		*scene = new SceneManager();
  Bomb			*newBomb = new Bomb(this->_pos);

  scene->addEntityToCurrentScene(newBomb);
}

void		Bomberman::moveRight()
{
  // glm::vec3	oldPos;
  // glm::vec3	newPos;

  // oldPos = this->getPos();
}

void		Bomberman::moveLeft()
{

}

void		Bomberman::moveBack()
{

}

void		Bomberman::moveFront()
{
  glm::vec3	oldPos;
  glm::vec3	newPos;

  oldPos = this->getPos();
}

void		Bomberman::jump()
{

}

void	       	Bomberman::draw(RenderManager & rm)
{
  gdl::Model*	model = rm.getModelManager().getModel(this->_modelId);

  if (model == NULL)
    throw (std::logic_error(std::string("Can't load bomberman model: ") + this->_modelId));
  model->draw(rm.getGraphicManager().getContext().getShaders(), this->getTransformation(), rm.getTimeManager().getClock().getElapsed() * 2);

}
