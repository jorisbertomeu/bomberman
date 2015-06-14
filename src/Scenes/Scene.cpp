//
// Scene.cpp for  in /home/mediav_j/mabm/bomberman/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Jun  1 15:32:58 2015 Jérémy Mediavilla
// Last update Sun Jun 14 04:27:38 2015 Jérémy Mediavilla
//

#include	<CameraManager.hh>
#include	<Scene.hh>

Scene::Scene(CameraManager* cm) : _cm(cm)
{
  this->_eventHandler = NULL;
  this->_first = true;
  this->_renderManager = NULL;
}

Scene::~Scene()
{
  if (_eventHandler)
    delete _eventHandler;
  for (std::list<AEntity*>::iterator it = _entityList.begin(); it != _entityList.end(); it++)
    delete (*it);
}

void				Scene::initialize()
{
  this->_cm->moveTo(glm::vec3(0, 500, 200), glm::vec3(0, 0, 0));
  this->_cm->setDefaultPos(glm::vec3(0, 500, 200));
}

std::list<AEntity*>		Scene::getEntities()
{
  return (this->_entityList);
}

bool		Scene::addEntity(AEntity *entity)
{
  std::cout << "adding entity size : " << this->_entityList.size() << std::endl;
  this->_entityList.push_back(entity);
  return(true);
}

void		Scene::updateEntities(gdl::Clock & clock)
{
  for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end(); it++)
    (*it)->update(clock, this);
}

IEvent*		Scene::getEventHandler()
{
  if (!this->_eventHandler)
    std::cerr << "WARNING : Event Handler from Scene is NULL." << std::endl;
  return (this->_eventHandler);
}

void  	      	Scene::draw(RenderManager & rm)
{
  if (!this->_first) {
    rm.getSoundManager().getSoundOf(Sound::AMBIANT)->setVolume(0);
    this->_first = true;
  }
  if (!this->_renderManager)
    this->_renderManager = &rm;
  for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end(); it++)
    (*it)->draw(rm);
}

bool		Scene::save(RenderManager *rm)
{
  std::fstream	fs;

  fs.open("XMLfiles/save.xml", std::fstream::in | std::fstream::out | std::fstream::trunc);
  if (!fs.is_open())
    {
      std::cout << "Error on open while saving map.xml" << std::endl;
      return (false);
    }
  fs << "<scene>" << std::endl;
  fs << "  <texture_pack>" << std::endl;
  std::map<std::string, Texture *> textureList = rm->getTextureManager().getTextures();
  for (std::map<std::string, Texture*>::iterator it = textureList.begin(); it != textureList.end(); ++it)
    {
      (*it->second).save(fs);
    }
  fs << "  </texture_pack>" << std::endl;
  fs << "  <entities>" << std::endl;
  for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end(); ++it)
    {
      (*it)->save(fs);
    }
  fs << "  </entities>" << std::endl;
  fs << "/<scene>" << std::endl;
  fs.close();
  return (true);
}

void		Scene::setEventHandler(IEvent *event)
{
  this->_eventHandler = event;
}

void		Scene::spacePress(SceneManager *sm)
{
  if (!sm->setCurrentScene(std::string("mainMenu")))
    std::cerr << "Error while loading menu Scene" << std::endl;
}

void		Scene::escapePress(SceneManager *sm)
{
  if (!sm->setCurrentScene(std::string("escapeMenu")))
    std::cerr << "Error while loading menu Scene" << std::endl;
}

void		*Scene::getBomberman()
{
  for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end(); ++it)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
	return (*it);
    }
  return (NULL);
}

