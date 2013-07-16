/*
** client.c for  in /home/lund/Projets/zappy-poney/serveur
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Jul  3 11:02:42 2013 florian dewulf
** Last update Thu Jul  4 23:27:31 2013 florian dewulf
*/

#include	<unistd.h>
#include	"serveur.h"

static t_client	*new_client(int fd, int end)
{
  t_client	*new;

  new = xmalloc(sizeof(t_client));
  new->id = give_id();
  new->fd = fd;
  new->end = end;
  new->type = WAIT_CO;
  return (new);
}

t_client	*create_cl(int fd, t_client *client, t_opt *opt, t_map **map)
{
  t_client	*new;

  if (client == NULL)
    {
      client = new_client(fd, 1);
      new = client;
    }
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
      write(fd, "BIENVENUE\n", 10);
    }
  return ((new->prev = NULL) ? new : new);
}

t_client	*delete_client(t_client *to_del)
{
  t_client	*prev;
  t_client	*next;

  prev = to_del->prev;
  next = to_del->nt;
  if (prev)
    prev->nt = next;
  if (next)
    next->prev = prev;
  free(to_del->team);
  free(to_del);
  if (prev)
    return (prev);
  else
    return (next);
}
