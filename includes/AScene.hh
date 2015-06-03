//
// AScene.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:27:30 2015 Joris Bertomeu
// Last update Wed Jun  3 15:22:08 2015 Geoffrey Merran
//

#ifndef			_ASCENE_HH_
# define		_ASCENE_HH_

# include		<list>

class			AScene;

# include		<AEntity.hh>

class			AScene
{
private:
  std::list<AEntity>	_objects;

public:
  explicit		AScene();
  virtual		~AScene();

  void			draw();
};

#endif
