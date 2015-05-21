/*
** main.c for  in /home/mediav_j/libxml
** 
** Made by Jérémy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Thu May 21 17:08:57 2015 Jérémy Mediavilla
** Last update Thu May 21 17:52:03 2015 Jérémy Mediavilla
*/

#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

int		main(int ac, char **av)
{
  xmlDocPtr	doc;
  xmlNodePtr	cur;

  if (ac != 2)
    {
      fprintf(stderr, "No paramaters\n");
      return (EXIT_FAILURE);
    }
  if ((doc = xmlParseFile(av[1])) == NULL)
    {
      fprintf(stderr, "Document not parsed successfully.\n");
      return (EXIT_FAILURE);
    }
  if ((cur = xmlDocGetRootElement(doc)) == NULL)
    {
      fprintf(stderr, "Empty document.\n");
      xmlFreeDoc(doc);
      return (EXIT_FAILURE);
    }
  if (xmlStrcmp(cur->name, (const xmlChar *)"scene"))
    {
      fprintf(stderr, "Document of the wrong type. Root node must be \"scene\"\n");
      xmlFreeDoc(doc);
      return (EXIT_FAILURE);
    }
  printf("current : %s\n", cur->name);
  cur = cur->xmlChildrenNode;
  while (cur != NULL)
    {
      if (xmlStrcmp(cur->name, (const xmlChar *)"text"))
	printf("[%s]\n", cur->name);
      cur = cur->next;
    }
  return (EXIT_SUCCESS);
}
