/*
** client.c for  in /home/lund/Projets/zappy-poney/serveur
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Jul  3 11:02:42 2013 florian dewulf
** Last update Wed Jul  3 11:55:24 2013 florian dewulf
*/

#include	"serveur.h"

static t_client	*new_client(int fd, int end)
{
  t_client	*new;

  new = xmalloc(sizeof(t_client));
  new->id = give_id();
  new->fd = fd;
  new->end = end;
  return (new);
}

t_client	*create_client(int fd, t_client *client, t_opt *opt, t_map **map)
{
  t_client	*new;

  if (client == NULL)
    client = new_client(fd, 1);
  else
    {
      new = new_client(fd, 0);
      client->action = get_time();
      client->prev = new;
      new->nt = client;
      new_inventory(new);
      new->level = 1;
      new->time_eat = get_time();
      new_map(new, opt, map);
      new->time = opt->time_world;
    }
  return ((new->prev = NULL) ? new : new);
}
