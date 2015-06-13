//
// Bomb.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:08:09 2015 Nicolas Adès
// Last update Sun Jun 14 10:12:32 2015 Jérémy Mediavilla
//

#include <Bomb.hh>

Bomb::Bomb(void *ptr, glm::vec3 pos) : AEntity(pos, AEntity::BOMB)
{
  this->_explodeTime = 4.0f;
  this->_damage = 50;
  this->_modelId = "idBombModel";
  this->setScale(glm::vec3(0.1, 0.1, 0.1));
  this->_parent = ptr;
  this->_droppedTime = time(NULL);
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

bool		Bomb::freshBomb(void *ptr) const
{
  if (this->_parent == ptr && time(NULL) - this->_droppedTime <= 1)
    return (true);
  return (false);
}
