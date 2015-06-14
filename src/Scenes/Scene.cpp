//
// Scene.cpp for  in /home/mediav_j/mabm/bomberman/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Jun  1 15:32:58 2015 Jérémy Mediavilla
// Last update Sun Jun 14 22:36:21 2015 Jérémy Mediavilla
//

#include	<CameraManager.hh>
#include	<Scene.hh>
#include	<Floor.hh>

Scene::Scene(CameraManager* cm) : _cm(cm), _isSplit(false)
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
  this->_entityList.push_back(entity);
  return(true);
}

void		Scene::updateEntities(gdl::Clock & clock)
{
  if (!this->_first) {
    this->_renderManager->getSoundManager().getSoundOf(Sound::AMBIANT)->setVolume(0);
    this->_first = true;
  }
  for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end(); it++)
    (*it)->update(clock, this);
  for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end();)
    {
      if ((*it)->getDestroy())
	{
	  delete (*it);
	  it = this->_entityList.erase(it);
	}
      else
	it++;
    }
}

IEvent*		Scene::getEventHandler()
{
  if (!this->_eventHandler)
    std::cerr << "WARNING : Event Handler from Scene is NULL." << std::endl;
  return (this->_eventHandler);
}

void		Scene::moveSplitScreenCamera() const
{

}

void  	      	Scene::draw(RenderManager & rm)
{
  if (!this->_first) {
    rm.getSoundManager().getSoundOf(Sound::AMBIANT)->pause();
    this->_first = true;
  }
  if (!this->_renderManager)
    this->_renderManager = &rm;
  if (this->_isSplit)
    {
      this->_renderManager->getCameraManager()->splitScreen(true);
      glm::vec2 ws = this->_renderManager->getCameraManager()->getWindowSize();
      glViewport(0, 0, ws.x / 2, ws.y);
      for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end(); it++)
	(*it)->draw(rm);
      glViewport(ws.x / 2, 0, ws.x / 2, ws.y);
      this->moveSplitScreenCamera();
    }
  else
    this->_renderManager->getCameraManager()->splitScreen(false);
  for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end(); it++)
    (*it)->draw(rm);
}

bool		Scene::save(RenderManager *rm)
{
  std::fstream	fs;

  fs.open("maps/save.xml", std::fstream::in | std::fstream::out | std::fstream::trunc);
  if (!fs.is_open())
    {
      std::cout << "Error on open while saving save.xml" << std::endl;
      return (false);
    }
  fs << "<scene>" << std::endl;
  fs << "  <parameters>" << std::endl;
  fs << "    <author>SAVE</author>" << std::endl;
  fs << "    <level>0</level>" << std::endl;
  fs << "    <date>time(NULL)</date>" << std::endl;
  fs << "    <id>" << "</id>" << std::endl;
  fs << "    <score>0</score>" << std::endl;
  fs << "    <bots>0</bots>" << std::endl;
  fs << "    <ia_difficulty>IA_EASY</ia_difficulty>" << std::endl;
  fs << "  </parameters>" << std::endl;
  fs << "  <texture_pack>" << std::endl;
  std::map<std::string, Texture *> textureList = rm->getTextureManager().getTextures();
  for (std::map<std::string, Texture*>::iterator it = textureList.begin(); it != textureList.end(); ++it)
    {
      (*it->second).save(fs);
    }
  fs << "  </texture_pack>" << std::endl;

  fs << "  <model_pack>" << std::endl;
  std::map<std::string, Model *> modelList = rm->getModelManager().getModelsMap();
  for (std::map<std::string, Model *>::iterator it = modelList.begin(); it != modelList.end(); ++it)
    {
      fs << "    <model>" << std::endl;
      fs << "      <id>" << (it->first) << "</id>" << std::endl;
      fs << "      <online>" << (*it->second).getOnline() << "</online>" << std::endl;
      fs << "      <file>" << (*it->second).getFilename() << "</file>" << std::endl;
      fs << "    </model>" << std::endl;
    }
  fs << "  </model_pack>" << std::endl;

  fs << "  <common>" << std::endl;
  for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end(); ++it)
    {
      if ((*it)->getType() == AEntity::PAVEMENT)
  	{
  	  fs << "    <width>" << static_cast<Floor *>((*it))->getWidth()  << "</width>" << std::endl;
  	  fs << "    <height>" << static_cast<Floor *>((*it))->getHeigth() << "</height>" << std::endl;
  	}
    }
  fs << "    <gravity>1</gravity>" << std::endl;
  fs << "    <friction>0.1</friction>" << std::endl;
  fs << "    <skybox><online>0</online><file>NULL</file></skybox>" << std::endl;
  fs << "    <texture>idFloorTexture</texture>" << std::endl;
  fs << "  </common>" << std::endl;

  fs << "  <entities>" << std::endl;
  for (std::list<AEntity*>::iterator it = this->_entityList.begin(); it != this->_entityList.end(); ++it)
    {
      if ((*it)->getType() == AEntity::UNKNOWN || (*it)->getType() == AEntity::PAVEMENT)
	{
	  std::cout << "on a trouvé unknown" << std::endl;
	  continue;
	}
      (*it)->save(fs);
    }
  fs << "  </entities>" << std::endl;
  fs << "</scene>" << std::endl;
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
