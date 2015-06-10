//
// Event.cpp for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:43:17 2015 mari_f
// Last update Wed Jun 10 02:49:44 2015 Joris Bertomeu
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

bool			CommonEvent::isCatch(gdl::Input &input, SceneManager* sm, CameraManager& camera)
{
  Scene			*scene = sm->getCurrentScene();

  (void) camera;
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
