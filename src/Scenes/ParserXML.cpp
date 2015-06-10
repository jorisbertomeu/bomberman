//
// ParserXML.cpp for  in /home/mediav_j/mabm/bomberman/parserXML
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Tue May 26 15:18:36 2015 Jérémy Mediavilla
// Last update Wed Jun 10 18:05:30 2015 Jérémy Mediavilla
//

#include "ParserXML.hh"
#include <iostream>

ParserXML::ParserXML()
{

}

ParserXML::~ParserXML()
{

}

bool		ParserXML::loadFile(const std::string &filename)
{
  xmlKeepBlanksDefault(0);
  if ((this->_doc = xmlParseFile((const char *)filename.c_str())) == NULL)
    {
      this->_error = "xmlParseFile error -- a faire\n";
      this->_node = NULL;
      /* utiliser xmlError */
      return (false);
    }
  this->_node = xmlDocGetRootElement(this->_doc);
  return (true);
}

bool		ParserXML::setNode(const std::string &node)
{
  xmlNodePtr	tmp;

  if (this->_node == NULL)
    return (false);
  tmp = this->_node;
  while (tmp != NULL)
    {
      if (xmlStrcmp(tmp->name, (const xmlChar *) node.c_str()) == 0)
	{
	  this->_node = tmp->xmlChildrenNode;
	  return (true);
	}
      tmp = tmp->next;
    }
  this->_error = "node not founded as a current child\n";
  xmlFree(tmp);
  return (false);
}

bool		ParserXML::resetNode()
{
  if (this->_doc == NULL)
    return (false);
  if ((this->_node = xmlDocGetRootElement(this->_doc)) == NULL)
    {
      this->_error = "Empty file\n";
      xmlFreeDoc(this->_doc);
      return (false);
    }
  return (true);
}

std::string	ParserXML::getValueOf(const std::string &tag)
{
  xmlNodePtr	tmp;
  xmlChar	*value;

  if (this->_node == NULL)
    return ("");
  tmp = this->_node;
  while (tmp != NULL)
    {
      if (xmlStrcmp(tmp->name, (const xmlChar *) tag.c_str()) == 0)
	{
	  value = xmlNodeGetContent(tmp);
	  return (std::string((char *)value));
	}
      tmp = tmp->next;
    }
  this->_error = "tag not founded in this node\n";
  xmlFree(tmp);
  return ("");
}

int		ParserXML::getTagPos(ParserXML::t_tag *tab, char *tag)
{
  int		i;

  for (i = 0; tab[i].name != NULL; i++)
    {
      if (strcmp(tag, tab[i].name) == 0)
	return (i);
    }
  return (-1);
}

ParserXML::t_tag		*ParserXML::getMultipleTag()
{
  ParserXML::t_tag		*tags;
  xmlNodePtr	cur;
  int		i;
  int		tmp;
  int		mult;
  int		j;

  /* Vérifier si la balise est valide - ou pas */
  if (this->_node == NULL)
    return (NULL);
  tags = (ParserXML::t_tag *)malloc(2 * sizeof(ParserXML::t_tag));
  for (i = 0; i < 2; i++)
    tags[i].name = NULL;
  i = 0;
  mult = 0;
  cur = this->_node;
  while (cur != NULL)
    {
      if ((tmp = getTagPos(tags, (char*) cur->name)) == -1)
	{
	  tags = (ParserXML::t_tag *)realloc(tags, (i + 2) * sizeof(ParserXML::t_tag));
	  tags[i + 1].name = NULL;
	  tags[i].name = strdup((char*)cur->name);
	  tags[i].nb = 1;
	  for (j = 0; j < 4096; j++)
	    tags[i].lines[j] = 0;
	  tags[i].lines[0] = cur->line;
	  i++;
	}
      else
	{
	  mult = 1;
	  tags[tmp].nb += 1;
	  tags[tmp].lines[tags[tmp].nb - 1] = cur->line;
	}
      cur = cur->next;
    }
  tags[i].name = NULL;
  if (mult == 0)
    {
      free(tags);
      return (NULL);
    }
  else
    return (tags);
}

bool		ParserXML::checkMultipleTag()
{
  ParserXML::t_tag	*tab;
  int		i;
  int		j;
  std::stringstream	ss;

  tab = this->getMultipleTag();
  this->_error = "";
  if (tab == NULL)
    return (true);
  for (i = 0; tab[i].name != NULL; i++)
    if (tab[i].nb > 1)
      {
	ss << "Error: multiple declaration of \"<" << tab[i].name << ">\" :\n";
	for (j = 0; tab[i].lines[j] > 0; j++)
	  ss << "\tdeclared line" << tab[i].lines[j] << "\n";
      }
  this->_error = ss.str();
  return (false);
}

std::string		ParserXML::getError()
{
  return (this->_error);
}

bool			ParserXML::foreach(const std::string &tag)
{
  xmlNodePtr		tmp;
  static int		first = 0;

  if (this->_node == NULL)
    return (false);
  if (!first)
    {
      first = 1;
      tmp = this->_node;
    }
  else
    tmp = this->_node->parent->next;
  while (tmp)
    {
      if (xmlStrcmp(tmp->name, (const xmlChar *) tag.c_str()) == 0)
	{
	  this->_node = tmp->xmlChildrenNode;
	  return (true);
	}
      tmp = tmp->next;
    }
  first = 0;
  xmlFree(tmp);
  return (false);
}

bool			ParserXML::setPreviousNode()
{
  if (!this->_node)
    return (false);
  this->_node = this->_node->parent;
  while (this->_node)
    if (this->_node->prev != NULL)
      this->_node =  this->_node->prev;
    else
      break;
  return (true);
}

std::string		ParserXML::getNodeName()
{
  return (std::string((char *) this->_node->name));
}

bool			ParserXML::isNum(const std::string &num)
{
  int			i;
  const char		*str;

  i = 0;
  str = num.c_str();
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (false);
      i++;
    }
  return (true);
}

bool			ParserXML::isBool(const std::string &num)
{
  if (num.size() != 1)
    return (false);
  if (num != "0" && num != "1")
    return (false);
  return (true);
}

bool			ParserXML::isGoodEnd(const std::string &str, const std::string &extension)
{
  int			i;
  int			delim;
  const char		*ext;
  const char		*name;

  if (extension.size() >= str.size())
    return (false);
  delim = extension.size();
  i = 0;
  ext = extension.c_str();
  name = str.c_str();
  while (name[delim])
    {
      if (name[delim] != ext[i])
	return (false);
      delim++;
      i++;
    }
  return (true);
}

bool			ParserXML::isFloatNum(const std::string &num)
{
  int			i;
  const char		*str;

  i = 0;
  str = num.c_str();
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
	return (false);
      i++;
    }
  return (true);
}
