/*
** fork.c for  in /home/duez/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon Jul  8 15:37:27 2013 guillaume duez
** Last update Mon Jul  8 16:12:07 2013 guillaume duez
*/

#include	"serveur.h"

int		give_id_egg()
{
  static int    ret = -1;

  ret++;
  return (ret);
}

void		fork_egg(t_msg *msg, t_client *client, t_map **map)
{
  t_client      *new;

  (void) map;
  sub_food(msg, client, "ok\n");
  msg->time = get_time_client(client, 42);
  new = xmalloc(sizeof(t_client));
  new->id = give_id_egg();
  new->fd = client->id;
  new->end = 0;
  new->nt = client->nt;
  new->type = EGG;
  client->nt = new;
}
