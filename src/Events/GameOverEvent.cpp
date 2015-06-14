//
// GameOverEvent.cpp for Bomberman in /home/polizz_v/rendu/CPP/git/bomberman
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Sun Jun 14 17:58:29 2015 Valérian Polizzi
// Last update Sun Jun 14 19:10:23 2015 Valérian Polizzi
//

#include <GameOverEvent.hh>

GameOverEvent::GameOverEvent()
{
  this->_events[SDLK_SPACE] = &GameOverEvent::space;
}

GameOverEvent::~GameOverEvent()
{

}

bool                    GameOverEvent::isCatch(gdl::Input &input, gdl::Clock& clock, SceneManager* sm, CameraManager& camera)
{
  (void) sm;
  (void) camera;
  (void) clock;
  for (std::map<int, GameOverEvent::eventHandler>::iterator found = this->_events.begin(); found != this->_events.end(); found++)
    {
      if (input.getKey((*found).first))
        {
          (this->*this->_events[(*found).first])(sm);
          return (true);
        }
    }
  return (false);
}


void                    GameOverEvent ::space(SceneManager* sm)
{
  std::cout << "ok" << std::endl;
  if(!sm->setCurrentScene(std::string("mainMenu")))
    std::cerr << "Error while loading 'mainMenu" << std::endl;
}
