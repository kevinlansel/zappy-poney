/*
** player_ress.c for  in /home/lund/Projets/zappy-poney/serveur/dialog_client
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Tue Jun 25 14:30:32 2013 florian dewulf
** Last update Tue Jul  9 13:53:43 2013 florian dewulf
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"../serveur.h"

void		drop_ress(int id, int ressource, t_client *cl)
{
  t_client	*tmp;
  char		*str;
  int		size;

  tmp = cl;
  size = snprintf(NULL, 0, "pdr %d %d\n", id, ressource) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "pdr %d %d\n", id, ressource);
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

void		take_ress(int id, int ressource, t_client *cl)
{
  t_client	*tmp;
  char		*str;
  int		size;

  tmp = cl;
  size = snprintf(NULL, 0, "pgt %d %d\n", id, ressource) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "pgt %d %d\n", id, ressource);
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
