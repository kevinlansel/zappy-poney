/*
** main.c for h in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue May 28 17:55:49 2013 guillaume duez
** Last update Thu Jun 27 18:10:53 2013 florian dewulf
*/

#include	<stdio.h>
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
      printf("-p numero de port\n-x largeur du monde\n-y hauteur du monde\n");
      printf("-n nom (team_1 team_2 ...)\n-c nombre de client par equipe\n");
      printf("-t delai temporel\n");
      return (1);
    }
  parse_args(ac, av);
  return (0);
}
