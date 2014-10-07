/*
** my_append.h for my_append in /home/mar_b/rendu/my_tar
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat May  3 14:25:21 2014 Fabien Martinez
** Last update Sat May  3 18:43:20 2014 Fabien Martinez
*/

#ifndef MY_APPEND_H_
# define MY_APPEND_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void	my_append_data(char *str, char *data);
void	my_append_chksum(char *str, t_my_file *file, int tot);
void	my_append_link(char *my_link, char *str, struct stat *buf);
void	my_append_uid(char *str, struct stat *buf, char type);
char	my_type_file(struct stat *buf);

#endif /* !MY_APPEND_H_ */
