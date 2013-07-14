/*
** take_let.c for  in /home/duez/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon Jun 24 16:01:55 2013 guillaume duez
** Last update Sun Jul 14 14:42:19 2013 florian dewulf
*/

#include	<stdio.h>
#include	<string.h>
#include	"serveur.h"

int		strlen_tab(char **str)
{
  int		i;

  i = 0;
  while (str && str[i])
    i++;
  return i;
}

void		pose_objet(t_msg *msg, t_client *client, t_map **map, t_opt *o)
{
  char		**tab_cmd;
  int		i;
  static char	tab[7][12] = { "nourriture", "linemate", "deraumere", "sibur",
			       "mendiane", "phiras", "thystame" };

  (void)o;
  i = -1;
  msg->time = get_time_client(client, 7);
  tab_cmd = my_str_to_wordtab(msg->comand, ' ');
  if (strlen_tab(tab_cmd) != 3 || !map)
    return;
  while (++i < MAX)
    if (strcmp(tab[i], tab_cmd[2]) == 0 && client->ress[i] > 0)
      {
	client->ress[i] -= (i > 0 ? 1 : 126);
	client->map->ress[i] += 1;
	printf("let : %s\n", tab[i]);
	drop_ress(client->id, i, client);
	sub_food(msg, client, "ok\n");
	drop_ress(client->id, i, client);
	return;
      }
  sub_food(msg, client, "ko\n");
}

void		prend_objet(t_msg *msg, t_client *cl, t_map **map, t_opt *o)
{
  char		**tab_cmd;
  int		i;
  static char	tab[7][12] = { "nourriture", "linemate", "deraumere", "sibur",
			       "mendiane", "phiras", "thystame" };

  (void)o;
  map = (void *)map;
  i = -1;
  msg->time = get_time_client(cl, 7);
  tab_cmd = my_str_to_wordtab(msg->comand, ' ');
  while (strlen_tab(tab_cmd) == 2 && ++i < MAX)
    if (strcmp(tab[i], tab_cmd[1]) == 0 && cl->map->ress[i] > 0)
      {
	cl->map->ress[i] -= 1;
	cl->ress[i] += (i > 0 ? 1 : 126);
	take_ress(cl->id, i, cl);
	sub_food(msg, cl, "ok\n");
	printf("add : %s\n", tab[i]);
	take_ress(cl->id, i, cl);
	return;
      }
  sub_food(msg, cl, "ko\n");
}
