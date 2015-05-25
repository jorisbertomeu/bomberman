##
## Makefile for  in /home/mediav_j/libxml
## 
## Made by Jérémy Mediavilla
## Login   <mediav_j@epitech.net>
## 
## Started on  Thu May 21 17:10:28 2015 Jérémy Mediavilla
## Last update Fri May 22 15:49:35 2015 Jérémy Mediavilla
##

NAME		=	xmlParser

SRC		=	main.c			\

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

CFLAGS		+=	-pedantic -g -Wall -Wextra -Werror

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME) `xml2-config --cflags` `xml2-config --libs`

all:		$(NAME)

clean:		
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
