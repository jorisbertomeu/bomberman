/*
** parserXml.h for  in /home/mediav_j/mabm/bomberman/parserXML
** 
** Made by Jérémy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Fri May 22 15:07:06 2015 Jérémy Mediavilla
// Last update Mon Jun  1 17:02:00 2015 Jérémy Mediavilla
*/

#ifndef		_PARSERXML_HH_
# define	_PARSERXML_HH_

# include <stdlib.h>
# include <libxml/parser.h>
# include <libxml/tree.h>
# include <string.h>
# include <sstream>

class		ParserXML
{
private:
  typedef struct	s_tag
  {
    char		*name;
    int			nb;
    int			lines[4096];
  }			t_tag;

private:
  xmlDocPtr		_doc;
  xmlNodePtr		_node;
  xmlNodePtr		_parent;
  std::string		_error;

public:
  explicit		ParserXML();
  virtual		~ParserXML();
  bool			loadFile(const std::string &);
  bool			setNode(const std::string &);
  bool			setPreviousNode();
  bool			resetNode();
  std::string		getValueOf(const std::string &);
  std::string		getError();
  bool			checkMultipleTag();
  bool			foreach(const std::string &);
  const xmlChar		*getNodeName();

private:
  t_tag			*getMultipleTag();
  int			getTagPos(ParserXML::t_tag *, char *);
};

#endif		/* _PARSERXML_HH_ */