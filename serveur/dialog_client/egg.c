/*
** egg.c for  in /home/lund/Projets/zappy-poney/serveur/dialog_client
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Tue Jun 25 18:57:11 2013 florian dewulf
** Last update Wed Jul  3 12:55:58 2013 florian dewulf
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"../serveur.h"

void		egg_drop_by(int id_egg, int id, t_client *cl)
{
  t_client	*tmp;
  int		size;
  char		*str;

  tmp = cl;
  size = snprintf(NULL, 0, "enw %d %d %d %d\n", id_egg, id, cl->map->x, cl->map->y);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "enw %d %d %d %d\n", id_egg, id, cl->map->x, cl->map->y);
  while (tmp->prev)
    tmp = tmp->prev;
  while (tmp && tmp->end != 1)
    {
      if (tmp->type == GRAPHIC)
	write(tmp->fd, str, strlen(str));
      tmp = tmp->nt;
    }
  free(str);
}

void		egg_open(int id_egg, t_client *cl)
{
  t_client	*tmp;
  int		size;
  char		*str;

  tmp = cl;
  size = snprintf(NULL, 0, "eht %d\n", id_egg);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "eht %d\n", id_egg);
  while (tmp->prev)
    tmp = tmp->prev;
  while (tmp && tmp->end != 1)
    {
      if (tmp->type == GRAPHIC)
	write(tmp->fd, str, strlen(str));
      tmp = tmp->nt;
    }
  free(str);
}

void		egg_connect(int id_egg, t_client *cl)
{
  t_client	*tmp;
  int		size;
  char		*str;

  tmp = cl;
  size = snprintf(NULL, 0, "ebo %d\n", id_egg);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "ebo %d\n", id_egg);
  while (tmp->prev)
    tmp = tmp->prev;
  while (tmp && tmp->end != 1)
    {
      if (tmp->type == GRAPHIC)
	write(tmp->fd, str, strlen(str));
      tmp = tmp->nt;
    }
  free(str);
}

void		egg_dead(int id_egg, t_client *cl)
{
  t_client	*tmp;
  int		size;
  char		*str;

  tmp = cl;
  size = snprintf(NULL, 0, "edi %d\n", id_egg);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "edi %d\n", id_egg);
  while (tmp->prev)
    tmp = tmp->prev;
  while (tmp && tmp->end != 1)
    {
      if (tmp->type == GRAPHIC)
	write(tmp->fd, str, strlen(str));
      tmp = tmp->nt;
    }
  free(str);
}

void		egg_drop(int id_client, t_client *cl)
{
  t_client	*tmp;
  int		size;
  char		*str;

  tmp = cl;
  size = snprintf(NULL, 0, "pfk %d\n", id_client);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "pfk %d\n", id_client);
  while (tmp->prev)
    tmp = tmp->prev;
  while (tmp && tmp->end != 1)
    {
      if (tmp->type == GRAPHIC)
	write(tmp->fd, str, strlen(str));
      tmp = tmp->nt;
    }
  free(str);
}
