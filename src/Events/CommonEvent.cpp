//
// Event.cpp for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:43:17 2015 mari_f
// Last update Fri Jun 12 20:51:52 2015 Geoffrey Merran
//

# include		<CommonEvent.hh>

CommonEvent::CommonEvent()
{
  //this->_events[SDLK_ESCAPE] = &CommonEvent::escape;
  this->_events[SDL_QUIT] = &CommonEvent::escape;
}

CommonEvent::~CommonEvent()
{

}

bool			CommonEvent::isCatch(gdl::Input &input, gdl::Clock& clock, SceneManager* sm, CameraManager& camera)
{
  (void) sm;
  (void) camera;
  (void) clock;
  for (std::map<int, CommonEvent::eventHandler>::iterator found = this->_events.begin(); found != this->_events.end(); found++)
    {
      if (input.getKey((*found).first))
	{
	  (this->*this->_events[(*found).first])(sm);
	  return (true);
	}
    }
  return (false);
}


void			CommonEvent::escape(SceneManager* sm)
{
  (void) sm;
  exit(0);
}
