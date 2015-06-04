//
// Event.cpp for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:43:17 2015 mari_f
// Last update Thu Jun  4 13:29:09 2015 mari_f
//

# include		<Event.hh>

Event::Event()
{

}

Event::~Event()
{

}

bool			Event::isCatch(gdl::Input &input)
{
  if (input.getKey(SDLK_UP))
    return (true);
  else if (input.getKey(SDLK_DOWN))
    return (true);
  else if (input.getKey(SDLK_LEFT))
    return (true);
  else if (input.getKey(SDLK_RIGHT))
    return (true);
  return (false);
}
