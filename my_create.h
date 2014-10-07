/*
** my_create.h for my_create in /home/mar_b/rendu/my_tar
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sun May  4 12:34:31 2014 Fabien Martinez
** Last update Sun May  4 20:57:07 2014 Fabien Martinez
*/

#ifndef MY_CREATE_H_
# define MY_CREATE_H_

# include "my_file.h"

t_my_file       *my_create_header(char *str);
void		my_createfile(int fg, t_my_file *my_file, char *opt);
void		my_createdir(t_my_file *my_file, char *opt);

#endif /* !MY_CREATE_H_ */
