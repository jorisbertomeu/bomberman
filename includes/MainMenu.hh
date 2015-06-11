//
// MainMenu.hpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Jun  9 11:12:51 2015 Joris Bertomeu
// Last update Thu Jun 11 16:03:36 2015 Valérian Polizzi
//

#ifndef		_MAINMENU_HPP_
# define	_MAINMENU_HPP_

# include	<Scene.hh>
# include	<Pavement.hh>
# include	<list>

# define	TOP_HEIGHT		800;
# define	MARGIN			200;

class		MainMenu : public	Scene
{
private:
  std::list<Pavement*>	_buttons;
  Pavement		*_cursor;
public:
  explicit	MainMenu();
  virtual	~MainMenu();

  void		initialize();
  void		moveCursor();
  Pavement     	*getCursor() const;
  int		getListSize() const;
};

#endif
