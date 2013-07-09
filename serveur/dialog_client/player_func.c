/*
** player_func.c for  in /home/lund/Projets/zappy-poney/serveur/dialog_client
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Jun 19 13:19:33 2013 florian dewulf
** Last update Tue Jul  9 13:53:22 2013 florian dewulf
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"../serveur.h"

void		connexion_player(char **arg, int fd,
				 t_map **map, t_client *begin)
{
  int		size;
  char		*str;

  (void)arg;
  (void)map;
  size = snprintf(NULL, 0, "pnw %d %d %d %d %d %s\n",
		  begin->id, begin->map->x, begin->map->y,
		  begin->direct + 1, begin->level, begin->team) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "pnw %d %d %d %d %d %s\n",
	   begin->id, begin->map->x, begin->map->y,
	   begin->direct + 1, begin->level, begin->team);
  write(fd, str, strlen(str));
  free(str);
}

void		getteam(char **arg, int fd, t_map **map, t_client *begin)
{
  char		*str;
  int		size;
  int		i;

  i = 0;
  (void)(map);
  (void)(begin);
  while (arg && arg[i])
    {
      size = snprintf(NULL, 0, "tna %s\n", arg[i]) + 1;
      str = xmalloc((size + 1) * sizeof(char));
      snprintf(str, size, "tna %s\n", arg[i]);
      write(fd, str, strlen(str));
      free(str);
      i++;
    }
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
		  id, cl->map->x, cl->map->y, cl->direct) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "ppo %d %d %d %d\n",
	   id, cl->map->x, cl->map->y, cl->direct) + 1;
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
  size = snprintf(NULL, 0, "plv %d %d\n", id, cl->level) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "plv %d %d\n", id, cl->level) + 1;
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
		  c->ress[2], c->ress[3], c->ress[4],
		  c->ress[5], c->ress[6]) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "pin %d %d %d %d %d %d %d %d %d %d\n",
	   id, c->map->x, c->map->y, c->ress[0], c->ress[1],
	   c->ress[2], c->ress[3], c->ress[4], c->ress[5], c->ress[6]);
  write(fd, str, strlen(str));
  free(str);
}
