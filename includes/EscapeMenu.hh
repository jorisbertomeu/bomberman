//
// EscapeMenu.hh for  in /home/ades_n/Work/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.eu>
//
// Started on  Fri Jun 12 11:12:51 2015 Nicolas Adès
// Last update Fri Jun 12 02:32:36 2015 Nicolas Adès
//

#ifndef		_ESCAPEMENU_HH_
# define	_ESCAPEMENU_HH_

# include	<SceneManager.hh>
# include	<GameButton.hh>
# include	<list>
# include	<EscapeEvent.hh>

# define	TOP_HEIGHT	800;
# define	MARGIN		200;

class					EscapeMenu : public Scene
{
private:
  std::list<GameButton*>		_buttons;
  GameButton*				_cursor;

public:
  explicit				EscapeMenu(CameraManager &cm);
  virtual				~EscapeMenu();

  void					initialize();
  void					moveCursor();
  GameButton*				getCursor() const;
  std::list<GameButton*>::iterator	getCurrent();
  int					getListSize() const;
  void					selectButton(SceneManager *);
};

#endif		// _ESCAPEMENU_HH_
