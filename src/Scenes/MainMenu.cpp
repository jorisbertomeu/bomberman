//
// MainMenu.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src/Scenes
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Mon Jun  8 09:29:53 2015 Valérian Polizzi
// Last update Sun Jun 14 02:09:59 2015 mari_f
//

#include	<MainMenu.hh>

MainMenu::MainMenu(CameraManager & cm) : Scene(&cm)
{
  Cloud		*cloud;
  Balloon	*balloon;

  this->_buttons.push_back(new GameButton(glm::vec3(0, 50, 0), std::string("assets/textures/play.tga"), MainMenu::PLAY));
  dynamic_cast<GameButton*>(this->_buttons.front())->setCurrent(true);
  this->_buttons.push_back(new GameButton(glm::vec3(0, -150, 0), std::string("assets/textures/load.tga"), MainMenu::LOAD));
  this->_buttons.push_back(new GameButton(glm::vec3(0, -350, 0), std::string("assets/textures/quit.tga"), MainMenu::QUIT));

  // cloud = new Cloud(glm::vec3(-500, -300, 0), std::string("assets/textures/cloud.tga"));
  // cloud->setScale(glm::vec3(250, 150, 0));
  // this->addEntity(cloud);
  cloud = new Cloud(glm::vec3(-700, 300, 0), std::string("assets/textures/cloud.tga"), 0.5f, 40.0f);
  cloud->setScale(glm::vec3(400, 240, 0));
  this->addEntity(cloud);
  cloud = new Cloud(glm::vec3(500, 250, 0), std::string("assets/textures/cloud.tga"), 0.7f, 60.0f);
  cloud->setScale(glm::vec3(150, 100, 0));
  this->addEntity(cloud);
  cloud = new Cloud(glm::vec3(400, -200, 0), std::string("assets/textures/cloud.tga"), 0.2f, 10.0f);
  cloud->setScale(glm::vec3(170, 110, 0));
  this->addEntity(cloud);
  cloud = new Cloud(glm::vec3(300, -500, 0), std::string("assets/textures/cloud.tga"), 0.5f, 10.0f);
  cloud->setScale(glm::vec3(230, 180, 0));
  this->addEntity(cloud);


  balloon = new Balloon(glm::vec3(-530, -90, 0), std::string("assets/textures/balloon.tga"), 0.5f, 10.0f);
  balloon->setScale(glm::vec3(400, 469, 0));
  this->addEntity(balloon);

  // balloon = new Balloon(glm::vec3(570, 370, 0), std::string("assets/textures/up.tga"), 0.5f, 10.0f);
  // balloon->setScale(glm::vec3(200, 269, 0));
  // this->addEntity(balloon);

  this->_eventHandler = new MenuEvent();
  for (std::list<Pavement*>::iterator it = this->_buttons.begin(); it != this->_buttons.end(); it++)
    {
      (*it)->setScale(glm::vec3(300, 100, 100));
      this->addEntity(*it);
    }
  this->_cursor = new GameButton(glm::vec3(-250, 50, 0), std::string("assets/textures/hat.tga"));
  this->_cursor->setScale(glm::vec3(120, 120, 0));
  this->_cursor->setCurrent(false);
  this->addEntity(this->_cursor);
  Pavement*	background = new Pavement(glm::vec3(0, 0, 0), std::string("assets/textures/background.tga"));
  background->setScale(glm::vec3(2500, 1300, 0));
  this->addEntity(background);
}

MainMenu::~MainMenu()
{

}

void			MainMenu::initialize()
{
  this->_cm->moveTo(glm::vec3(0, 0, 1000), glm::vec3(0, 0, 0));
}

int			MainMenu::getListSize() const
{
  return (this->_buttons.size());
}

GameButton*		MainMenu::getCursor() const
{
  return (this->_cursor);
}

std::list<Pavement*>::iterator 	MainMenu::getCurrent()
{
  for (std::list<Pavement*>::iterator it = this->_buttons.begin(); it != this->_buttons.end(); it++)
    {
      if (dynamic_cast<GameButton*>(*it)->getCurrent())
	return (it);
    }
  return (this->_buttons.end());
}

void			MainMenu::moveCursorDown()
{
  std::list<Pavement*>::iterator it = this->getCurrent();
  glm::vec3 pos;

  dynamic_cast<GameButton*>(*it)->setCurrent(false);
  if (++it == this->_buttons.end())
    {
      dynamic_cast<GameButton*>(this->_buttons.front())->setCurrent(true);
      pos = this->_buttons.front()->getPos();
    }
  else
    {
      dynamic_cast<GameButton*>(*it)->setCurrent(true);
      pos = (*it)->getPos();
    }
  pos.x = -250;
  this->_cursor->setPos(pos);
}

void			MainMenu::moveCursorUp()
{
  std::list<Pavement*>::iterator it = this->getCurrent();
  glm::vec3		pos;

  dynamic_cast<GameButton*>(*it)->setCurrent(false);
  if (it == this->_buttons.begin())
    {
      dynamic_cast<GameButton*>(this->_buttons.back())->setCurrent(true);
      pos = this->_buttons.back()->getPos();
    }
  else
    {
      it--;
      dynamic_cast<GameButton*>(*it)->setCurrent(true);
      pos = (*it)->getPos();
    }
  pos.x = -250;
  this->_cursor->setPos(pos);
}

void			MainMenu::selectButton(SceneManager *sm)
{
  std::string		nextScene;

  switch (dynamic_cast<GameButton*>(*this->getCurrent())->getId())
    {
    case PLAY:
      nextScene = "newGame";
      break;
    case LOAD:
      nextScene = "loadMap";
      break;
    case QUIT:
      sm->stopGame();
      return ;
      break;
    }
  if (!sm->setCurrentScene("loadingScene"))
    std::cerr << "Error while loading scene: " << nextScene << std::endl;
  dynamic_cast<LoadingScene*>(sm->getCurrentScene())->setSceneToLoad(nextScene);
}
