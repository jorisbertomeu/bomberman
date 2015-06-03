//
// SceneParser.cpp for  in /home/mediav_j/mabm/bomberman/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Mon Jun  1 15:13:39 2015 Jérémy Mediavilla
// Last update Wed Jun  3 15:28:06 2015 Jérémy Mediavilla
//

#include "SceneParser.hh"

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

Scene		SceneParser::getScene()
{
  Scene		newScene;
  AEntity	*entity;

  this->_parser.setNode("scene");

  std::cout << "PARAMETERS :" << std::endl;
  this->_parser.setNode("parameters");
  std::cout << "author : " << this->_parser.getValueOf("author") << std::endl;
  std::cout << "id : " << this->_parser.getValueOf("id") << std::endl;
  std::cout << "level : " << this->_parser.getValueOf("level") << std::endl;
  std::cout << "date : " << this->_parser.getValueOf("date") << std::endl;
  std::cout << "score : " << this->_parser.getValueOf("score") << std::endl;
  std::cout << "bots : " << this->_parser.getValueOf("bots") << std::endl;
  std::cout << "ia_difficulty : " << this->_parser.getValueOf("ia_difficulty") << std::endl;

  this->_parser.resetNode();
  this->_parser.setNode("scene");
  std::cout << std::endl << "TEXTURE_PACK :" << std::endl;
  this->_parser.setNode("texture_pack");
  while (this->_parser.foreach("texture"))
    {
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
      std::cout << "id : " << this->_parser.getValueOf("id") << std::endl;
      std::cout << "online : " << this->_parser.getValueOf("online") << std::endl;
      std::cout << "file : " << this->_parser.getValueOf("file") << std::endl << std::endl;
    }

  this->_parser.resetNode();
  this->_parser.setNode("scene");
  std::cout << std::endl << "COMMON :" << std::endl;
  this->_parser.setNode("common");
  std::cout << "width : " << this->_parser.getValueOf("width") << std::endl;
  std::cout << "height : " << this->_parser.getValueOf("height") << std::endl;
  std::cout << "gravity : " << this->_parser.getValueOf("gravity") << std::endl;
  std::cout << "friction : " << this->_parser.getValueOf("friction") << std::endl;
  std::cout << "texture : " << this->_parser.getValueOf("texture") << std::endl;
  this->_parser.setNode("skybox");
  std::cout << "online : " << this->_parser.getValueOf("online") << std::endl;
  std::cout << "file : " << this->_parser.getValueOf("file") << std::endl;

  this->_parser.resetNode();
  this->_parser.setNode("scene");
  std::cout << std::endl << "ENTITIES :" << std::endl;
  this->_parser.setNode("entities");
  while (this->_parser.foreach("entity"))
    {
      if (this->_parser.getValueOf("type") == "BOMBERMAN")
	{
	  std::string	name = this->_parser.getValueOf("name");
	  this->_parser.setNode("position");
	  entity = new Bomberman(glm::vec3(atof(this->_parser.getValueOf("x").c_str()),
					   atof(this->_parser.getValueOf("y").c_str()),
					   atof(this->_parser.getValueOf("z").c_str())),
				 name);
	  this->_parser.setPreviousNode();
	}
      else if (this->_parser.getValueOf("type") == "BRICK_WALL")
	{
	  this->_parser.setNode("position");
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
      entity->setSpeed(atof(this->_parser.getValueOf("speed").c_str()));
      entity->setJump((atoi(this->_parser.getValueOf("jump").c_str()) == 0) ? false : true);
      entity->setFriction(atof(this->_parser.getValueOf("friction").c_str()));
      entity->setMove((atoi(this->_parser.getValueOf("move").c_str()) == 0) ? false : true);
      entity->setRange(atof(this->_parser.getValueOf("range").c_str()));
      entity->setWeight((atoi(this->_parser.getValueOf("wieght").c_str())));
      if (this->_parser.getValueOf("ability") == "NONE")
	{
	  // std::cout << "ok" << std::endl;
	  entity->setAbility(ASolid::NONE_ABILITY);
	}
      else
	{
	  std::cout << "Unknown ability : " << this->_parser.getValueOf("ability") << std::endl;
	  this->_parser.setPreviousNode();
	  delete entity;
	  continue;
	}
      if (this->_parser.getValueOf("bonus") == "NONE")
	{
	  std::cout << "BONUS A SET" << std::endl;
	  // entity->setBonus(ASolid::NONE_BONUS);
	}
      else
	{
	  std::cout << "Unknown bonus : " << this->_parser.getValueOf("bonus") << std::endl;
	  this->_parser.setPreviousNode();
	  delete entity;
	  continue;
	}
      this->_parser.setPreviousNode();
      entity->setHealth((atoi(this->_parser.getValueOf("health").c_str())));
      entity->setTexture(std::string(this->_parser.getValueOf("texture").c_str()));
      this->_parser.setNode("size");
      entity->setSize(glm::vec3(atof(this->_parser.getValueOf("x").c_str()),
				atof(this->_parser.getValueOf("y").c_str()),
				atof(this->_parser.getValueOf("z").c_str())));
      this->_parser.setPreviousNode();
    }
  return (newScene);
}
