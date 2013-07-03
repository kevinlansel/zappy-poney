/*
** level.c for  in /home/lund/Projets/zappy-poney/serveur/dialog_client
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Tue Jun 25 21:22:00 2013 florian dewulf
** Last update Wed Jul  3 12:35:23 2013 guillaume duez
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"../serveur.h"

static char	*add_id(int id, char *str)
{
  char		*tmp;
  int		size;

  size = snprintf(NULL, 0, "%s %d", str, id);
  tmp = xmalloc((size + 1) * sizeof(char));
  snprintf(tmp, size, "%s %d", str, id);
  free(str);
  return (tmp);
}

static char	*add_enter(char *str)
{
  char		*tmp;
  int		size;

  size = snprintf(NULL, 0, "%s\n", str);
  tmp = xmalloc((size + 1) * sizeof(char));
  snprintf(tmp, size, "%s\n", str);
  free(str);
  return (tmp);
}

void		begin_incant(int level, t_client *cl, int x, int y)
{
  t_client	*tm;
  t_client	*tmp;
  int		size;
  char		*str;

  tm = cl;
  size = snprintf(NULL, 0, "pic %d %d %d %d", x, y, level, cl->id);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "pic %d %d %d %d", x, y, level, cl->id);
  while (tm->prev)
    tm = tm->prev;
  tmp = tm;
  while (tm && tm->end != 1)
    {
      str = (tm->map->x == x && tm->map->y == y) ? add_id(tm->id, str) : str;
      tm = tm->nt;
    }
  str = add_enter(str);
  while (tmp && tmp->end != 1)
    {
      if (tmp->type == 1)
	write(tmp->fd, str, strlen(str));
      tmp = tmp->nt;
    }
  free(str);
}

void		end_incant(int state, t_client *cl)
{
  t_client	*tmp;
  int		size;
  char		*str;

  tmp = cl;
  size = snprintf(NULL, 0, "pie %d %d %d", cl->map->x, cl->map->y, state);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "pie %d %d %d", cl->map->x, cl->map->y, state);
  while (tmp->prev)
    tmp = tmp->prev;
  while (tmp && tmp->end != 1)
    {
      if (tmp->type == 1)
	write(tmp->fd, str, strlen(str));
      tmp = tmp->nt;
    }
  free(str);
}
