//
// Event.cpp for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:43:17 2015 mari_f
// Last update Sat Jun  6 19:48:51 2015 Geoffrey Merran
//

# include		<CommonEvent.hh>

CommonEvent::CommonEvent()
{
  this->_events[SDLK_ESCAPE] = &CommonEvent::escape;
  this->_events[SDL_QUIT] = &CommonEvent::escape;
}

CommonEvent::~CommonEvent()
{

}

bool			CommonEvent::isCatch(gdl::Input &input, Scene* scene, CameraManager& camera)
{
  (void) camera;
  for (std::map<int, CommonEvent::eventHandler>::iterator found = this->_events.begin(); found != this->_events.end(); found++)
    {
      if (input.getKey((*found).first))
	{
	  (this->*this->_events[(*found).first])(scene);
	  return (true);
	}
    }
  return (false);
}


void			CommonEvent::escape(Scene* scene)
{
  (void) scene;
  exit(0);
}
