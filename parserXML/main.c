/*
** main.c for  in /home/mediav_j/libxml
** 
** Made by Jérémy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Thu May 21 17:08:57 2015 Jérémy Mediavilla
** Last update Tue May 26 13:21:10 2015 Jérémy Mediavilla
*/

#include "parserXml.h"

int		loadFile(xmlDocPtr *doc, char *file)
{
  if ((*doc = xmlParseFile(file)) == NULL)
    {
      fprintf(stderr, "Document not parsed successfully.\n");
      return (-1);
    }
  return (0);
}

int		docGetRoot(xmlNodePtr *cur, xmlDocPtr doc)
{
  if ((*cur = xmlDocGetRootElement(doc)) == NULL)
    {
      fprintf(stderr, "Empty document.\n");
      xmlFreeDoc(doc);
      return (-1);
    }
  return (0);
}

int		checkRoot(xmlNodePtr cur, xmlDocPtr doc)
{
  if (xmlStrcmp(cur->name, (const xmlChar *)"scene"))
    {
      fprintf(stderr, "Document of the wrong type. Root node must be \"scene\"\n");
      xmlFree(cur);
      xmlFreeDoc(doc);
      return (-1);
    }
  return (0);
}

int		getTagPos(t_tag *tab, char *tagName)
{
  int		i;

  for (i = 0; tab[i].name != NULL; i++)
    if (strcmp(tagName, tab[i].name) == 0)
      return (i);
  return (-1);
}

xmlChar		*getValueFromTag(xmlNodePtr cur, char *tag)
{
  xmlNodePtr	tmp;

  tmp = cur->xmlChildrenNode;
  while (tmp != NULL)
    {
      printf("%s\n", tmp->name);
      if (xmlStrcmp(tmp->name, (const xmlChar *) tag) == 0)
	return (xmlNodeGetContent(tmp));
      tmp = tmp->next;
    }
  return (NULL);
}

t_tag		*isMultipleNode(xmlNodePtr cur)
{
  t_tag		*tags;
  int		i;
  int		tmp;
  int		mult;
  int		j;

  /* Vérifier si la balise est valide - ou pas */
  tags = malloc(42 * sizeof(t_tag));
  for (i = 0; i < 42; i++)
    tags[i].name = NULL;
  i = 0;
  mult = 0;
  cur = cur->xmlChildrenNode;
  while (cur != NULL)
    {
      if ((tmp = getTagPos(tags, (char *)cur->name)) == -1)
	{
	  tags[i].name = strdup((char*)cur->name);
	  tags[i].nb = 1;
	  tags[i].lines = malloc(4096 * sizeof(int));
	  for (j = 0; j < 4096; j++)
	    tags[i].lines[j] = 0;
	  tags[i].lines[0] = cur->line;
	  i++;
	}
      else
	{
	  mult = 1;
	  tags[tmp].nb += 1;
	  if (tags[tmp].nb < 4096)
	    tags[tmp].lines[tags[tmp].nb - 1] = cur->line;
	}
      cur = cur->next;
    }
  if (mult == 0)
    {
      free(tags);
      return (NULL);
    }
  else
    return (tags);
}

void		multipleNodeError(t_tag *tags)
{
  int		i;
  int		j;

  for (i = 0; tags[i].name != NULL; i++)
    if (tags[i].nb > 1)
      {
	fprintf(stderr, "Error: multiple déclaration of \"<%s>\" :\n", tags[i].name);
	for (j = 0; tags[i].lines[j] > 0; j++)
	  fprintf(stderr, "\tdeclared line %i\n", tags[i].lines[j]);
      }
}

void		getParameters(xmlNodePtr cur)
{
  t_tag		*tmp;

  if ((tmp = isMultipleNode(cur)) != NULL)
    {
      multipleNodeError(tmp);
      free(tmp);
      /* return */
    }
  printf("--> param\n");
}

