//
// MainMenu.hpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Jun  9 11:12:51 2015 Joris Bertomeu
// Last update Mon Jun  8 09:50:19 2015 Valérian Polizzi
//

#ifndef		_MAINMENU_HPP_
# define	_MAINMENU_HPP_

# include	<Scene.hh>
# include	<Pavement.hh>
# include	<list>

class		MainMenu : public	Scene
{
private:
  Pavement	*_p1;
  Pavement	*_p2;
public:
  explicit	MainMenu();
  virtual	~MainMenu();
};

#endif
