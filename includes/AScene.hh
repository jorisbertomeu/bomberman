//
// AScene.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:27:30 2015 Joris Bertomeu
// Last update Mon May 25 22:34:37 2015 Joris Bertomeu
//

#ifndef			_ASCENE_HH_
# define		_ASCENE_HH_

# include		<list>
# include		<AEntity.hh>

class			AScene
{
private:
  std::list<AEntity>	_objects;

public:
  explicit		AScene();
  virtual		~AScene();
};

#endif
