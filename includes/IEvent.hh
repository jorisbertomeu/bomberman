//
// IEvent.hh for  in /home/mari_f/testtt/src
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:34:31 2015 mari_f
// Last update Wed Jun  3 14:19:46 2015 mari_f
//

#ifndef			_IEVENT_HH__
# define		_IEVENT_HH__

# include		<Input.hh>

class			IEvent
{
public:
  virtual		~IEvent() {};
  virtual bool	       	isCatch(const gdl::Input &input) = 0;
};

#endif
