/*
** client_utils.c for  in /home/duez_a//zappy/perso/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 18:19:39 2013 guillaume duez
** Last update Mon Jul  1 16:37:31 2013 florian dewulf
*/

#include	"serveur.h"

t_client        *end_client(t_client *client)
{
  if (client && client->prev == NULL && client->end != 1)
    {
      client = client->nt;
      client->prev = NULL;
      return client;
    }
  else if (client && client->prev && client->end != 1)
    {
      client = client->prev;
      client->nt = client->nt->nt;
      if (client->nt)
        client->nt->prev = client;
    }
  return client;
}

t_client        *client_reset(t_client *client)
{
  while (client && client->prev != NULL)
    client = client->prev;
  return client;
}

void		new_inventory(t_client *client)
{
  client->ress[NOURRITURE] = 1260;
  client->ress[LINEMATE] = 0;
  client->ress[DERAUMERE] = 0;
  client->ress[SIBUR] = 0;
  client->ress[MENDIANE] = 0;
  client->ress[PHIRAS] = 0;
  client->ress[THYSTAME] = 0;
}

void		new_map(t_client *client, t_opt *opt, t_map **map)
{
  int	x;
  int	y;

  x = rand() % opt->x_world;
  y = rand() % opt->y_world;
  client->map = &(map[y][x]);
  client->direct = SUD;
}

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
