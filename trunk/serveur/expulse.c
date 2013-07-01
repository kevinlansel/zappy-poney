/*
** expulse.c for  in /home/duez/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue Jun 25 14:18:23 2013 guillaume duez
** Last update Mon Jul  1 15:29:31 2013 guillaume duez
*/

#include	"serveur.h"
#include	<stdio.h>

t_client	*get_client(t_client *client)
{
  t_client *hurt;

  hurt = client;
  while (client && client->prev != NULL)
    client = client->prev;
  while (client && client->end != 1)
    {
      if (client != hurt)
	return client;
      client = client->nt;
    }
  return NULL;
}

int		check_co(t_client *client, t_client *hurt, t_map **map)
{
  e_direct	type;
  int		x;
  int		y;

  type = hurt->direct;
  if (client == hurt)
    return 0;
  if (!client || !hurt || !client->map || !hurt->map)
    return 0;
  if (client->map->x != hurt->map->x || client->map->y != hurt->map->y)
    return 0;
  x = client->map->x;
  y = client->map->y;
  if (type == SUD)
    client->map = (y + 1) < client->map->y_world ? &map[y + 1][x] : &map[0][x];
  else if (type == EST)
    client->map = (x + 1) < client->map->x_world ? &map[y][x + 1] : &map[y][0];
  else if (type == OUEST)
    client->map = (x - 1) >= 0 ? &map[y][x - 1] :
      &map[y][client->map->x_world - 1];
  else if (type == NORD)
    client->map = (y - 1) >= 0 ? &map[y - 1][x] :
      &map[client->map->y_world - 1][x];
  return 1;
}

void            expulse(t_msg *msg, t_client *client, t_map **map)
{
  t_client	*hurt;
  int		size;
  char		*str;

  msg->time = get_time_client(client, 7);
  hurt = client;
  client = get_client(client);
  if (client && map)
    {
      size = snprintf(NULL, 0, "deplacement: %d\n", calcul_K(hurt, client));
      str = xmalloc(size + 1);
      snprintf(str, size + 1, "deplacement: %d\n", calcul_K(hurt, client));
      while (client && client->end != 1)
	{
	  msg->cmd = str;
	  msg->client = client;
	  if (client && client->graphic != 1 && check_co(client, hurt, map) == 1)
	    send_mess(msg);
	  client = client->nt;
	}
    }
  msg->client = hurt;
  (!client) ? sub_food(msg, hurt, "ko\n") : sub_food(msg, hurt, "ok\n");
  client = hurt;
}
