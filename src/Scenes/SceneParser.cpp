//
// SceneParser.cpp for  in /home/mediav_j/mabm/bomberman/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Jun  1 15:13:39 2015 Jérémy Mediavilla
// Last update Fri Jun 12 19:14:37 2015 Geoffrey Merran
//

#include	<SceneParser.hh>
#include	<Bomberman.hh>
#include	<BrickWall.hh>
#include	<Floor.hh>

SceneParser::SceneParser()
{

}

SceneParser::~SceneParser()
{

}

bool		SceneParser::load(const std::string &filename)
{
  if (!this->_parser.loadFile(filename))
    {
      std::cout << this->_parser.getError() << std::endl;
      return (false);
    }
  return (true);
}

Scene		*SceneParser::getScene(RenderManager *rm, CameraManager* cm)
{
  Scene		*newScene = new Scene(cm);
  AEntity	*entity;

  this->_parser.setNode("scene");

  std::cout << "PARAMETERS :" << std::endl;
  this->_parser.setNode("parameters");
  if (this->_parser.checkMultipleTag() == false)
    std::cout << this->_parser.getError();
  std::cout << "author : " << this->_parser.getValueOf("author") << std::endl;
  std::cout << "id : " << this->_parser.getValueOf("id") << std::endl;
  if (this->_parser.isNum(this->_parser.getValueOf("level")) == false)
    std::cout << "Warning : \"level\" must be a number" << std::endl;
  std::cout << "level : " << this->_parser.getValueOf("level") << std::endl;
  std::cout << "date : " << this->_parser.getValueOf("date") << std::endl;
  if (this->_parser.isNum(this->_parser.getValueOf("score")) == false)
    std::cout << "Warning : \"score\" must be a number" << std::endl;
  std::cout << "score : " << this->_parser.getValueOf("score") << std::endl;
  if (this->_parser.isNum(this->_parser.getValueOf("bots")) == false)
    std::cout << "Warning : \"score\" must be a number" << std::endl;
  std::cout << "bots : " << this->_parser.getValueOf("bots") << std::endl;
  if (this->_parser.isNum(this->_parser.getValueOf("ia_difficulty")) == false)
    std::cout << "Warning : \"ia_difficulty\" must be a number" << std::endl;
  std::cout << "ia_difficulty : " << this->_parser.getValueOf("ia_difficulty") << std::endl;

  this->_parser.resetNode();
  this->_parser.setNode("scene");
  std::cout << std::endl << "TEXTURE_PACK :" << std::endl;
  this->_parser.setNode("texture_pack");
  while (this->_parser.foreach("texture"))
    {
      if (this->_parser.checkMultipleTag() == false)
	std::cout << this->_parser.getError();
      if (this->_parser.isBool(this->_parser.getValueOf("online")) == false)
	{
	  std::cout << "Error in texture : \"" << this->_parser.getValueOf("online") << "\" online tag must be a boolean" << std::endl;
	  continue;
	}
      rm->getTextureManager().addTextureFromFile(this->_parser.getValueOf("id"), this->_parser.getValueOf("file"));
      std::cout << "id : " << this->_parser.getValueOf("id") << std::endl;
      std::cout << "online : " << this->_parser.getValueOf("online") << std::endl;
      std::cout << "file : " << this->_parser.getValueOf("file") << std::endl << std::endl;
    }

  this->_parser.resetNode();
  this->_parser.setNode("scene");
  std::cout << std::endl << "SOUND_PACK :" << std::endl;
  this->_parser.setNode("sound_pack");
  while (this->_parser.foreach("sound"))
    {
      if (this->_parser.isBool(this->_parser.getValueOf("online")) == false)
	{
	  std::cout << "Error in sound : online tag must be a boolean" << std::endl;
	  continue;
	}
      if (this->_parser.checkMultipleTag() == false)
	std::cout << this->_parser.getError();
      if (this->_parser.getValueOf("id") == "WALK_SOUND")
	rm->getSoundManager().addSound(Sound(Sound::WALK, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file")));
      else if (this->_parser.getValueOf("id") == "EXPLOSION_SOUND")
	rm->getSoundManager().addSound(Sound(Sound::EXPLOSION, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file")));
      else if (this->_parser.getValueOf("id") == "WALK_STOP_SOUND")
	rm->getSoundManager().addSound(Sound(Sound::WALK_STOP, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file")));
else if (this->_parser.getValueOf("id") == "DESTRUCTION_SOUND")
	rm->getSoundManager().addSound(Sound(Sound::DESTRUCTION, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file")));
else if (this->_parser.getValueOf("id") == "DEAD_SOUND")
	rm->getSoundManager().addSound(Sound(Sound::DEAD, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file")));
else if (this->_parser.getValueOf("id") == "AMBIANT_SOUND")
	rm->getSoundManager().addSound(Sound(Sound::AMBIANT, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file")));
else if (this->_parser.getValueOf("id") == "JUMP_SOUND")
	rm->getSoundManager().addSound(Sound(Sound::JUMP, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file")));
      else
	rm->getSoundManager().addSound(Sound(Sound::UNKNOWN, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file")));
    }
  this->_parser.resetNode();
  std::cout << "MODELS" << std::endl;
  this->_parser.setNode("scene");
  this->_parser.setNode("model_pack");
  while (this->_parser.foreach("model"))
    {
      if (this->_parser.checkMultipleTag() == false)
	std::cout << this->_parser.getError();
      if (this->_parser.isBool(this->_parser.getValueOf("online")) == false)
	{
	  std::cout << "Error in model : \"" << this->_parser.getValueOf("id") << "\" online tag must be a boolean" << std::endl;
	  continue;
	}
      rm->getModelManager().addModel(this->_parser.getValueOf("file"), this->_parser.getValueOf("id"));
    }
  this->_parser.resetNode();
  this->_parser.setNode("scene");
  std::cout << std::endl << "COMMON :" << std::endl;
  this->_parser.setNode("common");
  if (this->_parser.checkMultipleTag() == false)
    std::cout << this->_parser.getError();
if (this->_parser.isNum(this->_parser.getValueOf("width")) == false
    || this->_parser.isNum(this->_parser.getValueOf("height")) == false)
  std::cout << "Error in common : \"width\" and \"height\" tags must be numbers" << std::endl;
 else
   {
     int mapWidth = atoi(this->_parser.getValueOf("width").c_str());
     int mapHeight = atoi(this->_parser.getValueOf("height").c_str());
     entity = new Floor(glm::vec3(0, 0, 0), mapWidth, mapHeight, rm->getTextureManager().getTexture("idFloorTexture"));
     newScene->addEntity(entity);
   }

 if (this->_parser.isFloatNum(this->_parser.getValueOf("gravity")) == false)
   std::cout << "Error in entity : gravity must be a number" << std::endl;
  std::cout << "gravity : " << this->_parser.getValueOf("gravity") << std::endl;
 if (this->_parser.isFloatNum(this->_parser.getValueOf("friction")) == false)
   std::cout << "Error in entity : friction must be a number" << std::endl;
  std::cout << "friction : " << this->_parser.getValueOf("friction") << std::endl;
  std::cout << "texture : " << this->_parser.getValueOf("texture") << std::endl;
  this->_parser.setNode("skybox");
  if (this->_parser.checkMultipleTag() == false)
    std::cout << this->_parser.getError();
      if (this->_parser.isBool(this->_parser.getValueOf("online")) == false)
	std::cout << "Error in common : online tag must be a boolean" << std::endl;
  std::cout << "online : " << this->_parser.getValueOf("online") << std::endl;
  std::cout << "file : " << this->_parser.getValueOf("file") << std::endl;

  this->_parser.resetNode();
  this->_parser.setNode("scene");
  std::cout << std::endl << "ENTITIES :" << std::endl;
  this->_parser.setNode("entities");
  while (this->_parser.foreach("entity"))
    {
      if (this->_parser.checkMultipleTag() == false)
	std::cout << this->_parser.getError();
      if (this->_parser.getValueOf("type") == "BOMBERMAN")
	{
	  std::string	name = this->_parser.getValueOf("name");
	  this->_parser.setNode("position");
	  if (this->_parser.checkMultipleTag() == false)
	    std::cout << this->_parser.getError();
	  if (this->_parser.isNum(this->_parser.getValueOf("x")) == false
	      || this->_parser.isNum(this->_parser.getValueOf("y")) == false
	      || this->_parser.isNum(this->_parser.getValueOf("z")) == false)
	    {
	      std::cout << "Error in entity : positions must be numbers" << std::endl;
	      this->_parser.setPreviousNode();
	      continue;
	    }
	  entity = new Bomberman(glm::vec3(atof(this->_parser.getValueOf("x").c_str()),
					   atof(this->_parser.getValueOf("y").c_str()),
					   atof(this->_parser.getValueOf("z").c_str())),
				 name);
	  this->_parser.setPreviousNode();
	}
      else if (this->_parser.getValueOf("type") == "BRICK_WALL" || this->_parser.getValueOf("type") == "WOOD_WALL")
	{
	  this->_parser.setNode("position");
	  if (this->_parser.checkMultipleTag() == false)
	    std::cout << this->_parser.getError();
	  if (this->_parser.isNum(this->_parser.getValueOf("x")) == false
	      || this->_parser.isNum(this->_parser.getValueOf("y")) == false
	      || this->_parser.isNum(this->_parser.getValueOf("z")) == false)
	    {
	      std::cout << "Error in entity : positions must be numbers" << std::endl;
	      this->_parser.setPreviousNode();
	      continue;
	    }
	  entity = new BrickWall(glm::vec3(atof(this->_parser.getValueOf("x").c_str()),
					   atof(this->_parser.getValueOf("y").c_str()),
					   atof(this->_parser.getValueOf("z").c_str())));
	  this->_parser.setPreviousNode();
	}
      else
	{
	  std::cout << "Unknown type : " << this->_parser.getValueOf("type") << std::endl;
	  continue;
	}
      this->_parser.setNode("attribut");
      if (this->_parser.checkMultipleTag() == false)
	std::cout << this->_parser.getError();
      if (this->_parser.isNum(this->_parser.getValueOf("speed")) == false)
	{
	  std::cout << "Error in entity : speed must be a number" << std::endl;
	  this->_parser.setPreviousNode();
	  delete entity;
	  continue;
	}
      entity->setSpeed(atof(this->_parser.getValueOf("speed").c_str()));
      if (this->_parser.isNum(this->_parser.getValueOf("jump")) == false)
	{
	  std::cout << "Error in entity : jump must be a number" << std::endl;
	  this->_parser.setPreviousNode();
	  delete entity;
	  continue;
	}
      entity->setJump((atoi(this->_parser.getValueOf("jump").c_str()) == 0) ? false : true);
      if (this->_parser.isFloatNum(this->_parser.getValueOf("friction")) == false)
	{
	  std::cout << "Error in entity : friction must be a float number" << std::endl;
	  this->_parser.setPreviousNode();
	  delete entity;
	  continue;
	}
      entity->setFriction(atof(this->_parser.getValueOf("friction").c_str()));
      if (this->_parser.isBool(this->_parser.getValueOf("move")) == false)
	{
	  std::cout << "Error in entity : move must be a boolean" << std::endl;
	  this->_parser.setPreviousNode();
	  delete entity;
	  continue;
	}
      entity->setMove((atoi(this->_parser.getValueOf("move").c_str()) == 0) ? false : true);
      if (this->_parser.isFloatNum(this->_parser.getValueOf("range")) == false)
	{
	  std::cout << "Error in entity : range must be a float number" << std::endl;
	  this->_parser.setPreviousNode();
	  delete entity;
	  continue;
	}
      entity->setRange(atof(this->_parser.getValueOf("range").c_str()));
      if (this->_parser.isNum(this->_parser.getValueOf("weight")) == false)
	{
	  std::cout << "Error in entity : weight must be a number" << std::endl;
	  this->_parser.setPreviousNode();
	  delete entity;
	  continue;
	}
      entity->setWeight((atoi(this->_parser.getValueOf("weight").c_str())));
      if (this->_parser.getValueOf("ability") == "NONE")
	entity->setAbility(ASolid::NONE_ABILITY);
      else
	{
	  std::cout << "Unknown ability : " << this->_parser.getValueOf("ability") << std::endl;
	  this->_parser.setPreviousNode();
	  delete entity;
	  continue;
	}
      if (this->_parser.getValueOf("bonus") == "NONE")
	entity->setBonus(ASolid::NONE_BONUS);
      else
	{
	  std::cout << "Unknown bonus : " << this->_parser.getValueOf("bonus") << std::endl;
	  this->_parser.setPreviousNode();
	  delete entity;
	  continue;
	}
      this->_parser.setPreviousNode();
      if (this->_parser.isNum(this->_parser.getValueOf("health")) == false)
	{
	  std::cout << "Error in entity : health must be a number" << std::endl;
	  delete entity;
	  continue;
	}
      entity->setHealth((atoi(this->_parser.getValueOf("health").c_str())));
      entity->setModelId(std::string(this->_parser.getValueOf("model").c_str()));
      entity->setTexture(std::string(this->_parser.getValueOf("texture").c_str()));
      this->_parser.setNode("size");
      if (this->_parser.checkMultipleTag() == false)
	std::cout << this->_parser.getError();
	  if (this->_parser.isFloatNum(this->_parser.getValueOf("x")) == false
	      || this->_parser.isFloatNum(this->_parser.getValueOf("y")) == false
	      || this->_parser.isFloatNum(this->_parser.getValueOf("z")) == false)
	    {
	      std::cout << "Error in entity : sizes must be numbers" << std::endl;
	      this->_parser.setPreviousNode();
	      delete entity;
	      continue;
	    }
      entity->setScale(glm::vec3(atof(this->_parser.getValueOf("x").c_str()),
				 atof(this->_parser.getValueOf("y").c_str()),
				 atof(this->_parser.getValueOf("z").c_str())));
      this->_parser.setPreviousNode();
      newScene->addEntity(entity);
    }
  return (newScene);
}
