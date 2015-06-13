//
// MapPreviewer.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 19:46:15 2015 Geoffrey Merran
// Last update Sat Jun 13 21:35:00 2015 Geoffrey Merran
//

#include <MapPreviewer.hh>

MapPreviewer::MapPreviewer(const glm::vec3 & pos, const std::string & texture) : Pavement(pos, texture), _hidden(false), _current(false)
{

}

MapPreviewer::~MapPreviewer()
{

}

void		MapPreviewer::setHidden(const bool & hidden)
{
  this->_hidden = hidden;
}

void	       	MapPreviewer::setCurrent(const bool & current)
{
  this->_current = current;
}


void		MapPreviewer::update(gdl::Clock & clock, Scene* scene)
{
  (void) scene;
  if (this->_current)
    this->rotate(glm::vec3(0, 1, 0), (50 * clock.getElapsed()));
}

void		MapPreviewer::changeMap(const std::string & tpath)
{
  delete this->_textureO;
  this->_textureO = new Texture(tpath);
}

void		MapPreviewer::draw(RenderManager &rm)
{
  if (!this->_hidden)
    {
      this->_textureO->getTexture().bind();
      this->_geometry.draw(rm.getGraphicManager().getContext().getShaders(), getTransformation(), GL_QUADS);
    }
}
