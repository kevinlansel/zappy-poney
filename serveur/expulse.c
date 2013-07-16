/*
** expulse.c for  in /home/duez/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue Jun 25 14:18:23 2013 guillaume duez
** Last update Tue Jul 16 17:26:52 2013 guillaume duez
*/

#include	<stdio.h>
#include	"serveur.h"

static t_client	*get_client(t_client *client)
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

static int	check_co(t_client *client, t_client *hurt, t_map **map)
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

static void	reduc_expulse(t_client *hurt, int *indice)
{
  if (*indice == 0)
    {
      *indice = 1;
      player_expulse(hurt->id, hurt);
    }
}

static char	*create_msg_depl(t_client *hurt, t_client *client)
{
  int		size;
  char		*str;

  size = snprintf(NULL, 0, "deplacement: %d\n", calcul_K(hurt, client)) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "deplacement: %d\n", calcul_K(hurt, client));
  return (str);
}

void		expulse(t_msg *msg, t_client *client, t_map **map, t_opt *opt)
{
  t_client	*hurt;
  char		*str;
  int		indice;

  indice = 0;
  msg->time = get_time_client(client, 7);
  client = (hurt = client) ? get_client(client) : get_client(client);
  if (client && map && opt)
    {
      str = create_msg_depl(hurt, client);
      while (client && client->end != 1)
	{
	  msg->client = (msg->cmd = str) ? client : client;
	  if (client && client->type == CLIENT && check_co(client, hurt, map) == 1)
	    {
	      reduc_expulse(hurt, &indice);
	      giveposition(client, reroll(client));
	      send_mess(msg);
	    }
	  client = client->nt;
	}
    }
  msg->client = hurt;
  (!client) ? sub_food(msg, hurt, "ko\n") : sub_food(msg, hurt, "ok\n");
  client = hurt;
}
