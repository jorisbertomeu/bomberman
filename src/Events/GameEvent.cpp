//
// Event.cpp for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:43:17 2015 mari_f
// Last update Sun Jun  7 00:10:53 2015 Geoffrey Merran
//

# include		<GameEvent.hh>

GameEvent::GameEvent()
{
  this->_events[SDLK_UP] = &GameEvent::up;
  this->_events[SDLK_DOWN] = &GameEvent::down;
  this->_events[SDLK_LEFT] = &GameEvent::left;
  this->_events[SDLK_RIGHT] = &GameEvent::right;
}

GameEvent::~GameEvent()
{

}

bool			GameEvent::isCatch(gdl::Input &input, Scene* scene, CameraManager& camera)
{
  this->_camera = camera;
  for (std::map<int, GameEvent::eventHandler>::iterator found = this->_events.begin(); found != this->_events.end(); found++)
    {
      if (input.getKey((*found).first))
	{
	  (this->*this->_events[(*found).first])(scene);
	  return (true);
	}
    }
  return (false);
}

void			GameEvent::updatePlayerCamera(const glm::vec3 & point)
{
  this->_camera.moveTo(this->_camera.getDefaultPos() + point, point);
}

void			GameEvent::up(Scene* scene)
{
  std::list<AEntity*>	list;

  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
	{
	  dynamic_cast<Bomberman*>((*it))->moveFront();
	  this->updatePlayerCamera((*it)->getPos());
	}
    }
}


void			GameEvent::down(Scene* scene)
{
  std::list<AEntity*>	list;

  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
	{
	  dynamic_cast<Bomberman*>((*it))->moveBack();
	  this->updatePlayerCamera((*it)->getPos());
	}

    }
}


void			GameEvent::right(Scene* scene)
{
  std::list<AEntity*>	list;

  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
	{
	  dynamic_cast<Bomberman*>((*it))->moveRight();
	  this->updatePlayerCamera((*it)->getPos());
	}
    }
}

void			GameEvent::left(Scene* scene)
{
  std::list<AEntity*>	list;

  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
	{
	  dynamic_cast<Bomberman*>((*it))->moveLeft();
	  this->updatePlayerCamera((*it)->getPos());
	}
    }
}
