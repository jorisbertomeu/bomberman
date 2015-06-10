//
// Bomberman.cpp for  in /home/parallels/Tek2/CPP/bomberman/src
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Wed May 27 12:18:17 2015 Nicolas Adès
// Last update Wed Jun 10 12:03:10 2015 Joris Bertomeu
//

#include <Bomberman.hh>
#include <Bomb.hh>
#include <SceneManager.hh>
#include <PhysicSolid.hh>

Bomberman::Bomberman(glm::vec3 pos, const std::string &name) : AEntity(glm::vec3(pos.x, pos.y - 0, pos.z), AEntity::BOMBERMAN), _name(name), _dir(DOWN)
{
  std::cout << "New bomberman created : <" << pos.x <<", "<< pos.y << ", "<< pos.z <<"> " << name << std::endl;
  this->_scale = glm::vec3(0.1, 0.1, 0.1);
}

Bomberman::~Bomberman()
{

}

std::string	Bomberman::getName() const
{
  return (this->_name);
}

void		Bomberman::dropBomb(Scene* scene)
{
  scene->addEntity(new Bomb(this->_pos));
}

void		Bomberman::moveRight()
{
  if (this->_dir != RIGHT)
    {
      this->rotate(glm::vec3(0, 1, 0), 90 * (this->_dir - RIGHT));
      this->isTurningBack(this->_dir - RIGHT);
      this->_dir = RIGHT;
    }
  float		acele = this->getAcceleration();
  this->setAcceleration(acele + 0.02);
  this->translate(glm::vec3(1, 0, 0) * (this->_speed * this->getAcceleration()));
  this->_hitbox->updateHitbox(this);
}

void		Bomberman::moveLeft()
{
  if (this->_dir != LEFT)
    {
      this->rotate(glm::vec3(0, 1, 0), 90 * (this->_dir - LEFT));
      this->isTurningBack(this->_dir - LEFT);
      this->_dir = LEFT;
    }
  float		acele = this->getAcceleration();
  this->setAcceleration(acele + 0.02);
  this->translate(glm::vec3(-1, 0, 0) * (this->_speed * this->getAcceleration()));
  this->_hitbox->updateHitbox(this);
}

void		Bomberman::moveBack()
{
  if (this->_dir != DOWN)
    {
      this->rotate(glm::vec3(0, 1, 0), 90 * (this->_dir - DOWN));
      this->isTurningBack(this->_dir - DOWN);
      this->_dir = DOWN;
    }
  float		acele = this->getAcceleration();
  this->setAcceleration(acele + 0.02);
  this->translate(glm::vec3(0, 0, 1) * (this->_speed * this->getAcceleration()));
  this->_hitbox->updateHitbox(this);
}

void		Bomberman::moveFront()
{
  if (this->_dir != UP)
    {
      this->rotate(glm::vec3(0, 1, 0), 90 * (this->_dir - UP));
      this->isTurningBack(this->_dir - UP);
      this->_dir = UP;
    }
  float		acele = this->getAcceleration();
  this->setAcceleration(acele + 0.02);
  this->translate(glm::vec3(0, 0, -1) * (this->_speed * this->getAcceleration()));
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

  if (model == NULL)
    throw (std::logic_error(std::string("Can't load bomberman model: ") + this->_modelId));
  model->draw(rm.getGraphicManager().getContext().getShaders(), this->getTransformation(), rm.getTimeManager().getClock().getElapsed());
}

void		Bomberman::update(gdl::Clock & clock, Scene *scene)
{
  // gdl::Model*	model = rm.getModelManager().getModel(this->_modelId);

  // if (this->getAcceleration <= 0)
  //   model.setCurrentAnim("stop", false);
  (void) clock;
  (void)scene;
}

void		Bomberman::isReleased(Scene *scene)
{
  glm::vec3	old = this->_pos;

  if (this->getAcceleration() <= 0)
    return;
  this->setAcceleration(this->getAcceleration() - 0.05);
  switch (this->_dir)
    {
    case (Bomberman::UP) :
      this->translate(glm::vec3(0, 0, -1) * (this->_speed * this->getAcceleration()));
      this->_hitbox->updateHitbox(this);
      break;
    case (Bomberman::RIGHT) :
      this->translate(glm::vec3(1, 0, 0) * (this->_speed * this->getAcceleration()));
      this->_hitbox->updateHitbox(this);
      break;
    case (Bomberman::DOWN) :
      this->translate(glm::vec3(0, 0, 1) * (this->_speed * this->getAcceleration()));
      this->_hitbox->updateHitbox(this);
      break;
    case (Bomberman::LEFT) :
      this->translate(glm::vec3(-1, 0, 0) * (this->_speed * this->getAcceleration()));
      this->_hitbox->updateHitbox(this);
      break;
    }
  if (this->getHitbox()->checkCollision(scene)) {
    this->setPos(old);
    this->setAcceleration(0.0f);
  }
}
