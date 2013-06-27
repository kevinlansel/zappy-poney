/*
** init.c for  in /home/lund/Projets/zappy-poney/serveur
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Jun 26 13:00:58 2013 florian dewulf
** Last update Thu Jun 27 18:14:08 2013 florian dewulf
*/

#include	<stdio.h>
#include	<string.h>
#include	"serveur.h"

static int	check_val(int val)
{
  if (val != 0)
    return (1);
  return (0);
}

static t_opt	*check(int *val, char **name_team)
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
  return (opt);
}

static int	check_tab(int i, int ac, char **av)
{
  static char	str[OPT_INT][3] = { "-p", "-x", "-y", "-c", "-t"};
  int		j;

  j = 0;
  while (j < OPT_INT)
    {
      if (strcmp(av[i], str[j]) == 0 && i + 1 < ac)
	return (j);
      j++;
    }
  return (-1);
}

static char	**manage_team(char **team, char **av, int *off)
{
  int		count;
  int		ac;
  char		**tab;

  ac = -1;
  while (av[++ac]);
  count = 1;
  tab = team;
  while (*off + count < ac && check_tab(*off + count, ac, av) == -1)
    {
      int	nb;

      nb = 0;
      while (tab && tab[nb])
	nb++;
      if ((tab = realloc(tab, nb + 2)) != NULL)
	{
	  tab[nb] = strdup(av[*off + count]);
	  tab[nb + 1] = NULL;
	}
      count++;
    }
  *off = *off + count - 2;
  return (tab);
}

void		parse_args(int ac, char **av)
{
  int		*val;
  int		i;
  char		**name_team;
  int		ret;

  val = xmalloc(sizeof(int) * OPT_INT);
  bzero(val, OPT_INT * sizeof(int));
  name_team = NULL;
  i = 1;
  while (i < ac)
    {
      if ((ret = check_tab(i, ac, av)) != -1)
	val[ret] = atoi(av[i + 1]);
      else if (strcmp(av[i], "-n") == 0)
	name_team = manage_team(name_team, av, &i);
      else
	printf("unknow parameter :%s\n", av[i]);
      i += 2;
    }
  run_server(check(val, name_team));
}
