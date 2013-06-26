/*
** player_action.c for  in /home/lund/Projets/zappy-poney/serveur/dialog_client
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Tue Jun 25 16:57:52 2013 florian dewulf
** Last update Wed Jun 26 10:59:51 2013 florian dewulf
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"../serveur.h"

void		player_expulse(int id, t_client *cl)
{
  t_client	*tmp;
  int		size;
  char		*str;

  tmp = cl;
  size = snprintf(NULL, 0, "pex %d\n", id);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "pex %d\n", id);
  while (tmp->prev)
    tmp = tmp->prev;
  while (tmp && tmp->end != 1)
    {
      if (tmp->graphic == 1)
	write(tmp->fd, str, strlen(str));
      tmp = tmp->nt;
    }
  free(str);
}

void		player_message(int id, char *str, t_client *cl)
{
  t_client	*tmp;
  int		size;
  char		*string;

  tmp = cl;
  size = snprintf(NULL, 0, "pbc %d %s\n", id, str);
  string = xmalloc((size + 1) * sizeof(char));
  snprintf(string, size, "pbc %d %s\n", id, str);
  while (tmp->prev)
    tmp = tmp->prev;
  while (tmp && tmp->end != 1)
    {
      if (tmp->graphic == 1)
	write(tmp->fd, string, strlen(string));
      tmp = tmp->nt;
    }
  free(str);
}

void		player_dead(int id, t_client *cl)
{
  t_client	*tmp;
  int		size;
  char		*str;

  tmp = cl;
  size = snprintf(NULL, 0, "pdi %d\n", id);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "pdi %d\n", id);
  while (tmp->prev)
    tmp = tmp->prev;
  while (tmp && tmp->end != 1)
    {
      if (tmp->graphic == 1)
	write(tmp->fd, str, strlen(str));
      tmp = tmp->nt;
    }
  free(str);
}
