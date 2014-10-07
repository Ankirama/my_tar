/*
** my_append_nbr.h for my_append_nbr.c in /home/mar_b/rendu/my_tar
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat May  3 12:51:29 2014 Fabien Martinez
** Last update Sat May  3 16:25:52 2014 Fabien Martinez
*/

#ifndef MY_APPEND_NBR_H_
# define MY_APPEND_NBR_H_

void	my_append_octal(char *str, int oct, int size);
void	my_append_int(char *str, int nbr, int size);
void	my_append_dev(char *str, int nbr, int size, mode_t st_mode);

#endif /* !MY_APPEND_NBR_H_ */
