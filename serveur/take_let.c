/*
** take_let.c for  in /home/duez/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon Jun 24 16:01:55 2013 guillaume duez
** Last update Tue Jul  9 15:32:55 2013 florian dewulf
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

void		pose_objet(t_msg *msg, t_client *client, t_map **map)
{
  char		**tab_cmd;
  int		i;
  static char	tab[7][12] = { "nourriture", "linemate", "deraumere", "sibur",
			       "mendiane", "phiras", "thystame" };

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

void		prend_objet(t_msg *msg, t_client *client, t_map **map)
{
  char		**tab_cmd;
  int		i;
  static char	tab[7][12] = { "nourriture", "linemate", "deraumere", "sibur",
			       "mendiane", "phiras", "thystame" };

  map = (void *)map;
  printf("call func prend_objet\n");
  i = -1;
  msg->time = get_time_client(client, 7);
  tab_cmd = my_str_to_wordtab(msg->comand, ' ');
  if (strlen_tab(tab_cmd) != 3)
    return;
  while (++i < MAX)
    if (strcmp(tab[i], tab_cmd[2]) == 0 && client->map->ress[i] > 0)
      {
	client->map->ress[i] -= 1;
	client->ress[i] += (i > 0 ? 1 : 126);
	take_ress(client->id, i, client);
	sub_food(msg, client, "ok\n");
	printf("add : %s\n", tab[i]);
	take_ress(client->id, i, client);
	return;
      }
  sub_food(msg, client, "ko\n");
}