void		getTextures(xmlNodePtr cur)
{
  t_tag		*error;

  cur = cur->xmlChildrenNode;
  while (cur != NULL)
    {
      if (xmlStrcmp(cur->name, (const xmlChar *)"texture"))
	{
	  fprintf(stderr, "Error : unknown tag \"<%s>\" declared line %i\n", cur->name, cur->line);
	  /* return */
	}
      if ((error = isMultipleNode(cur)) != NULL)
	{
	  multipleNodeError(error);
	  free(error);
	  /* return */
	}
      cur = cur->next;
    }
  printf("--> texture\n");
}

void		getSounds(xmlNodePtr cur)
{
  t_tag		*error;

  cur = cur->xmlChildrenNode;
  while (cur != NULL)
    {
      if (xmlStrcmp(cur->name, (const xmlChar *)"sound"))
	{
	  fprintf(stderr, "Error : unknown tag \"<%s>\" declared line %i\n", cur->name, cur->line);
	  /* return */
	}
      if ((error = isMultipleNode(cur)) != NULL)
	{
	  multipleNodeError(error);
	  free(error);
	  /* return */
	}
      cur = cur->next;
    }
  printf("--> sound\n");
}

void		getCommon(xmlNodePtr cur)
{
  t_tag		*tmp;

  if ((tmp = isMultipleNode(cur)) != NULL)
    {
      multipleNodeError(tmp);
      free(tmp);
      /* return */
    }
  printf("--> common\n");
}

void		getEntities(xmlNodePtr cur)
{
  xmlNodePtr	child;
  t_tag		*tmp;

  cur = cur->xmlChildrenNode;
  while (cur != NULL)
    {
      if (xmlStrcmp(cur->name, (const xmlChar *)"entity"))
	{
	  fprintf(stderr, "Error : unknown tag \"<%s>\" declared line %i\n", cur->name, cur->line);
	  /* return */
	}
      if ((tmp = isMultipleNode(cur)) != NULL)
	{
	  multipleNodeError(tmp);
	  free(tmp);
	  /* return */
	}
      child = cur->xmlChildrenNode;
      while (child != NULL)
	{
	  if (xmlStrcmp(child->name, (const xmlChar *)"attribut") == 0)
	    printf("***** %s\n", child->name);
	  printf("\tchild : %s\n", child->name);
	  child = child->next;
	}
      cur = cur->next;
    }
  printf("--> entities\n");
}

int		parseTag(char *tag, xmlNodePtr cur)
{
  void		(*whichTag[5])();
  char		*tagTab[5];
  int		i;

  whichTag[0] = &getParameters;
  whichTag[1] = &getTextures;
  whichTag[2] = &getSounds;
  whichTag[3] = &getCommon;
  whichTag[4] = &getEntities;
  tagTab[0] = PARAMETERS_TAG;
  tagTab[1] = TEXTURE_TAG;
  tagTab[2] = SOUND_TAG;
  tagTab[3] = COMMON_TAG;
  tagTab[4] = ENTITY_TAG;
  for (i = 0; i != 5; i++)
    if (strcmp(tag, tagTab[i]) == 0)
      {
	(*whichTag[i])(cur);
	return (0);
      }
  fprintf(stderr, "Error : unknown tag \"%s\" at line %i\n", tag, cur->line);
  return (-1);
}

int		main(int ac, char **av)
{
  xmlDocPtr	doc;
  xmlNodePtr	cur;
  t_tag		*tmp;

  xmlKeepBlanksDefault(0);
  if (ac != 2)
    {
      fprintf(stderr, "No parameters\n");
      return (EXIT_FAILURE);
    }
  if (loadFile(&doc, av[1]) == -1 || docGetRoot(&cur, doc) == -1 || checkRoot(cur, doc) == -1)
    return (EXIT_FAILURE);
  if ((tmp = isMultipleNode(cur)) != NULL)
    {
      multipleNodeError(tmp);
      free(tmp);
      xmlFree(cur);
      xmlFreeDoc(doc);
      return (EXIT_FAILURE);
    }
  cur = cur->xmlChildrenNode;
  while (cur != NULL)
    {
      if (parseTag((char *) cur->name, cur) == -1)
	{
	  xmlFree(cur);
	  xmlFreeDoc(doc);
	  return (EXIT_FAILURE);
	}
      cur = cur->next;
    }
  xmlFree(cur);
  xmlFreeDoc(doc);
  return (EXIT_SUCCESS);
}
