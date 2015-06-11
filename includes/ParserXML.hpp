/*
** parserXml.h for  in /home/mediav_j/mabm/bomberman/parserXML
** 
** Made by Jérémy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Fri May 22 15:07:06 2015 Jérémy Mediavilla
// Last update Thu Jun 11 17:47:11 2015 Jérémy Mediavilla
*/

#ifndef		_PARSERXML_HPP_
# define	_PARSERXML_HPP_

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
  std::string		getNodeName();
  bool			isNum(const std::string &);
  bool			isFloatNum(const std::string &);
  bool			isBool(const std::string &);
  bool			isGoodEnd(const std::string &, const std::string &);
  template<typename T>
  bool			isBigger(T nbr,T other) {
    if (nbr > other)
      return (true);
    return (false);
  };
  template<typename T>
  bool			isSmaller(T nbr,T other) {
    if (nbr < other)
      return (true);
    return (false);
  };

private:
  t_tag			*getMultipleTag();
  int			getTagPos(ParserXML::t_tag *, char *);
};

#endif		/* _PARSERXML_HPP_ */
