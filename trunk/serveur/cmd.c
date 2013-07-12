/*
** cmd.c for  in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue May 28 16:48:58 2013 guillaume duez
** Last update Fri Jul 12 17:11:42 2013 florian dewulf
*/

#include	<stdio.h>
#include	<string.h>
#include	"serveur.h"

void		avance(t_msg *msg, t_client *client, t_map **map, t_opt *opt)
{
  e_direct	type;

  (void)opt;
  type = client->direct;
  sub_food(msg, client, "ok\n");
  msg->time = get_time_client(client, 7);
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
  client->direct = type;
  giveposition(client, reroll(client));
  printf("position x : %d , position y : %d\n",  client->map->x, client->map->y);
}

void		droite(t_msg *msg, t_client *client, t_map **map, t_opt *opt)
{
  (void)opt;
  if (map)
    {
      sub_food(msg, client, "ok\n");
      msg->time = get_time_client(client, 7);
      if (client->direct == SUD)
	client->direct = OUEST;
      else if (client->direct == OUEST)
	client->direct = NORD;
      else if (client->direct == NORD)
	client->direct = EST;
      else if (client->direct == EST)
	client->direct = SUD;
      giveposition(client, reroll(client));
    }
}

void		gauche(t_msg *msg, t_client *client, t_map **map, t_opt *opt)
{
  (void)opt;
  if (map)
    {
      sub_food(msg, client, "ok\n");
      msg->time = get_time_client(client, 7);
      if (client->direct == SUD)
	client->direct = EST;
      else if (client->direct == EST)
	client->direct = NORD;
      else if (client->direct == NORD)
	client->direct = OUEST;
      else if (client->direct == OUEST)
	client->direct = SUD;
      giveposition(client, reroll(client));
    }
}

void		inventaire(t_msg *mess, t_client *cl, t_map **map, t_opt *opt)
{
  static char	tab[7][12] = { "nourriture ", ", linemate ", ", deraumere ", ", sibur ",
			       ", mendiane ", ", phiras ", ", thystame" };
  int		i;
  char		*msg;
  int		len;
  char		*str;

  (void)opt;
  str = xmalloc(10);
  i = 0;
  msg = xmalloc(256);
  len = 0;
  while (i < MAX && map)
    {
      sprintf(str, "%d", (int)cl->ress[i]);
      strcpy(msg + len, tab[i]);
      len += strlen(tab[i]);
      strcpy(msg + len, str);
      len += strlen(str);
      i++;
    }
  mess->time = get_time_client(cl, 7);
  sub_food(mess, cl, msg);
}

void		connecnb(t_msg *mess, t_client *cl, t_map **map, t_opt *opt)
{
  int		len;
  int		i;
  char		*str;

  (void)map;
  i = 0;
  while (opt && opt->name_team && opt->name_team[i] &&
	 strcmp(opt->name_team[i], cl->team) != 0)
    i++;
  len = snprintf(NULL, 0, "%d", opt->nb_player[i]) + 1;
  str = xmalloc((len + 1) * sizeof(char));
  snprintf(str, len, "%d", opt->nb_player[i]);
  mess->time = get_time_client(cl, 0);
  sub_food(mess, cl, str);
}
