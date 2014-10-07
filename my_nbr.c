/*
** my_nbr.c for my_nbr.c in /home/mar_b/rendu/my_tar
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sun May  4 01:49:23 2014 Fabien Martinez
** Last update Sun May  4 11:11:45 2014 Fabien Martinez
*/

int	my_pow(int nbr, int expo)
{
  if (expo == 0)
    return (1);
  else
    return (nbr * my_pow(nbr, expo - 1));
}

int	oct_to_int(int oct)
{
  int	nbr;
  int	i;
  int	tmp;

  nbr = 0;
  i = 0;
  while (oct != 0)
    {
      tmp = oct % 10;
      oct = oct / 10;
      nbr = nbr + tmp * my_pow(8, i);
      i += 1;
    }
  return (nbr);
}
