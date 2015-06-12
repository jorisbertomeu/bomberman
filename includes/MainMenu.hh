//
// MainMenu.hpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Jun  9 11:12:51 2015 Joris Bertomeu
// Last update Fri Jun 12 05:18:37 2015 Geoffrey Merran
//

#ifndef		_MAINMENU_HPP_
# define	_MAINMENU_HPP_

# include      	<Scene.hh>
# include	<GameButton.hh>
# include	<list>
# include	<MenuEvent.hh>

# define	TOP_HEIGHT 	800;
# define	MARGIN	       	200;

class				MainMenu : public Scene
{
private:
  std::list<GameButton*>	_buttons;
  GameButton*			_cursor;
  CameraManager			_cm;

public:
  explicit			MainMenu(CameraManager & cm);
  virtual			~MainMenu();

  void				initialize();
  void				moveCursor();
  GameButton*			getCursor() const;
  std::list<GameButton*>::iterator    	getCurrent();
  int				getListSize() const;
};

#endif
