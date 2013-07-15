/*
** func_bis.c for  in /home/lund/Projets/zappy-poney/serveur/dialog_client
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Tue Jul  9 14:54:23 2013 florian dewulf
** Last update Mon Jul 15 14:11:15 2013 florian dewulf
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"../serveur.h"

void		giveposition(t_client *cl, t_client *begin)
{
  int		size;
  char		*str;

  size = snprintf(NULL, 0, "ppo %d %d %d %d\n", cl->id, cl->map->x,
		  cl->map->y, cl->direct + 1) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "ppo %d %d %d %d\n", cl->id, cl->map->x,
	   cl->map->y, cl->direct + 1);
  while (begin && begin->end != 1)
    {
      if (begin->type == GRAPHIC)
	write(begin->fd, str, strlen(str));
      begin = begin->nt;
    }
  free(str);
}

void		giveinventaire(int fd, t_client *cl)
{
  int		size;
  char		*str;

  size = snprintf(NULL, 0, "pin %d %d %d %d %d %d %d %d %d %d\n",
		  cl->id, cl->map->x, cl->map->y, cl->ress[0] / 126,
		  cl->ress[1], cl->ress[2], cl->ress[3], cl->ress[4],
		  cl->ress[5], cl->ress[6]) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "pin %d %d %d %d %d %d %d %d %d %d\n",
	   cl->id, cl->map->x, cl->map->y, cl->ress[0] / 126,
	   cl->ress[1], cl->ress[2], cl->ress[3], cl->ress[4],
	   cl->ress[5], cl->ress[6]);
  write(fd, str, strlen(str));
  free(str);
}

void		givelvl(t_client *cl, t_client *begin)
{
  int		size;
  char		*str;

  size = snprintf(NULL, 0, "plv %d %d\n", cl->id, cl->level) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "plv %d %d\n", cl->id, cl->level);
  while (begin && begin->end != 1)
    {
      if (begin->type == GRAPHIC)
	write(begin->fd, str, strlen(str));
      begin = begin->nt;
    }
  free(str);
}

void		giveinvall(t_client *cl)
{
  t_client	*tmp;
  char		*str;
  int		size;

  size = snprintf(NULL, 0, "pin %d %d %d %d %d %d %d %d %d %d\n",
		  cl->id, cl->map->x, cl->map->y, cl->ress[0] / 126,
		  cl->ress[1], cl->ress[2], cl->ress[3], cl->ress[4],
		  cl->ress[5], cl->ress[6]) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "pin %d %d %d %d %d %d %d %d %d %d\n",
	   cl->id, cl->map->x, cl->map->y, cl->ress[0] / 126,
	   cl->ress[1], cl->ress[2], cl->ress[3], cl->ress[4],
	   cl->ress[5], cl->ress[6]);
  tmp = reroll(cl);
  while (tmp && tmp->end != 1)
    {
      if (tmp->type == GRAPHIC)
	write(tmp->fd, str, strlen(str));
      tmp = tmp->nt;
    }
  free(str);
}
