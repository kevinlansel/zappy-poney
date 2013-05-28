/*
** client_utils.c for  in /home/duez_a//zappy/perso/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 18:19:39 2013 guillaume duez
** Last update Tue May 28 17:55:10 2013 guillaume duez
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

t_inventory	*new_inventory()
{
  t_inventory *in;
  
  in = xmalloc(sizeof(t_inventory));
  in->food = 1260;
  in->linemate = 0;
  in->deraumere = 0;
  in->sibur = 0;
  in->mendiane = 0;
  in->phiras = 0;
  in->thystame = 0;
  return in;
}

t_pos		*new_pos(t_map *map)
{
  t_pos		*pos;
  
  pos = xmalloc(sizeof(t_pos));
  pos->pos = SUD;
  pos->x = rand() % map->x;
  pos->y = rand() % map->y;
  return pos;
}

t_client        *create_client(int fd, t_client *client)
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
      new->inventory = new_inventory();
    }
  new->prev = NULL;
  return new;
}
