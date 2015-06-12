//
// Event.cpp for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:43:17 2015 mari_f
// Last update Fri Jun 12 14:38:22 2015 Geoffrey Merran
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
  // this->_events[SDL_BUTTON_LEFT] = &GameEvent::click;
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
  std::list<AEntity*> list;
  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
	{
	  dynamic_cast<Bomberman*>((*it))->isReleased(scene);
	  this->updatePlayerCamera((*it)->getPos());
	  return (false);
	}
    }
  return (false);
}

void			GameEvent::updatePlayerCamera(const glm::vec3 & point)
{
  this->_camera.moveTo(this->_camera.getDefaultPos() + point, point);
}

void			GameEvent::up(SceneManager* sm)
{
  std::list<AEntity*>	list;
  glm::vec3		bomberman_position_old;
  Scene			*scene = sm->getCurrentScene();

  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
      	{
      	  bomberman_position_old = dynamic_cast<Bomberman*>((*it))->getPos();
      	  dynamic_cast<Bomberman*>((*it))->moveFront();
      	  if (dynamic_cast<Bomberman*>((*it))->getHitbox()->checkCollision(scene))
      	    dynamic_cast<Bomberman*>((*it))->setPos(bomberman_position_old);
      	  this->updatePlayerCamera((*it)->getPos());
      	}
    }
}

void			GameEvent::click(SceneManager* sm)
{
  (void)sm;
}

void			GameEvent::down(SceneManager* sm)
{
  std::list<AEntity*>	list;
  glm::vec3		bomberman_position_old;
  Scene			*scene = sm->getCurrentScene();

  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
	{
	  bomberman_position_old = dynamic_cast<Bomberman*>((*it))->getPos();
	  dynamic_cast<Bomberman*>((*it))->moveBack();
	  if (dynamic_cast<Bomberman*>((*it))->getHitbox()->checkCollision(scene))
      	    dynamic_cast<Bomberman*>((*it))->setPos(bomberman_position_old);
	  this->updatePlayerCamera((*it)->getPos());
	}
    }
}


void			GameEvent::right(SceneManager* sm)
{
  std::list<AEntity*>	list;
  glm::vec3		bomberman_position_old;
  Scene			*scene = sm->getCurrentScene();

  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
	{
	  bomberman_position_old = dynamic_cast<Bomberman*>((*it))->getPos();
	  dynamic_cast<Bomberman*>((*it))->moveRight();
	  if (dynamic_cast<Bomberman*>((*it))->getHitbox()->checkCollision(scene))
      	    dynamic_cast<Bomberman*>((*it))->setPos(bomberman_position_old);
	  this->updatePlayerCamera((*it)->getPos());
	}
    }

}

void			GameEvent::left(SceneManager* sm)
{
  std::list<AEntity*>	list;
  glm::vec3		bomberman_position_old;
  Scene			*scene = sm->getCurrentScene();

  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
	{
	  bomberman_position_old = dynamic_cast<Bomberman*>((*it))->getPos();
	  dynamic_cast<Bomberman*>((*it))->moveLeft();
	  if (dynamic_cast<Bomberman*>((*it))->getHitbox()->checkCollision(scene))
      	    dynamic_cast<Bomberman*>((*it))->setPos(bomberman_position_old);
	  this->updatePlayerCamera((*it)->getPos());
	}
    }
}

void			GameEvent::space(SceneManager* sm)
{
  //dynamic_cast<Scene*>(sm->getCurrentScene())->spacePress(sm);
}
