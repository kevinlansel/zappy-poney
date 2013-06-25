/*
** echo.c for  in /home/lund/Projets/zappy-poney/serveur/tmp
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu Jun 13 17:23:39 2013 florian dewulf
** Last update Tue Jun 25 14:54:33 2013 florian dewulf
*/

#include	<math.h>
#include	"serveur.h"

void		broadcast(t_msg *msg, t_client *client, t_map **map)
{
  t_client	*begin;
  int		k;

  (void)(map);
  begin = client;
  while (begin->prev != NULL)
    begin = begin->prev;
  sub_food(msg, client, "ok\n");
  msg->time = get_time() + (7 / client->time);
  while (begin && begin->end != 1)
    {
      if (begin != client && begin->graphic != 1)
	{
	  k = calcul_K(client, begin);
	  snd_msg_broadcast(msg->comand + 9, k, begin->fd);
	}
      begin = begin->nt;
    }
}
