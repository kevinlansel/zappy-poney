/*
** player_func.c for  in /home/lund/Projets/zappy-poney/serveur/dialog_client
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Jun 19 13:19:33 2013 florian dewulf
** Last update Fri Jul  5 01:05:28 2013 florian dewulf
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"../serveur.h"

static char	**gen_team(t_client *begin)
{
  char		**team;
  t_client	*tmp;
  int		i;

  team = NULL;
  tmp = begin;
  while (tmp && tmp->end != 1)
    {
      i = 0;
      while (team && team[i] && strcmp(tmp->team, team[i]) != 0)
	i++;
      if (team == NULL || (team && team[i] == NULL))
	{
	  team = realloc(team, (strlen_tab(team) + 2) * sizeof(char *));
	  team[i] = tmp->team;
	  team[i + 1] = NULL;
	}
      tmp = tmp->nt;
    }
  return (team);
}

void		getteam(char **arg, int fd, t_map **map, t_client *begin)
{
  char		**team;
  char		*str;
  int		size;
  int		i;

  i = 0;
  (void)(arg);
  (void)(map);
  team = gen_team(begin);
  while (team && team[i])
    {
      size = snprintf(NULL, 0, "tna %s\n", team[i]);
      str = xmalloc((size + 1) * sizeof(char));
      snprintf(str, size, "tna %s\n", team[i]);
      write(fd, str, strlen(str));
      free(str);
      i++;
    }
  if (team)
    free(team);
}

void		getposplayer(char **arg, int fd, t_map **map, t_client *begin)
{
  int		id;
  t_client	*cl;
  int		size;
  char		*str;

  (void)(map);
  id = atoi(arg[0]);
  cl = begin;
  while (cl && id != cl->id)
    cl = cl->nt;
  if (cl == NULL)
    {
      write(fd, "sbp\n", 4);
      return;
    }
  size = snprintf(NULL, 0, "ppo %d %d %d %d\n",
		  id, cl->map->x, cl->map->y, cl->direct);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "ppo %d %d %d %d\n",
	   id, cl->map->x, cl->map->y, cl->direct);
  write(fd, str, strlen(str));
  free(str);
}

void		getlevelplayer(char **arg, int fd, t_map **map, t_client *begin)
{
  int		id;
  t_client	*cl;
  int		size;
  char		*str;

  (void)(map);
  id = atoi(arg[0]);
  cl = begin;
  while (cl && id != cl->id)
    cl = cl->nt;
  if (cl == NULL)
    {
      write(fd, "sbp\n", 4);
      return;
    }
  size = snprintf(NULL, 0, "plv %d %d\n", id, cl->level);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "plv %d %d\n", id, cl->level);
  write(fd, str, strlen(str));
  free(str);
}

void		getinvplayer(char **arg, int fd, t_map **map, t_client *begin)
{
  int		id;
  t_client	*c;
  int		size;
  char		*str;

  (void)(map);
  id = atoi(arg[0]);
  c = begin;
  while (c && id != c->id)
    c = c->nt;
  if (c == NULL)
    {
      write(fd, "sbp\n", 4);
      return;
    }
  size = snprintf(NULL, 0, "pin %d %d %d %d %d %d %d %d %d %d\n",
		  id, c->map->x, c->map->y, c->ress[0], c->ress[1],
		  c->ress[2], c->ress[3], c->ress[4], c->ress[5], c->ress[6]);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "pin %d %d %d %d %d %d %d %d %d %d\n",
	   id, c->map->x, c->map->y, c->ress[0], c->ress[1],
	   c->ress[2], c->ress[3], c->ress[4], c->ress[5], c->ress[6]);
  write(fd, str, strlen(str));
  free(str);
}
