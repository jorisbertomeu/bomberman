//
// EscapeMenu.hh for  in /home/ades_n/Work/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.eu>
//
// Started on  Fri Jun 12 11:12:51 2015 Nicolas Adès
// Last update Sat Jun 13 19:21:49 2015 mari_f
//

#ifndef		_ESCAPEMENU_HH_
# define	_ESCAPEMENU_HH_

# include	<SceneManager.hh>
# include	<GameButton.hh>
# include	<Cloud.hh>
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
  enum ButtonId
    {
      RESUME,
      SAVE,
      QUIT
    };

  explicit				EscapeMenu(CameraManager &cm);
  virtual				~EscapeMenu();

  virtual void				initialize();
  void					moveCursorUp();
  void					moveCursorDown();

  GameButton*				getCursor() const;
  std::list<GameButton*>::iterator    	getCurrent();
  int					getListSize() const;
  void					selectButton(SceneManager *);
};

#endif		// _ESCAPEMENU_HH_
