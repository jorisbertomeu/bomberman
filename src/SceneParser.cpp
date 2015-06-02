//
// SceneParser.cpp for  in /home/mediav_j/mabm/bomberman/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Mon Jun  1 15:13:39 2015 Jérémy Mediavilla
// Last update Tue Jun  2 15:42:11 2015 Jérémy Mediavilla
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
      this->_parser.setNode("attribut");
      std::cout << "speed : " << this->_parser.getValueOf("speed") << std::endl;
      std::cout << "jump : " << this->_parser.getValueOf("jump") << std::endl;
      std::cout << "weigth : " << this->_parser.getValueOf("weigth") << std::endl;
      std::cout << "friction : " << this->_parser.getValueOf("friction") << std::endl;
      std::cout << "move : " << this->_parser.getValueOf("move") << std::endl;
      std::cout << "ability : " << this->_parser.getValueOf("ability") << std::endl;
      std::cout << "range : " << this->_parser.getValueOf("range") << std::endl;
      std::cout << "bonus : " << this->_parser.getValueOf("bonus") << std::endl;
      this->_parser.setPreviousNode();
      std::cout << "health : " << this->_parser.getValueOf("health") << std::endl;
      std::cout << "type : " << this->_parser.getValueOf("type") << std::endl;
      std::cout << "texture : " << this->_parser.getValueOf("texture") << std::endl;
      this->_parser.setNode("position");
      std::cout << "pos x : " << this->_parser.getValueOf("x") << std::endl;
      std::cout << "pos y : " << this->_parser.getValueOf("y") << std::endl;
      std::cout << "pos z : " << this->_parser.getValueOf("z") << std::endl;
      this->_parser.setPreviousNode();
      this->_parser.setNode("size");
      std::cout << "size x : " << this->_parser.getValueOf("x") << std::endl;
      std::cout << "size y : " << this->_parser.getValueOf("y") << std::endl;
      std::cout << "size z : " << this->_parser.getValueOf("z") << std::endl << std::endl;
    }
  return (newScene);
}
