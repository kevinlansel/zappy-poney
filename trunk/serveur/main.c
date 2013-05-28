/*
** main.c for h in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue May 28 17:55:49 2013 guillaume duez
** Last update Tue May 28 20:50:02 2013 guillaume duez
*/

#include	"serveur.h"

int		usage()
{
  printf("-p numero de port\n-x largeur du monde\n-y hauteur du monde\n");
  printf("-n nom (l'equipe_1 equipe_2 ...)\n-c nombre de client par equipe\n");
  printf("-t delai temporel\n");
  return 0;
}

int		check_val(int val)
{
  if (val != 0)
    return 1;
  return 0;
}

t_opt		*check(int *val, char **name_team)
{
  t_opt		*opt;

  opt = xmalloc(sizeof(t_opt));
  opt->port = val[0];
  if (check_val(opt->port) == 0)
    {
      printf("the port cannot be null\n");
      exit(0);
    }
  opt->x_world = val[1];
  opt->y_world = val[2];
  opt->nb_player = val[3];
  if (check_val(opt->x_world) == 0)
    opt->x_world = 50;
  if (check_val(opt->y_world) == 0)
    opt->y_world = 50;
  if (check_val(opt->nb_player) == 0)
    opt->nb_player = 4;
  opt->time_world = val[4];
  if (check_val(opt->time_world) == 0)
    opt->time_world = 100;
  opt->name_team = name_team;
  return opt;
}		

int		check_tab(int i, int ac, char **av)
{
  static char		str[OPT_INT][3] = { "-p", "-x", "-y", "-c", "-t"};
  int			j;
  
  j = 0;
  while (j < OPT_INT)
    {
      if (strcmp(av[i], str[j]) == 0 && i + 1 < ac)
	return j;
      j++;
    }
  return -1;
}		

void		parse_args(int ac, char **av)
{
  int                   *val;
  int			i;
  char			**name_team;
  int			nb_team;
  int			ret;
  
  val = xmalloc(sizeof(int) * OPT_INT);
  bzero(val, OPT_INT * sizeof(int));
  nb_team = 0;
  i = 1;
  while (i < ac)
    {
      if ((ret = check_tab(i, ac, av)) != -1)
	val[ret] = atoi(av[i + 1]);
      else if (strcmp(av[i], "-n") == 0 &&  i + 1 < ac)
	name_team[nb_team++] = av[i + 1];
      else
	printf("unknow parameter :%s\n", av[i]);
      i += 2;
    }
  run_server(check(val, name_team));
}

int             main(int ac, char **av)
{
  if (ac < 2)
    {
      usage();
      return 1;
    }
  parse_args(ac, av);
  return 0;
}
