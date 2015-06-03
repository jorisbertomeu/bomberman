//
// Event.hh for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:40:00 2015 mari_f
// Last update Wed Jun  3 14:18:24 2015 mari_f
//

#ifndef				_EVENT_HH__
# define			_EVENT_HH__

# include			<IEvent.hh>

class Event : public IEvent
{
public:
  Event(void);
  virtual ~Event(void);
  virtual bool		isCatch(const gdl::Input &input);
};

#endif
