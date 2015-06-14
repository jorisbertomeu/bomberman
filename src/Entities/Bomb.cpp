//
// Bomb.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:08:09 2015 Nicolas Adès
// Last update Sun Jun 14 08:49:10 2015 Geoffrey Merran
//

#include <Bomb.hh>

Bomb::Bomb(glm::vec3 pos) : AEntity(pos, AEntity::BOMB), _explodeTime(3.0f), _damage(50)
{
  this->_explodeTime = 3.0f;
  this->_damage = 50;
  this->_modelId = "idBombModel";
  this->setScale(glm::vec3(0.1, 0.1, 0.1));
}

Bomb::~Bomb()
{

}

void		Bomb::explode(Scene*)
{
  this->_destroy = true;
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
  if (this->_destroy)
    return ;
  gdl::Model*	model = rm.getModelManager().getModel(this->_modelId);
  if (model == NULL)
    throw (std::logic_error(std::string("Can't load model brickwall:  ") + this->_modelId));
  model->draw(rm.getGraphicManager().getContext().getShaders(), this->getTransformation(), 0);
  model->setCurrentAnim(0, true);
}

void		Bomb::update(gdl::Clock & clock, Scene *scene)
{
  this->_explodeTime -= clock.getElapsed();
  if (this->_explodeTime <= 0)
    this->explode(scene);
  (void) scene;
  (void) clock;
}
