//
// Pavement.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Jun  9 10:21:36 2015 Joris Bertomeu
// Last update Wed Jun 10 16:02:27 2015 Joris Bertomeu
//

#include	<Pavement.hh>

Pavement::Pavement(const glm::vec3 &pos, const std::string& texture) : AEntity(pos, AEntity::PAVEMENT)
{
  _textureO = new Texture(texture);
  this->buildObject();
}

Pavement::Pavement(const glm::vec3 &pos, Texture* t) : AEntity(pos, AEntity::PAVEMENT)
{
  if (t == NULL)
    throw(std::logic_error("Error while loading Texture for Pavement"));
  _textureO = t;
  this->buildObject();
}

Pavement::~Pavement()
{

}

void		Pavement::buildObject()
{
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  // Les UVs d'une premiere face
  _geometry.pushUv(glm::vec2(0.01f, 0.01f));
  _geometry.pushUv(glm::vec2(0.99f, 0.01f));
  _geometry.pushUv(glm::vec2(0.99f, 0.99f));
  _geometry.pushUv(glm::vec2(0.01f, 0.99f));
  // ETC ETC
  //_geometry.setColor(glm::vec4(1, 1, 0, 1));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(0.01f, 0.01f));
  _geometry.pushUv(glm::vec2(0.99f, 0.01f));
  _geometry.pushUv(glm::vec2(0.99f, 0.99f));
  _geometry.pushUv(glm::vec2(0.01f, 0.99f));
  //  _geometry.setColor(glm::vec4(0, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushUv(glm::vec2(0.01f, 0.01f));
  _geometry.pushUv(glm::vec2(0.99f, 0.01f));
  _geometry.pushUv(glm::vec2(0.99f, 0.99f));
  _geometry.pushUv(glm::vec2(0.01f, 0.99f));
  //_geometry.setColor(glm::vec4(1, 0, 1, 1));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(0.01f, 0.01f));
  _geometry.pushUv(glm::vec2(0.99f, 0.01f));
  _geometry.pushUv(glm::vec2(0.99f, 0.99f));
  _geometry.pushUv(glm::vec2(0.01f, 0.99f));
  //_geometry.setColor(glm::vec4(0, 1, 0, 1));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushUv(glm::vec2(0.01f, 0.01f));
  _geometry.pushUv(glm::vec2(0.99f, 0.01f));
  _geometry.pushUv(glm::vec2(0.99f, 0.99f));
  _geometry.pushUv(glm::vec2(0.01f, 0.99f));
  //_geometry.setColor(glm::vec4(0, 0, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(0.01f, 0.01f));
  _geometry.pushUv(glm::vec2(0.99f, 0.01f));
  _geometry.pushUv(glm::vec2(0.99f, 0.99f));
  _geometry.pushUv(glm::vec2(0.01f, 0.99f));
  this->_geometry.build();
  this->_hitbox = new Hitbox(this);
}

Hitbox		*Pavement::getHitbox() const
{
  return (this->_hitbox);
}

float		Pavement::getHeigth()
{
  return (0.5 * this->getScale().y);
}

float		Pavement::getWidth()
{
  return (0.5 * this->getScale().x);
}

float		Pavement::getDepth()
{
  return (0.5 * this->getScale().z);
}

void		Pavement::draw(RenderManager &rm)
{
  this->_textureO->getTexture().bind();
  this->_geometry.draw(rm.getGraphicManager().getContext().getShaders(), getTransformation(), GL_QUADS);
}

void		Pavement::update(gdl::Clock & clock, Scene *scene)
{
  (void)scene;
  (void) clock;
}
