//
// NewGameMenu.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 01:12:21 2015 Geoffrey Merran
// Last update Sat Jun 13 03:18:09 2015 Geoffrey Merran
//

#ifndef __NEW_GAME_MENU_HH
# define __NEW_GAME_MENU_HH

# include				<SceneManager.hh>
# include				<GameButton.hh>
# include				<list>
# include				<NewGameEvent.hh>

class					NewGameMenu : public Scene
{
private:
  std::list<GameButton*>		_buttons;
  GameButton*				_cursor;

public:
  enum ButtonId
    {
      LEFT,
      OK,
      RIGHT
    };

  explicit				NewGameMenu(CameraManager & cm, const std::string & folderPath);
  virtual				~NewGameMenu();

  virtual void				initialize();
  void					moveNextMap();
  void					movePrevMap();
  std::list<GameButton*>::iterator    	getCurrent();
  void					selectMap(SceneManager* sm);
  void					back(SceneManager* sm) const;
};

#endif /* __NEW_GAME_MENU_HH */
