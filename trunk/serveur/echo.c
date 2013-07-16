/*
** echo.c for  in /home/lund/Projets/zappy-poney/serveur/tmp
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu Jun 13 17:23:39 2013 florian dewulf
** Last update Fri Jul 12 16:44:05 2013 florian dewulf
*/

#include	<math.h>
#include	"serveur.h"

void		broadcast(t_msg *msg, t_client *client, t_map **map, t_opt *o)
{
  t_client	*begin;
  int		k;
  char		*tmp;

  (void)o;
  (void)(map);
  begin = client;
  while (begin->prev != NULL)
    begin = begin->prev;
  sub_food(msg, client, "ok\n");
  msg->time = get_time() + (7 / client->time);
  while (begin && begin->end != 1)
    {
      if (begin != client && begin->type == CLIENT)
	{
	  k = calcul_K(client, begin);
	  snd_msg_broadcast(msg->comand + 9, k, begin->fd);
	}
      begin = begin->nt;
    }
  tmp = msg->comand + 9;
  if (tmp[0])
    player_message(client->id, msg->comand + 10, client);
  else
    player_message(client->id, msg->comand + 9, client);
}
