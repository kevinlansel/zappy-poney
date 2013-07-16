/*
** cmd.c for  in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue May 28 16:48:58 2013 guillaume duez
** Last update Tue Jul 16 22:31:59 2013 florian dewulf
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
      &map[client->map->y][client->map->x - 1] :
      &map[client->map->y][client->map->x_world - 1];
  else if (type == NORD)
    {
      client->map = (client->map->y - 1) >= 0 ?
	&map[client->map->y - 1][client->map->x] :
	&map[client->map->y_world - 1][client->map->x];
    }
  client->direct = type;
  giveposition(client, reroll(client));
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
  static char	tab[7][12] = { "nourriture", " linemate", " deraumere",
			       " sibur", " mendiane", " phiras", " thystame" };
  char		*msg;
  int		len;

  (void)opt;
  (void)map;
  len = snprintf(NULL, 0, "{%s %d,%s %d,%s %d,%s %d,%s %d,%s %d,%s %d}\n",
		 tab[0], cl->ress[0] / 126, tab[1], cl->ress[1], tab[2],
		 cl->ress[2], tab[3], cl->ress[3], tab[4], cl->ress[4],
		 tab[5], cl->ress[5], tab[6], cl->ress[6]) + 1;
  msg = xmalloc((len + 1) * sizeof(char));
  snprintf(msg, len, "{%s %d,%s %d,%s %d,%s %d,%s %d,%s %d,%s %d}\n",
	   tab[0], cl->ress[0] / 126, tab[1], cl->ress[1], tab[2],
	   cl->ress[2], tab[3], cl->ress[3], tab[4], cl->ress[4],
	   tab[5], cl->ress[5], tab[6], cl->ress[6]);
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
  len = snprintf(NULL, 0, "%d\n", opt->nb_player[i]) + 1;
  str = xmalloc((len + 1) * sizeof(char));
  snprintf(str, len, "%d\n", opt->nb_player[i]);
  mess->time = get_time_client(cl, 0);
  sub_food(mess, cl, str);
}
