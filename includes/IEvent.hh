//
// IEvent.hh for  in /home/mari_f/testtt/src
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:34:31 2015 mari_f
// Last update Sat Jun  6 19:45:52 2015 Geoffrey Merran
//

#ifndef			_IEVENT_HH__
# define		_IEVENT_HH__

# include		<Input.hh>
# include		<Scene.hh>
# include		<CameraManager.hh>

class			IEvent
{
public:
  virtual		~IEvent() {};
  virtual bool	       	isCatch(gdl::Input &input, Scene*, CameraManager&) = 0;
};

#endif
