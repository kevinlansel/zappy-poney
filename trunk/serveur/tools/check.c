/*
** check.c for  in /home/lund/Projets/zappy-poney/serveur
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Fri Jul 12 11:05:03 2013 florian dewulf
** Last update Tue Jul 16 18:50:50 2013 guillaume duez
*/

#include	<string.h>
#include	<unistd.h>
#include	"../serveur.h"

int		check_endgame(t_client *client)
{
  char		*str;
  t_client	*tmp;
  int		i;

  i = 0;
  str = NULL;
  tmp = reroll(client);
  while (tmp && tmp->end != 1)
    {
      if (str == NULL && tmp->type == CLIENT)
	i += (str = tmp->team) ? 1 : 1;
      if (tmp->type == CLIENT && str && strcmp(str, tmp->team) != 0)
	i++;
      tmp = tmp->nt;
    }
  if (i == 1 || i == 0)
    {
      if (i == 0)
	end_game(client, "Nobody");
      else
	end_game(client, str);
      return (1);
    }
  return (0);
}

void		epur_client(t_client **client)
{
  t_client	*cl;

  cl = reroll(*client);
  while (cl && cl->end != 1)
    {
      if (cl->type == TO_DEL)
	{
	  close(cl->fd);
	  cl = delete_client(cl);
	}
      else
	cl = cl->nt;
    }
  reroll(cl);
  *client = cl;
}
