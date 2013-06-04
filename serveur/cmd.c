/*
** cmd.c for  in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue May 28 16:48:58 2013 guillaume duez
** Last update Tue Jun  4 17:32:48 2013 guillaume duez
*/

#include	"serveur.h"

void		avance(t_msg *msg, t_client *client, t_map **map)
{
  e_direct	type;

  type = client->map->direct;
  sub_food(msg, client, "ok");
  msg->time = get_time() + (7 / client->time);
  if (type == SUD)
    client->map = (client->map->y + 1) < client->map->y_world ?
      &map[client->map->y + 1][client->map->x] : &map[0][client->map->x];
  else if (type == EST)
    client->map = (client->map->x + 1) < client->map->x_world ?
      &map[client->map->y][client->map->x + 1] : &map[client->map->y][0];
  else if (type == OUEST)
    client->map = (client->map->x - 1) >= 0 ? 
      &map[client->map->y][client->map->x - 1] : &map[client->map->y][client->map->x_world - 1];
  else if (type == NORD)
    {
      client->map = (client->map->y - 1) >= 0 ? 
	&map[client->map->y - 1][client->map->x] : &map[client->map->y_world - 1][client->map->x];
    }
  client->map->direct = type;
  printf("position x : %d , position y : %d\n",  client->map->x, client->map->y);
}

void		droite(t_msg *msg, t_client *client, t_map **map)
{
  if (map)
    {
      sub_food(msg, client, "ok");
      msg->time = get_time() + (7 / client->time);
      if (client->map->direct == SUD)
	client->map->direct = OUEST;
      else if (client->map->direct == OUEST)
	client->map->direct = NORD;
      else if (client->map->direct == NORD)
	client->map->direct = EST;
      else if (client->map->direct == EST)
	client->map->direct = SUD;
    }
}

void		gauche(t_msg *msg, t_client *client, t_map **map)
{
  if (map)
    {
      sub_food(msg, client, "ok");
      msg->time = get_time() + (7 / client->time);
      if (client->map->direct == SUD)
	client->map->direct = EST;
      else if (client->map->direct == EST)
	client->map->direct = NORD;
      else if (client->map->direct == NORD)
	client->map->direct = OUEST;
      else if (client->map->direct == OUEST)
	client->map->direct = SUD;
    }
}

void		inventaire(t_msg *mess, t_client *client, t_map **map)
{
  static char	tab[7][12] = { "nourriture ", ", linemate ", ", deraumere ", ", sibur ",
			       ", mendiane ", ", phiras ", ", thystame" };

  int	i;
  char	*msg;
  int	len;
  char *str;

  str = xmalloc(10);
  i = 0;
  msg = xmalloc(256);
  len = 0;
  while (i < MAX && map)
    {
      sprintf(str, "%d", (int)client->ress[i]);
      strcpy(msg + len, tab[i]);
      len += strlen(tab[i]);
      strcpy(msg + len, str);
      len += strlen(str);
      i++;
    }
  sub_food(mess, client, msg);
  printf("%s\n", msg);
}
