/*
** my_tar.h for my_tar in /home/mar_b/rendu/my_tar
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat May  3 11:13:16 2014 Fabien Martinez
** Last update Sun May  4 20:39:29 2014 Fabien Martinez
*/

#ifndef MY_TAR_H_
# define MY_TAR_H_

void	my_writeparam(FILE *file, char *str, int size);
void    my_tar(char *str, FILE *tar, char *opt);

#endif /* !MY_TAR_H_ */
