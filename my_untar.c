/*
** my_untar.c for my_untar.c in /home/mar_b/rendu/my_tar
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat May  3 19:26:32 2014 Fabien Martinez
** Last update Sun May  4 20:55:38 2014 Fabien Martinez
*/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my_untar.h"
#include "my_create.h"
#include "my_fun.h"
#include "my_file.h"

int	my_fill_elt(char *header, char *elt, int start, int end)
{
  int	i;

  i = 0;
  while (start < end)
    elt[i++] = header[start++];
  return (start);
}

static void	my_wrong_header(int len)
{
  if (len < MAX_SIZE)
    {
      printf("Error: Problem with header, is it a tar file ?\n");
      exit(EXIT_FAILURE);
    }
}

void	my_convert_elt(mode_t *mode, uid_t *owner, gid_t *grp, t_my_file *file)
{
  *mode = strtol(file->mode, NULL, 8);
  *owner = strtol(file->uid, NULL, 8);
  *grp = strtol(file->gid, NULL, 8);
}

void		my_untar(int fd, char *opt)
{
  int		len;
  char		buff[MAX_SIZE];
  int		my_fd;
  t_my_file	*my_file;

  buff[0] = 'a';
  while (!my_check_block(buff))
    {
      if ((len = read(fd, buff, MAX_SIZE)) == -1)
	my_puterror(1, errno);
      my_wrong_header(len);
      if (!my_check_block(buff))
	{
	  my_file = my_create_header(buff);
	  if (my_file->typeflag == '5')
	    my_createdir(my_file, opt);
	  else
	    my_createfile(fd, my_file, opt);
	  free(my_file);
	}
    }
}
