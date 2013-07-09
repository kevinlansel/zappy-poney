/*
** level_up.c for  in /home/duez/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Wed Jul  3 14:39:06 2013 guillaume duez
** Last update Tue Jul  9 16:14:31 2013 florian dewulf
*/

#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"serveur.h"

#define		LVL	8

char		*get_mess_level_up(int level)
{
  int		size;
  char		*str;

  size = snprintf(NULL, 0, "niveau actuel : %d\n", level) + 1;
  str = xmalloc(size);
  snprintf(str, size, "niveau actuel : %d\n", level);
  return str;
}

int		check_nbr_client(int level, t_client *client, t_map *map, int opt)
{
  static int	player_need[LVL] = {1, 2, 2, 4, 4, 6, 6};
  int		i;

  i = 0;
  while (client)
    {
       if (client->type == CLIENT && client->map == map
	   && client->level - 1 == level)
	 i++;
      client = client->nt;
    }
  client = client_reset(client);
  while (player_need[level] == i && opt == 1 && client)
    {
        if (client->type == CLIENT && client->map == map
	    && client->level - 1 == level)
	  {
	    client->level++;
	    send_mess(create_mess(client, get_mess_level_up(client->level)));
	  }
      client = client->nt;
    }
  if (player_need[level] == i)
    return 1;
  return -1;
}

int		check_ress(int level, t_map *map, t_client *client)
{
  t_client	*tmp;
  static int	ress[LVL][MAX] = { { 1, 0, 0, 0, 0, 0 }, { 1, 1, 1, 0, 0, 0 },
				   { 2, 0, 1, 0, 2, 0 }, { 1, 1, 2, 0, 1, 0 },
				   { 1, 2, 1, 3, 0, 0 }, { 1, 2, 3, 0, 1, 0 },
				   { 2, 2, 2, 2, 2, 1 }};
  int		i;

  i = -1;
  tmp = client;
  if (check_nbr_client(level, client_reset(client), map, 0) == 1)
    {
      while (level < LVL && ++i < MAX)
	if (map->ress[i] < ress[level][i])
	  i = MAX;
    }
  if (i == MAX)
    {
      i = -1;
      while (++i < MAX)
	map->ress[i] -= ress[level][i];
    }
  client = tmp;
  return (i == MAX ? 1 : -1);
}

void		level_up(t_msg *msg, t_client *client, t_map **map)
{
  if (map && client &&
      check_ress(client->level - 1, client->map, client) == 1)
    {
      sub_food(msg, client, "elevation en cours\n");
      send_mess(msg);
      msg->time = get_time_client(client, 300);
      begin_incant(client->level, client, client->map->x, client->map->y);
    }
  else
      sub_food(msg, client, "ko\n");
}

int		up_level(t_msg *msg)
{
  t_client	*client;

  client = msg->client;
  if (msg && msg->client)
    {
      if (check_ress(msg->client->level - 1, msg->client->map, msg->client) == 1)
	{
	  msg->client = client_reset(msg->client);
	  check_nbr_client(msg->client->level, msg->client, msg->client->map, 1);
	  msg->client = client;
	  end_incant(1, client);
	  return 1;
	}
    }
  end_incant(0, client);
  return -1;
}

