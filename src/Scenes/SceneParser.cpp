//
// SceneParser.cpp for  in /home/mediav_j/mabm/bomberman/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Jun  1 15:13:39 2015 Jérémy Mediavilla
// Last update Fri Jun 12 22:58:47 2015 Valérian Polizzi
//

#include	<SceneParser.hh>
#include	<Bomberman.hh>
#include	<Bot.hh>
#include	<BrickWall.hh>
#include	<Floor.hh>
#include	<stdexcept>

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

  try {
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
	  throw (std::runtime_error("Error in texture : \"" + this->_parser.getValueOf("online") + "\" online tag must be a boolean"));
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
	throw (std::runtime_error("Error in sound : online tag must be a boolean"));
      if (this->_parser.checkMultipleTag() == false)
	std::cout << this->_parser.getError();
      if (this->_parser.getValueOf("id") == "WALK_SOUND")
	rm->getSoundManager().addSound(new Sound(Sound::WALK, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file"), rm->getSoundManager().getSystem()));
      else if (this->_parser.getValueOf("id") == "EXPLOSION_SOUND")
	rm->getSoundManager().addSound(new Sound(Sound::EXPLOSION, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file"), rm->getSoundManager().getSystem()));
      else if (this->_parser.getValueOf("id") == "WALK_STOP_SOUND")
	rm->getSoundManager().addSound(new Sound(Sound::WALK_STOP, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file"), rm->getSoundManager().getSystem()));
      else if (this->_parser.getValueOf("id") == "DESTRUCTION_SOUND")
	rm->getSoundManager().addSound(new Sound(Sound::DESTRUCTION, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file"), rm->getSoundManager().getSystem()));
      else if (this->_parser.getValueOf("id") == "DEAD_SOUND")
	rm->getSoundManager().addSound(new Sound(Sound::DEAD, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file"), rm->getSoundManager().getSystem()));
      else if (this->_parser.getValueOf("id") == "AMBIANT_SOUND")
	rm->getSoundManager().addSound(new Sound(Sound::AMBIANT, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file"), rm->getSoundManager().getSystem()));
      else if (this->_parser.getValueOf("id") == "JUMP_SOUND")
	rm->getSoundManager().addSound(new Sound(Sound::JUMP, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file"), rm->getSoundManager().getSystem()));
      else
	rm->getSoundManager().addSound(new Sound(Sound::UNKNOWN, atoi(this->_parser.getValueOf("online").c_str()), this->_parser.getValueOf("file"), rm->getSoundManager().getSystem()));
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
	  throw (std::runtime_error("Error in model : \"" + this->_parser.getValueOf("id") + "\" online tag must be a boolean"));
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
 throw (std::runtime_error("Error in common : \"width\" and \"height\" tags must be numbers"));
 else
   {
     int mapWidth = atoi(this->_parser.getValueOf("width").c_str());
     int mapHeight = atoi(this->_parser.getValueOf("height").c_str());
     entity = new Floor(glm::vec3(0, 0, 0), mapWidth, mapHeight, rm->getTextureManager().getTexture("idFloorTexture"));
     newScene->addEntity(entity);
   }

 if (this->_parser.isFloatNum(this->_parser.getValueOf("gravity")) == false)
   throw (std::runtime_error("Error in entity : gravity must be a number"));
 std::cout << "gravity : " << this->_parser.getValueOf("gravity") << std::endl;
 if (this->_parser.isFloatNum(this->_parser.getValueOf("friction")) == false)
   throw (std::runtime_error("Error in entity : friction must be a number"));
 std::cout << "friction : " << this->_parser.getValueOf("friction") << std::endl;
 std::cout << "texture : " << this->_parser.getValueOf("texture") << std::endl;
  this->_parser.setNode("skybox");
  if (this->_parser.checkMultipleTag() == false)
    std::cout << this->_parser.getError();
      if (this->_parser.isBool(this->_parser.getValueOf("online")) == false)
	throw (std::runtime_error("Error in common : online tag must be a boolean"));
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
	      throw (std::runtime_error("Error in entity : positions must be numbers"));
	      this->_parser.setPreviousNode();
	      continue;
	    }
	  entity = new Bomberman(glm::vec3(atof(this->_parser.getValueOf("x").c_str()),
					   atof(this->_parser.getValueOf("y").c_str()),
					   atof(this->_parser.getValueOf("z").c_str())),
				 name);
	  this->_parser.setPreviousNode();
	}
      else if (this->_parser.getValueOf("type") == "BOT")
	{
	  std::cout << "BOT !" << std::endl;
	  std::string	name = this->_parser.getValueOf("name");
	  this->_parser.setNode("position");
	  if (this->_parser.checkMultipleTag() == false)
	    std::cout << this->_parser.getError();
	  if (this->_parser.isNum(this->_parser.getValueOf("x")) == false
	      || this->_parser.isNum(this->_parser.getValueOf("y")) == false
	      || this->_parser.isNum(this->_parser.getValueOf("z")) == false)
	    {
	      throw (std::runtime_error("Error in entity : positions must be numbers"));
	      this->_parser.setPreviousNode();
	      continue;
	    }
	  entity = new Bot(glm::vec3(atof(this->_parser.getValueOf("x").c_str()),
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
	    throw (std::runtime_error("Error in entity : positions must be numbers"));
	  entity = new BrickWall(glm::vec3(atof(this->_parser.getValueOf("x").c_str()),
					   atof(this->_parser.getValueOf("y").c_str()),
					   atof(this->_parser.getValueOf("z").c_str())));
	  this->_parser.setPreviousNode();
	}
      else
	throw (std::runtime_error("Unknown type : " + this->_parser.getValueOf("type")));
      this->_parser.setNode("attribut");
      if (this->_parser.checkMultipleTag() == false)
	std::cout << this->_parser.getError();
      if (this->_parser.isNum(this->_parser.getValueOf("speed")) == false)
	{
	  delete entity;
	  throw (std::runtime_error("Error in entity : speed must be a number"));
	}
      entity->setSpeed(atof(this->_parser.getValueOf("speed").c_str()));
      if (this->_parser.isNum(this->_parser.getValueOf("jump")) == false)
	{
	  delete entity;
	  throw (std::runtime_error("Error in entity : jump must be a number"));
	}
      entity->setJump((atoi(this->_parser.getValueOf("jump").c_str()) == 0) ? false : true);
      if (this->_parser.isFloatNum(this->_parser.getValueOf("friction")) == false)
	{
	  delete entity;
	  throw (std::runtime_error("Error in entity : friction must be a float number"));
	}
      entity->setFriction(atof(this->_parser.getValueOf("friction").c_str()));
      if (this->_parser.isBool(this->_parser.getValueOf("move")) == false)
	{
	  delete entity;
	  throw (std::runtime_error("Error in entity : move must be a boolean"));
	}
      entity->setMove((atoi(this->_parser.getValueOf("move").c_str()) == 0) ? false : true);
      if (this->_parser.isFloatNum(this->_parser.getValueOf("range")) == false)
	{
	  delete entity;
	  throw (std::runtime_error("Error in entity : range must be a float number"));
	}
      entity->setRange(atof(this->_parser.getValueOf("range").c_str()));
      if (this->_parser.isNum(this->_parser.getValueOf("weight")) == false)
	{
	  delete entity;
	  throw (std::runtime_error("Error in entity : weight must be a number"));
	}
      entity->setWeight((atoi(this->_parser.getValueOf("weight").c_str())));
      if (this->_parser.getValueOf("ability") == "NONE")
	entity->setAbility(ASolid::NONE_ABILITY);
      else
	{
	  delete entity;
	  throw (std::runtime_error("Unknown ability : " + this->_parser.getValueOf("ability")));
	}
      if (this->_parser.getValueOf("bonus") == "NONE")
	entity->setBonus(ASolid::NONE_BONUS);
      else
	{
	  delete entity;
	  throw (std::runtime_error("Unknown bonus : " + this->_parser.getValueOf("bonus")));
	}
      this->_parser.setPreviousNode();
      if (this->_parser.isNum(this->_parser.getValueOf("health")) == false)
	{
	  delete entity;
	  throw (std::runtime_error("Error in entity : health must be a number"));
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
	      delete entity;
	      throw (std::runtime_error("Error in entity : sizes must be numbers"));
	    }
      entity->setScale(glm::vec3(atof(this->_parser.getValueOf("x").c_str()),
				 atof(this->_parser.getValueOf("y").c_str()),
				 atof(this->_parser.getValueOf("z").c_str())));
      this->_parser.setPreviousNode();
      newScene->addEntity(entity);
    }
  }
  catch (const std::exception &e){
    std::cerr << e.what() << std::endl;
    abort();
  }
  return (newScene);
}
