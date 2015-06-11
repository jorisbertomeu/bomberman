//
// WoodWall.cpp for  in /home/parallels/Tek2/CPP/bomberman
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:13:09 2015 Nicolas Adès
// Last update Sun Jun 14 10:42:03 2015 Jérémy Mediavilla
//

#include <WoodWall.hh>

WoodWall::WoodWall(glm::vec3 pos) : AEntity(pos, AEntity::WOODWALL)
{

}

WoodWall::~WoodWall()
{

}

void	WoodWall::draw(RenderManager & rm)
{
  gdl::Model*	model = rm.getModelManager().getModel(this->_modelId);

  if (model == NULL)
    throw (std::logic_error(std::string("Can't load model brickwall:  ") + this->_modelId));
  model->draw(rm.getGraphicManager().getContext().getShaders(), this->getTransformation(), 0);
}

void	WoodWall::update(gdl::Clock & clock, Scene *scene)
{
  (void)scene;
  (void) clock;
}
