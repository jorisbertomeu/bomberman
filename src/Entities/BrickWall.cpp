//
// BrickWall.cpp for  in /home/parallels/Tek2/CPP/bomberman
// 
// Made by Nicolas Adès
// Login   <parallels@epitech.net>
// 
// Started on  Wed May 27 13:17:23 2015 Nicolas Adès
// Last update Sat Jun 13 04:47:52 2015 Geoffrey Merran
//

#include <BrickWall.hh>

BrickWall::BrickWall(glm::vec3 pos) : AEntity(pos, AEntity::BRICKWALL)
{
}

BrickWall::~BrickWall()
{

}

void	       	BrickWall::draw(RenderManager & rm)
{
  gdl::Model*	model = rm.getModelManager().getModel(this->_modelId);

  if (model == NULL)
    throw (std::logic_error(std::string("Can't load model brickwall:  ") + this->_modelId));
  model->draw(rm.getGraphicManager().getContext().getShaders(), this->getTransformation(), 0);
}

void		BrickWall::update(gdl::Clock & clock, Scene *scene)
{
  (void)scene;
  (void) clock;
}
