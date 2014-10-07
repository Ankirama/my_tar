##
## Makefile for Makefile in /home/mar_b/rendu/PSU_2013_my_ls
##
## Made by Fabien Martinez
## Login   <mar_b@epitech.net>
##
## Started on  Wed Apr 23 01:28:46 2014 Fabien Martinez
## Last update Sun May  4 18:28:35 2014 Fabien Martinez
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -ansi -pedantic

CFLAGS	+= -D_BSD_SOURCE

SRCS	= my_tar.c \
	  my_untar.c \
	  main.c \
	  my_create.c \
	  my_dir.c \
	  my_options.c \
	  my_append.c \
	  my_append_nbr.c \
	  my_file.c \
	  my_nbr.c \
	  my_fun.c

NAME	= my_tar

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
