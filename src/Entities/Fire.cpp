//
// Fire.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sun Jun 14 17:29:50 2015 Geoffrey Merran
// Last update Sun Jun 14 17:48:39 2015 Geoffrey Merran
//

#include <Fire.hh>

Fire::Fire(glm::vec3 pos) : AEntity(pos, AEntity::FIRE), _fireTime(1.0f)
{
  this->_modelId = "idFirebModel";
  this->_scale = glm::vec3(0.1, 0.1, 0.1);
}

Fire::~Fire()
{

}

void			Fire::draw(RenderManager & rm)
{
  gdl::Model*	model = rm.getModelManager().getModel(this->_modelId);

  if (model != NULL)
    model->draw(rm.getGraphicManager().getContext().getShaders(), this->getTransformation(), 0);
}

void			Fire::update(gdl::Clock & clock, Scene *)
{
  this->_fireTime -= clock.getElapsed();
  if (this->_fireTime <= 0)
    this->_destroy = true;
}
