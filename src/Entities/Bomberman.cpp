//
// Bomberman.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 12:18:17 2015 Nicolas Adès
// Last update Sat Jun  6 18:01:21 2015 Geoffrey Merran
//

#include <Bomberman.hh>
#include <Bomb.hh>
#include <SceneManager.hh>

Bomberman::Bomberman(glm::vec3 pos, const std::string &name) : AEntity(pos, AEntity::BOMBERMAN), _name(name), _dir(DOWN)
{
  std::cout << "New bomberman created : <" << pos.x <<", "<< pos.y << ", "<< pos.z <<"> " << name << std::endl;
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
  if (this->_dir != RIGHT)
    {
      this->rotate(glm::vec3(0, 1, 0), 90 * (this->_dir - RIGHT));
      this->_dir = RIGHT;
    }
  this->translate(glm::vec3(1, 0, 0) * this->_speed);
}

void		Bomberman::moveLeft()
{
  if (this->_dir != LEFT)
    {
      this->rotate(glm::vec3(0, 1, 0), 90 * (this->_dir - LEFT));
      this->_dir = LEFT;
    }
  this->translate(glm::vec3(-1, 0, 0) * this->_speed);
}

void		Bomberman::moveBack()
{
  if (this->_dir != DOWN)
    {
      this->rotate(glm::vec3(0, 1, 0), 90 * (this->_dir - DOWN));
      this->_dir = DOWN;
    }
  this->translate(glm::vec3(0, 0, 1) * this->_speed);
}

void		Bomberman::moveFront()
{
  if (this->_dir != UP)
    {
      this->rotate(glm::vec3(0, 1, 0), 90 * (this->_dir - UP));
      this->_dir = UP;
    }
  this->translate(glm::vec3(0, 0, -1) * this->_speed);
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
