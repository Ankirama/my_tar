/*
** main.c for main in /home/mar_b/rendu/my_tar
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sun May  4 14:25:01 2014 Fabien Martinez
** Last update Sun May  4 21:04:49 2014 Fabien Martinez
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_fun.h"
#include "my_tar.h"
#include "my_file.h"
#include "my_untar.h"
#include "my_options.h"

void	main_tar(int argc, char **argv, char *opt)
{
  struct stat	*buf;
  t_my_file	*my_file;
  FILE		*my_create;
  int		i;
  char		end[512];

  if ((my_create = fopen(argv[2], "w")) == NULL)
    my_puterror(1, errno);
  printf("Creating archive %s......\n", argv[2]);
  i = 3;
  while (i < argc)
    {
      my_tar(argv[i], my_create, opt);
      i += 1;
    }
  my_init_char(end, 512);
  my_writeparam(my_create, end, 512);
  if (fclose(my_create) == -1)
    my_puterror(1, errno);
  printf("Archive created\n");
}

void	main_untar(char *tar, char *opt)
{
  int	fd;

  if ((fd = open(tar, O_RDONLY)) == -1)
    my_puterror(1, errno);
  printf("Unarchive %s\n", tar);
  my_untar(fd, opt);
  if (close(fd) == -1)
    my_puterror(1, errno);
  printf("done!\n");
}

int	main(int argc, char **argv)
{
  char		opt[6];
  int		i;

  i = 0;
  while (i < 6)
    opt[i++] = 0;
  if (argc < 2 || my_check_options(opt, argv[1]) ||
      (opt[ID_CREATE] && argc < 3 || opt[ID_XTRACT] && argc < 2))
    {
      printf("Usage : ./my_tar [-cxvf] TAR [FILES]\n");
      exit(EXIT_FAILURE);
    }
  if (opt[ID_CREATE])
    main_tar(argc, argv, opt);
  else if (opt[ID_XTRACT])
    main_untar(argv[2], opt);
  return (0);
}
