//
// LoadingScene.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 23:22:58 2015 Geoffrey Merran
// Last update Sat Jun 13 23:51:11 2015 Geoffrey Merran
//

#include <LoadingScene.hh>

LoadingScene::LoadingScene(CameraManager &cm) : Scene(&cm), _sceneToLoad("loadingScene")
{
  Pavement*	background = new Pavement(glm::vec3(0, 0, 0), std::string("assets/textures/intro.tga"));
  background->setScale(glm::vec3(2500, 1300, 0));
  this->addEntity(background);
  this->_eventHandler = new LoadingEvent();
}

LoadingScene::~LoadingScene()
{

}

void				LoadingScene::initialize()
{

}

void				LoadingScene::setSceneToLoad(const std::string & scene)
{
  this->_sceneToLoad = scene;
}

const std::string &		LoadingScene::getSceneToLoad() const
{
  return (this->_sceneToLoad);
}

void				LoadingScene::loadScene(SceneManager *sm)
{
  if (!sm->setCurrentScene(this->_sceneToLoad))
    std::cerr << "Error while loading scene: " << this->_sceneToLoad << std::endl;
}
