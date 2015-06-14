//
// LoseScene.hh for bomberman in /home/polizz_v/rendu/CPP/git/bomberman/includes
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Sun Jun 14 17:54:10 2015 Valérian Polizzi
// Last update Sun Jun 14 19:03:09 2015 Valérian Polizzi
//

#ifndef _LOSESCENE_HH_
# define _LOSESCENE_HH_

# include	<Scene.hh>
# include	<SceneManager.hh>
# include	<Pavement.hh>
# include	<GameOverEvent.hh>

class           LoseScene : public Scene
{
public:
  explicit      LoseScene(CameraManager &cm);
  virtual       ~LoseScene();
};

#endif
