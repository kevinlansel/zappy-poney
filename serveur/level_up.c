/*
** level_up.c for  in /home/duez/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Wed Jul  3 14:39:06 2013 guillaume duez
** Last update Wed Jul  3 15:17:25 2013 guillaume duez
*/

#include	"serveur.h"

#define		LEVEL	8

int		check_nbr_client(int level, t_client *client, t_map *map)
{
  static int	player_need[LEVEL] = {1, 2, 2, 4, 4, 6, 6};
  int	i;

  i = 0;
  while (client)
    {
       if (client->type == CLIENT && client->map == map)
	 i++;
       if (player_need[level] == i)
	 return 1;
      client = client->nt;
    }
  return -1;
}

int		check_ress(int level, t_map *map, t_client *client)
{
  t_client	*tmp;
  static int	ress[LEVEL][MAX] = { { 1, 0, 0, 0, 0, 0 }, { 1, 1, 1, 0, 0, 0 },
				     { 2, 0, 1, 0, 2, 0 }, { 1, 1, 2, 0, 1, 0 },
				     { 1, 2, 1, 3, 0, 0 }, { 1, 2, 3, 0, 1, 0 },
				     { 2, 2, 2, 2, 2, 1 }};
  int		i;

  i = 0;
  tmp = client;
  client = client_reset(client);
  if (check_nbr_client(level, client, map) == 1 && level < LEVEL)
    {
      client = tmp;
      while (i < MAX)
	{
	  if (ress[level][i] > map->ress[i])
	      return -1;
	  i++;
	}
      if (i == MAX)
	return 1;
    }
  client = tmp;
  return -1;
}

void		level_up(t_msg *msg, t_client *client, t_map **map)
{
  if (map && client &&
      check_ress(client->level - 1, client->map, client) == 1)
    {
      sub_food(msg, client, "elevation en cours\n");
      msg->time = get_time_client(client, 300);
    }
  else
      sub_food(msg, client, "ko\n");
}
