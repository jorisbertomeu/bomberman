//
// Event.cpp for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:43:17 2015 mari_f
// Last update Sat Jun  6 15:23:21 2015 Geoffrey Merran
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

bool			GameEvent::isCatch(gdl::Input &input, Scene* scene)
{
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


void			GameEvent::up(Scene* scene)
{
  std::list<AEntity*>	list;

  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
	dynamic_cast<Bomberman*>((*it))->moveFront();
    }
}


void			GameEvent::down(Scene* scene)
{
  (void) scene;
}


void			GameEvent::right(Scene* scene)
{
  (void) scene;
}

void			GameEvent::left(Scene* scene)
{
  (void) scene;
}
