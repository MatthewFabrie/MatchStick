##
## EPITECH PROJECT, 2021
## my_sokoban
## File description:
## Makefile
##

CC		= gcc
CFLAGS		= -W -Wall -Wextra
CFLAGS	+= -I./include -L./ -lmy

SRC		= $(wildcard SRC/*.c)

OBJ		= $(SRC:.c=.o)

NAME		= matchstick

all		: $(OBJ)
		$(MAKE) -C lib/my/ $@
		$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean		:
		$(RM) $(OBJ)
		$(RM) $(NAME)
		$(RM) *~
		$(RM) /#*#/
		$(MAKE) -C lib/my $@
		$(RM) libmy.a

fclean		:	clean
		$(MAKE) -C lib/my $@

re		:	fclean all
