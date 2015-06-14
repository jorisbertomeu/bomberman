//
// WinScene.hh for Bomberman in /home/polizz_v/rendu/CPP/git/bomberman/includes
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Sun Jun 14 15:51:20 2015 Valérian Polizzi
// Last update Sun Jun 14 18:43:34 2015 Valérian Polizzi
//

#ifndef _WINSCENE_HH_
# define _WINSCENE_HH_

# include	<Scene.hh>
# include	<SceneManager.hh>
# include	<Pavement.hh>
# include	<GameOverEvent.hh>

class		WinScene : public Scene
{
public:
  explicit	WinScene(CameraManager &cm);
  virtual	~WinScene();
};

#endif
