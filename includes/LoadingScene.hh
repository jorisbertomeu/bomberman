//
// LoadingScene.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 23:23:12 2015 Geoffrey Merran
// Last update Sat Jun 13 23:56:58 2015 Geoffrey Merran
//

#ifndef __LOADING_SCENE_HH
# define __LOADING_SCENE_HH

class				LoadingScene;

# include <SceneManager.hh>
# include <Pavement.hh>
# include <LoadingEvent.hh>

class				LoadingScene : public Scene
{
public:
  explicit		       	LoadingScene(CameraManager &cm);
  virtual		       	~LoadingScene();

  virtual void			initialize();
  void				setSceneToLoad(const std::string &);
  const std::string &		getSceneToLoad() const;
  void				loadScene(SceneManager *sm);

private:
  std::string			_sceneToLoad;
};

#endif /* __LOADING_SCENE_HH */
