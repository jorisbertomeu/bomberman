//
// Event.cpp for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:43:17 2015 mari_f
// Last update Fri Jun 12 19:40:15 2015 mari_f
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
}

GameEvent::~GameEvent()
{

}

bool			GameEvent::isCatch(gdl::Input &input, SceneManager* sm, CameraManager& camera)
{
  Scene			*scene = sm->getCurrentScene();


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
  bomberman->isReleased(scene);
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
  bomberman->moveFront();
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
  bomberman->moveBack();
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
  bomberman->moveRight();
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
  bomberman->moveLeft();
  if (bomberman->getHitbox()->checkCollision(scene))
    bomberman->setPos(bomberman_position_old);
  this->updatePlayerCamera(bomberman->getPos());

}

void			GameEvent::space(SceneManager* sm)
{
  (void) sm;
  //dynamic_cast<Scene*>(sm->getCurrentScene())->spacePress(sm);
}
