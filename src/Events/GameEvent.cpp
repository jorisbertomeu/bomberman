//
// Event.cpp for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:43:17 2015 mari_f
// Last update Sun Jun 14 08:47:21 2015 Geoffrey Merran
//

#include		<GameEvent.hh>
#include		<Pavement.hh>
#include		<MainMenu.hh>

GameEvent::GameEvent()
{
  this->_events[SDLK_UP] = &GameEvent::up;
  this->_events[SDLK_DOWN] = &GameEvent::down;
  this->_events[SDLK_LEFT] = &GameEvent::left;
  this->_events[SDLK_RIGHT] = &GameEvent::right;
  this->_events[SDLK_SPACE] = &GameEvent::space;
  this->_events[SDLK_ESCAPE] = &GameEvent::escape;
}

GameEvent::~GameEvent()
{

}

bool			GameEvent::isCatch(gdl::Input &input, gdl::Clock& clock, SceneManager* sm, CameraManager& camera)
{
  Scene			*scene = sm->getCurrentScene();

  this->_clock = clock;
  this->_camera = camera;
  for (std::map<int, GameEvent::eventHandler>::iterator found = this->_events.begin(); found != this->_events.end(); found++)
    {
      if (input.getKey((*found).first))
	{
	  (this->*this->_events[(*found).first])(sm);
	  return (true);
	}
    }
  Bomberman*		bomberman = static_cast<Bomberman*>(scene->getBomberman());
  bomberman->isReleased(scene, clock);
  this->updatePlayerCamera(bomberman->getPos());
  return (false);

}

void			GameEvent::updatePlayerCamera(const glm::vec3 & point)
{
  this->_camera.moveTo(this->_camera.getDefaultPos() + point, point);
}

void			GameEvent::up(SceneManager* sm)
{
  glm::vec3		bomberman_position_old;
  Scene			*scene = sm->getCurrentScene();
  Bomberman*		bomberman = static_cast<Bomberman*>(scene->getBomberman());

  bomberman_position_old = bomberman->getPos();
  bomberman->moveFront(this->_clock);
  if (bomberman->getHitbox()->checkCollision(scene))
    bomberman->setPos(bomberman_position_old);
  this->updatePlayerCamera(bomberman->getPos());
}

void			GameEvent::down(SceneManager* sm)
{
  glm::vec3		bomberman_position_old;
  Scene			*scene = sm->getCurrentScene();
  Bomberman*		bomberman = static_cast<Bomberman*>(scene->getBomberman());

  bomberman_position_old = bomberman->getPos();
  bomberman->moveBack(this->_clock);
  if (bomberman->getHitbox()->checkCollision(scene))
    bomberman->setPos(bomberman_position_old);
  this->updatePlayerCamera(bomberman->getPos());

}


void			GameEvent::right(SceneManager* sm)
{
  glm::vec3		bomberman_position_old;
  Scene			*scene = sm->getCurrentScene();
  Bomberman*		bomberman = static_cast<Bomberman*>(scene->getBomberman());

  bomberman_position_old = bomberman->getPos();
  bomberman->moveRight(this->_clock);
  if (bomberman->getHitbox()->checkCollision(scene))
    bomberman->setPos(bomberman_position_old);
  this->updatePlayerCamera(bomberman->getPos());
}

void			GameEvent::left(SceneManager* sm)
{
  glm::vec3		bomberman_position_old;
  Scene			*scene = sm->getCurrentScene();
  Bomberman*		bomberman = static_cast<Bomberman*>(scene->getBomberman());

  bomberman_position_old = bomberman->getPos();
  bomberman->moveLeft(this->_clock);
  if (bomberman->getHitbox()->checkCollision(scene))
    bomberman->setPos(bomberman_position_old);
  this->updatePlayerCamera(bomberman->getPos());

}

void			GameEvent::space(SceneManager* sm)
{
  Scene			*scene = sm->getCurrentScene();
  Bomberman*		bomberman = static_cast<Bomberman*>(scene->getBomberman());

  bomberman->dropBomb(scene);
}

void			GameEvent::escape(SceneManager* sm)
{
  (void) sm;
  dynamic_cast<Scene*>(sm->getCurrentScene())->escapePress(sm);
}
