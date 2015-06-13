//
// NewGameMenu.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 01:12:21 2015 Geoffrey Merran
// Last update Sat Jun 13 21:09:55 2015 Geoffrey Merran
//

#ifndef __NEW_GAME_MENU_HH
# define __NEW_GAME_MENU_HH

# include				<list>
# include				<SceneManager.hh>
# include				<GameButton.hh>
# include				<NewGameEvent.hh>
# include				<MapSelector.hh>
# include				<MapPreviewer.hh>

class					NewGameMenu : public Scene
{
private:
  std::list<GameButton*>		_buttons;
  std::list<MapPreviewer*>		_previewers;
  GameButton*				_cursor;
  bool					_initialized;
  std::string				_folderPath;
  MapSelector*				_mapSelector;

  void					updateMaps();

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
