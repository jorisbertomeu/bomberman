//
// NewGameMenu.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 01:38:42 2015 Geoffrey Merran
// Last update Sun Jun 14 07:48:25 2015 Geoffrey Merran
//

#include <NewGameMenu.hh>

NewGameMenu::NewGameMenu(CameraManager & cm, const std::string & folderPath) : Scene(&cm), _initialized(false), _folderPath(folderPath), _mapSelector(NULL)
{
  this->_buttons.push_back(new GameButton(glm::vec3(-300, -350, 100), std::string("assets/textures/left.tga"), LEFT));
  this->_buttons.back()->setScale(glm::vec3(100, 100, 100));
  this->_buttons.push_back(new GameButton(glm::vec3(0, -350, 100), std::string("assets/textures/ok.tga"), OK));
  this->_buttons.back()->setCurrent(true);
  this->_buttons.back()->setScale(glm::vec3(300, 100, 100));
  this->_buttons.push_back(new GameButton(glm::vec3(300, -350, 100), std::string("assets/textures/right.tga"), RIGHT));
  this->_buttons.back()->setScale(glm::vec3(100, 100, 100));

  this->_previewers.push_back(new MapPreviewer(glm::vec3(-600, 0, 0), std::string("assets/textures/nothumb.tga")));
  this->_previewers.back()->setScale(glm::vec3(350, 350, 350));
  this->_previewers.push_back(new MapPreviewer(glm::vec3(0, 0, 0), std::string("assets/textures/nothumb.tga")));
  this->_previewers.back()->setCurrent(true);
  this->_previewers.back()->setScale(glm::vec3(350, 350, 350));
  this->_previewers.push_back(new MapPreviewer(glm::vec3(600, 0, 0), std::string("assets/textures/nothumb.tga")));
  this->_previewers.back()->setScale(glm::vec3(350, 350, 350));
  this->_eventHandler = new NewGameEvent();
  for (std::list<GameButton*>::iterator it = this->_buttons.begin(); it != this->_buttons.end(); it++)
    this->addEntity((*it));
  for (std::list<MapPreviewer*>::iterator it = this->_previewers.begin(); it != this->_previewers.end(); it++)
    this->addEntity((*it));
  this->_cursor = new GameButton(glm::vec3(0, -290, 0), std::string("assets/textures/merran.tga"));
  this->_cursor->setScale(glm::vec3(120, 120, 0));
  this->_cursor->setCurrent(false);
  this->addEntity(this->_cursor);
  Pavement*	background = new Pavement(glm::vec3(0, 0, 0), std::string("assets/textures/background.tga"));
  background->setScale(glm::vec3(2500, 1300, 0));
  this->addEntity(background);
}

NewGameMenu::~NewGameMenu()
{
  if (_mapSelector)
    delete _mapSelector;
}

void					NewGameMenu::initialize()
{
  this->_cm->moveTo(glm::vec3(0, 0, 1000), glm::vec3(0, 0, 0));
  if (!this->_initialized)
    {
      this->_mapSelector = new MapSelector(this->_folderPath);
      if (this->_mapSelector->hasFoundMap() == false)
	{
	  delete _mapSelector;
	  _mapSelector = NULL;
	}
      else
	{
	  this->_initialized = true;
	  this->updateMaps();
	}
    }
}

void					NewGameMenu::updateMaps()
{
  if (this->_mapSelector != NULL)
    {
      std::list<std::string>		textures = this->_mapSelector->get3Maps();
      std::list<MapPreviewer*>::iterator   	itPreviewer = this->_previewers.begin();
      for (std::list<std::string>::iterator it = textures.begin(); it != textures.end(); it++)
	{
	  if ((*it) == "hidden")
	    (*itPreviewer)->setHidden(true);
	  else
	    {
	      (*itPreviewer)->setHidden(false);
	      (*itPreviewer)->changeMap((*it));
	    }
	  itPreviewer++;
	}
    }
}


void					NewGameMenu::moveNextMap()
{
  (*this->getCurrent())->setCurrent(false);
  this->_buttons.back()->setCurrent(true);
  glm::vec3 pos = this->_buttons.back()->getPos();
  pos.y += 60;
  pos.z = 0;
  this->_cursor->setPos(pos);
  if (this->_mapSelector != NULL)
    this->_mapSelector->nextMap();
  this->updateMaps();
}

void					NewGameMenu::movePrevMap()
{
  (*this->getCurrent())->setCurrent(false);
  this->_buttons.front()->setCurrent(true);
  glm::vec3 pos = this->_buttons.front()->getPos();
  pos.y += 60;
  pos.z = 0;
  this->_cursor->setPos(pos);
  if (this->_mapSelector != NULL)
    this->_mapSelector->prevMap();
  this->updateMaps();
}

std::list<GameButton*>::iterator    	NewGameMenu::getCurrent()
{
  for (std::list<GameButton*>::iterator it = this->_buttons.begin(); it != this->_buttons.end(); it++)
    {
      if ((*it)->getCurrent())
	return (it);
    }
  return (this->_buttons.end());
}

void					NewGameMenu::selectMap(SceneManager* sm)
{
  if (this->_mapSelector != NULL)
    {
      std::list<Map>::iterator it = this->_mapSelector->getCurrent();
      if (!(*it).isCorrupted())
	sm->loadSceneFromFile("gameScene", (*it).getFilename());
      if (!sm->setCurrentScene("gameScene"))
	std::cerr << "[ERROR] loading scene [gameScene]: not found. (maybe map corrupted)" << std::endl;
    }
}

void					NewGameMenu::back(SceneManager* sm) const
{
  if (!sm->setCurrentScene("mainMenu"))
    std::cerr << "[ERROR] loading scene [mainMenu]: not found." << std::endl;
}
