/*
** main.c for h in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue May 28 17:55:49 2013 guillaume duez
** Last update Wed Jun 26 13:08:40 2013 florian dewulf
*/

#include	<time.h>
#include	<stdlib.h>
#include	"serveur.h"

int		give_id()
{
  static int	ret = -1;

  ret++;
  return (ret);
}

int             main(int ac, char **av)
{
  srand(time(NULL));
  if (ac < 2)
    {
      usage();
      return (1);
    }
  parse_args(ac, av);
  return (0);
}
