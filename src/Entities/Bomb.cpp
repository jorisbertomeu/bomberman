//
// Bomb.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:08:09 2015 Nicolas Adès
// Last update Sun Jun 14 05:05:47 2015 Jérémy Mediavilla
//

#include <Bomb.hh>

Bomb::Bomb(glm::vec3 pos) : AEntity(pos, AEntity::BOMB)
{
  this->_explodeTime = 4;
  this->_damage = 50;
  this->_modelId = "idBombModel";
  this->setScale(glm::vec3(0.1, 0.1, 0.1));
}

Bomb::~Bomb()
{

}

void		Bomb::explode() const
{

}

int		Bomb::getDamage() const
{
  return (this->_damage);
}

void		Bomb::setDamage(const int &damage)
{
  this->_damage = damage;
}

void		Bomb::draw(RenderManager & rm)
{
  gdl::Model*	model = rm.getModelManager().getModel(this->_modelId);

  if (model == NULL)
    throw (std::logic_error(std::string("Can't load model brickwall:  ") + this->_modelId));
  model->draw(rm.getGraphicManager().getContext().getShaders(), this->getTransformation(), 0);
  (void) rm;
}

void		Bomb::update(gdl::Clock & clock, Scene *scene)
{
  this->_explodeTime -= 1;
  (void)scene;
  (void) clock;
}
