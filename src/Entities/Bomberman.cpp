//
// Bomberman.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Wed May 27 12:18:17 2015 Nicolas Adès
// Last update Sun Jun 14 03:31:26 2015 Geoffrey Merran
//

#include <Bomberman.hh>
#include <Bomb.hh>
#include <SceneManager.hh>
#include <PhysicSolid.hh>

Bomberman::Bomberman(glm::vec3 pos, const std::string &name, ModelManager& m) : AEntity(glm::vec3(pos.x, pos.y - 0, pos.z), AEntity::BOMBERMAN), _init(false), _currentAnim(""), _animToDisplay(""), _modelManager(m), _nbBombs(1), _fireRange(2), _name(name), _dir(DOWN)
{
  std::cout << "New bomberman created : <" << pos.x <<", "<< pos.y << ", "<< pos.z <<"> " << name << std::endl;
  this->_scale = glm::vec3(0.1, 0.1, 0.1);
}

Bomberman::~Bomberman()
{

}

void		Bomberman::initialize()
{
  gdl::Model*	model = this->_modelManager.getModel(this->_modelId);

  if (model == NULL)
    throw (std::logic_error(std::string("Can't load bomberman model: ") + this->_modelId));
  model->createSubAnim(0, "run", 13, 60);
  model->createSubAnim(0, "stop", 60, 120);
  this->_init = true;
}

std::string	Bomberman::getName() const
{
  return (this->_name);
}

void		Bomberman::dropBomb(Scene* scene)
{
  scene->addEntity(new Bomb(this->_pos));
}

void		Bomberman::moveRight(gdl::Clock& clock)
{
  this->_animToDisplay = "run";
  if (this->_dir != RIGHT)
    {
      this->rotate(glm::vec3(0, 1, 0), 90 * (this->_dir - RIGHT));
      this->isTurningBack(this->_dir - RIGHT);
      this->_dir = RIGHT;
    }
  float		acele = this->getAcceleration();
  this->setAcceleration(acele + 0.03);
  this->translate((glm::vec3(1, 0, 0) * ((this->_speed * this->getAcceleration()) - this->getFriction())) * static_cast<float>(clock.getElapsed()));
  this->_hitbox->updateHitbox(this);
}

void		Bomberman::moveLeft(gdl::Clock& clock)
{
  this->_animToDisplay = "run";
  if (this->_dir != LEFT)
    {
      this->rotate(glm::vec3(0, 1, 0), 90 * (this->_dir - LEFT));
      this->isTurningBack(this->_dir - LEFT);
      this->_dir = LEFT;
    }
  float		acele = this->getAcceleration();
  this->setAcceleration(acele + 0.02);
  this->translate((glm::vec3(-1, 0, 0) * ((this->_speed * this->getAcceleration()) - this->getFriction())) * static_cast<float>(clock.getElapsed()));
  this->_hitbox->updateHitbox(this);
}

void		Bomberman::moveBack(gdl::Clock& clock)
{
  this->_animToDisplay = "run";
  if (this->_dir != DOWN)
    {
      this->rotate(glm::vec3(0, 1, 0), 90 * (this->_dir - DOWN));
      this->isTurningBack(this->_dir - DOWN);
      this->_dir = DOWN;
    }
  float		acele = this->getAcceleration();
  this->setAcceleration(acele + 0.02);
  this->translate((glm::vec3(0, 0, 1) * ((this->_speed * this->getAcceleration()) - this->getFriction())) * static_cast<float>(clock.getElapsed()));
  this->_hitbox->updateHitbox(this);
}

void		Bomberman::moveFront(gdl::Clock& clock)
{
  this->_animToDisplay = "run";
  if (this->_dir != UP)
    {
      this->rotate(glm::vec3(0, 1, 0), 90 * (this->_dir - UP));
      this->isTurningBack(this->_dir - UP);
      this->_dir = UP;
    }
  float		acele = this->getAcceleration();
  this->setAcceleration(acele + 0.02);
  this->translate((glm::vec3(0, 0, -1) * ((this->_speed * this->getAcceleration()) - this->getFriction())) * static_cast<float>(clock.getElapsed()));
  this->_hitbox->updateHitbox(this);
}

void		Bomberman::isTurningBack(const int & d)
{
  if (d == 2 || d == -2)
    this->setAcceleration(0.0f);
}

void		Bomberman::jump()
{
  std::cout << "Bomberman : " << this->getName() << " jump" << std::endl;
}

void	       	Bomberman::draw(RenderManager & rm)
{
  gdl::Model*	model = rm.getModelManager().getModel(this->_modelId);

  model->draw(rm.getGraphicManager().getContext().getShaders(), this->getTransformation(), rm.getTimeManager().getClock().getElapsed());
}

void		Bomberman::update(gdl::Clock & clock, Scene *scene)
{
  (void) clock;
  (void) scene;
  if (!this->_init)
    this->initialize();
  gdl::Model*	model = this->_modelManager.getModel(this->_modelId);
  if (this->_animToDisplay != this->_currentAnim)
    {
      this->_currentAnim = this->_animToDisplay;
      if (this->_animToDisplay == "run")
      	model->setCurrentSubAnim(this->_animToDisplay, true);
      if (this->_animToDisplay == "stop")
      	model->setCurrentSubAnim(this->_animToDisplay, false);
    }
}

void		Bomberman::isReleased(Scene *scene, gdl::Clock &clock)
{
  glm::vec3	old = this->_pos;

  this->_animToDisplay = "stop";
  if (this->getAcceleration() <= 0.01)
    return;
  this->setAcceleration(this->getAcceleration() - this->getFriction());
  switch (this->_dir)
    {
    case (Bomberman::UP) :
      this->translate(glm::vec3(0, 0, -1) * (this->_speed * this->getAcceleration()) * static_cast<float>(clock.getElapsed()));
      this->_hitbox->updateHitbox(this);
      break;
    case (Bomberman::RIGHT) :
      this->translate(glm::vec3(1, 0, 0) * (this->_speed * this->getAcceleration()) * static_cast<float>(clock.getElapsed()));
      this->_hitbox->updateHitbox(this);
      break;
    case (Bomberman::DOWN) :
      this->translate(glm::vec3(0, 0, 1) * (this->_speed * this->getAcceleration()) * static_cast<float>(clock.getElapsed()));
      this->_hitbox->updateHitbox(this);
      break;
    case (Bomberman::LEFT) :
      this->translate(glm::vec3(-1, 0, 0) * (this->_speed * this->getAcceleration()) * static_cast<float>(clock.getElapsed()));
      this->_hitbox->updateHitbox(this);
      break;
    }
  if (this->getHitbox()->checkCollision(scene)) {
    this->setPos(old);
    this->setAcceleration(0.01f);
  }
}
