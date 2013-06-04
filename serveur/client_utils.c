/*
** client_utils.c for  in /home/duez_a//zappy/perso/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 18:19:39 2013 guillaume duez
** Last update Tue Jun  4 15:07:32 2013 guillaume duez
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

void	new_inventory(t_client *client)
{
  client->ress[NOURRITURE] = 1260;
  client->ress[LINEMATE] = 0;
  client->ress[DERAUMERE] = 0;
  client->ress[SIBUR] = 0;
  client->ress[MENDIANE] = 0;
  client->ress[PHIRAS] = 0;
  client->ress[THYSTAME] = 0;
}

void		new_map(t_client *client, t_opt *opt)
{
  client->ress[NOURRITURE] = 1260;
  client->ress[LINEMATE] = 0;
  client->ress[DERAUMERE] = 0;
  client->ress[SIBUR] = 0;
  client->ress[MENDIANE] = 0;
  client->ress[PHIRAS] = 0;
  client->ress[THYSTAME] = 0;
  client->map = xmalloc(sizeof(t_map));
  client->map->direct = SUD;
  client->map->x = rand() % opt->x_world;
  client->map->y = rand() % opt->y_world;
  client->map->x_world = opt->x_world;
  client->map->y_world = opt->y_world;
}

t_client        *create_client(int fd, t_client *client, t_opt *opt)
{
  t_client      *new;

  new = xmalloc(sizeof(t_client));
  if (client == NULL)
    {
      client = new;
      client->id = (void *)client;
      client->end = 1;
      client->nt = NULL;
    }
  else
    {
      new->fd = fd;
      client->prev = new;
      new->end = 0;
      new->id = (void *)new;
      new->nt = client;
      new_inventory(new);
      new->level = 1;
      new->time_eat = get_time();
      if (opt != NULL)
	{
	  printf("Opt is not null, time :%d\n", opt->time_world);
	  new_map(new, opt);
	  new->time = opt->time_world;
	}
    }
  new->prev = NULL;
  return new;
}
