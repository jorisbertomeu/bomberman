//
// Bomb.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:08:09 2015 Nicolas Adès
// Last update Sun Jun 14 17:37:46 2015 Geoffrey Merran
//

#include <Bomb.hh>

Bomb::Bomb(void* ptr, glm::vec3 pos) : AEntity(pos, AEntity::BOMB), _explodeTime(3.0f), _damage(50)
{
  this->_explodeTime = 3.0f;
  this->_damage = 50;
  this->_modelId = "idBombModel";
  this->setScale(glm::vec3(0.1, 0.1, 0.1));
  this->_parent = ptr;
}

Bomb::~Bomb()
{

}

void		Bomb::explode(Scene* scene)
{
  this->_destroy = true;
  glm::vec3 pos = this->_pos;
  for (int i = 0; i < 2; i++)
    {
      pos.x += 20;
      scene->addEntity(new Fire(pos));
    }
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

bool		Bomb::freshBomb(void *ptr) const
{
  if (this->_parent == ptr && this->_explodeTime >= 1.0f)
    return (true);
  //printf("FreshBomb false cause %p != %p and elapsed = %d\n", this->_parent, ptr, time(NULL) - this->_droppedTime);
  return (false);
}
