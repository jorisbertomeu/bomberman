//
// SceneParser.hh for  in /home/mediav_j/mabm/bomberman/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Jun  1 15:09:44 2015 Jérémy Mediavilla
// Last update Thu Jun 11 17:45:12 2015 Jérémy Mediavilla
//

#ifndef		_SCENEPARSER_HH_
# define	_SCENEPARSER_HH_

# include	<iostream>
# include	<ParserXML.hpp>
# include	<Scene.hh>
# include	<Bomberman.hh>
# include	<BrickWall.hh>
# include	<Floor.hh>

class		SceneParser
{
private:
  ParserXML	_parser;

public:
  explicit	SceneParser();
  virtual	~SceneParser();
  bool		load(const std::string &);
  Scene		*getScene(RenderManager *);
};

#endif		// _SCENEPARSER_HH_
