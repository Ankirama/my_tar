/*
** my_dir.c for my_dir in /home/mar_b/rendu/my_tar
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sun May  4 18:21:03 2014 Fabien Martinez
** Last update Sun May  4 18:49:51 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "my_fun.h"

char	*my_pathfile(char *path, char *name)
{
  char	*res;
  int	i;
  int	j;

  if ((res = malloc(my_strlen(path) + my_strlen(name) + 1)) == NULL)
    my_puterror(0, 0);
  i = 0;
  j = 0;
  while (path[i])
    res[i] = path[i++];
  while (name[j])
    res[i++] = name[j++];
  res[i] = '\0';
  return (res);
}

char	*my_add_slash_dir(char *str)
{
  char	*res;
  int	i;

  if (str[my_strlen(str) - 1] == '/')
    return (str);
  if ((res = malloc(my_strlen(str) + 1)) == NULL)
    my_puterror(0, 0);
  i = 0;
  while (str[i])
    res[i] = str[i++];
  res[i++] = '/';
  res[i] = '\0';
  return (res);
}
