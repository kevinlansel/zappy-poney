/*
** client_utils.c for  in /home/duez_a//zappy/perso/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 18:19:39 2013 guillaume duez
** Last update Thu May 23 18:20:05 2013 guillaume duez
*/

#include	"serveur.h"

t_client        *client_reset(t_client *client)
{
  while (client && client->prev != NULL)
    client = client->prev;
  return client;
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
    }
  new->prev = NULL;
  return new;
}
