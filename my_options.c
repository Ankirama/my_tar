/*
** my_options.c for my_options.c in /home/mar_b/rendu/my_tar
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sun May  4 14:33:36 2014 Fabien Martinez
** Last update Sun May  4 21:06:57 2014 Fabien Martinez
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_options.h"

static char	my_create_tab_opt(char c)
{
  char		tab[6];
  char		i;

  tab[ID_CREATE] = 'c';
  tab[ID_XTRACT] = 'x';
  tab[ID_VERBOSE] = 'v';
  tab[ID_FILE] = 'f';
  i = 0;
  while (tab[i] && tab[i] != c)
    i += 1;
  return (i);
}

static void	is_good_combo_opt(char *opt)
{
  if ((opt[ID_XTRACT] && !opt[ID_VERBOSE] && !opt[ID_FILE]))
    {
      printf("Usage : ./my_tar [-cxvf] TAR [FILES]\n");
      exit(EXIT_FAILURE);
    }
}

char	my_check_options(char *opt, char *str)
{
  int	i;
  char	c;

  i = str[0] == '-' ? 1 : 0;
  while (str[i])
    {
      if ((c = my_create_tab_opt(str[i])) < 6)
	opt[c] = 1;
      else
	return (1);
      i += 1;
    }
  if (opt[ID_CREATE] && opt[ID_XTRACT])
    {
      printf("Unable to create and extract same files\n");
      exit(EXIT_FAILURE);
    }
  is_good_combo_opt(opt);
  return (0);
}
