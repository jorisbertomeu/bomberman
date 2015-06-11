//
// LoadingEvent.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 23:41:29 2015 Geoffrey Merran
// Last update Sat Jun 13 23:45:17 2015 Geoffrey Merran
//

#include <LoadingEvent.hh>

LoadingEvent::LoadingEvent()
{

}

LoadingEvent::~LoadingEvent()
{

}

bool			LoadingEvent::isCatch(gdl::Input &input, gdl::Clock& clock, SceneManager* sm, CameraManager& cm)
{
  (void) input;
  (void) cm;
  (void) clock;
  dynamic_cast<LoadingScene*>(sm->getCurrentScene())->loadScene(sm);
  return (true);
}

