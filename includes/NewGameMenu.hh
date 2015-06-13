//
// NewGameMenu.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 01:12:21 2015 Geoffrey Merran
// Last update Sat Jun 13 03:47:43 2015 Geoffrey Merran
//

#ifndef __NEW_GAME_MENU_HH
# define __NEW_GAME_MENU_HH

# include				<SceneManager.hh>
# include				<GameButton.hh>
# include				<list>
# include				<NewGameEvent.hh>
# include				<MapSelector.hh>

class					NewGameMenu : public Scene
{
private:
  std::list<GameButton*>		_buttons;
  GameButton*				_cursor;
  bool					_initialized;
  std::string				_folderPath;
  MapSelector*				_mapSelector;

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
