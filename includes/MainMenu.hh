//
// MainMenu.hpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Jun  9 11:12:51 2015 Joris Bertomeu
// Last update Sun Jun 14 01:26:10 2015 mari_f
//

#ifndef		_MAINMENU_HPP_
# define	_MAINMENU_HPP_

# include				<SceneManager.hh>
# include				<GameButton.hh>
# include				<Cloud.hh>
# include				<Balloon.hh>
# include				<list>
# include				<MenuEvent.hh>
# include				<LoadingScene.hh>

class					MainMenu : public Scene
{
private:
  std::list<Pavement*>		_buttons;
  GameButton*				_cursor;

public:
  enum ButtonId
    {
      PLAY,
      LOAD,
      QUIT
    };

  explicit				MainMenu(CameraManager & cm);
  virtual				~MainMenu();

  virtual void				initialize();
  void					moveCursorUp();
  void					moveCursorDown();

  GameButton*				getCursor() const;
  std::list<Pavement*>::iterator    	getCurrent();
  int					getListSize() const;
  void					selectButton(SceneManager *);
};

#endif
