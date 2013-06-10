/*
** serveur.c for  in /home/duez_a//zappy/perso/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 17:52:10 2013 guillaume duez
** Last update Mon Jun 10 17:26:13 2013 florian dewulf
*/

#include	"serveur.h"


//creation de chaque case de la map || creation de ressource aléatoire a faire
static void		create_case(t_map *map, int x, int y, t_opt *opt)
{
  map->ress[NOURRITURE] = 0;
  map->ress[LINEMATE] = 0;
  map->ress[DERAUMERE] = 0;
  map->ress[SIBUR] = 0;
  map->ress[MENDIANE] = 0;
  map->ress[PHIRAS] = 0;
  map->ress[THYSTAME] = 0;
  map->x = x;
  map->y = y;
  map->x_world = opt->x_world;
  map->y_world = opt->y_world;
}

//creation de la map
static t_map		**create_map(t_opt *opt)
{
  t_map	**map;
  int	y;
  int	x;

  y = 0;
  map = xmalloc(sizeof(t_map *) * opt->y_world);
  while (y < opt->y_world)
    {
      x = 0;
      map[y] = xmalloc(sizeof(t_map) * opt->x_world);
      while (x < opt->x_world)
	{
	  create_case(&map[y][x], x, y, opt);
	  x++;
	}
      y++;
    }
  return map;
}

static void     set_fd(fd_set *listen_select,
                       t_client *client, int *max, int fd)
{
  FD_ZERO(listen_select);
  FD_SET(fd, listen_select);
  *max = fd;
  while (client && client->end != 1)
    {
      FD_SET(client->fd, listen_select);
      if (client->fd > *max)
        *max = client->fd;
      client = client->nt;
    }
  client = client_reset(client);
}

// boucle select
static void		open_serv(t_connect *co, t_client *client, t_opt *opt, t_map **map)
{
  int		error;
  fd_set        fd_read;
  int		max;
  t_msg		*msg;

  error = 0;
  msg = NULL;
  while (error != -1)
    {
      set_fd(&fd_read, client, &max, co->fd);
      if ((error = select(max + 1, &fd_read, NULL, NULL, NULL)) != -1)
        {
          if (FD_ISSET(co->fd, &fd_read))
	    client = create_client(xaccept(co->fd, co->s_in_client,
					   co->s_in_size), client, opt);
          while (client && client->end != 1)
            {
              if (FD_ISSET(client->fd, &fd_read))
		msg = do_action(client, map, msg);
              if (client->end != 1)
                client = client->nt;
            }
        }
      msg = exec_task(msg);
      client = client_reset(client);
    }
}

void		run_server(t_opt *opt)
{
  t_connect	*connect;
  t_client      *client;
  t_map		**map;

  connect = xmalloc(sizeof(t_connect));
  connect->s_in_size = sizeof(connect->s_in_client);
  connect->pe = getprotobyname("TCP");
  if (!connect->pe)
    return;
  connect->fd = xsocket(connect->pe);
  connect->s_in.sin_family = AF_INET;
  connect->s_in.sin_port = htons(opt->port);
  connect->s_in.sin_addr.s_addr = INADDR_ANY;
  xbind(connect->fd, connect->s_in);
  xlisten(connect->fd);
  client = create_client(0, NULL, NULL);
  map = create_map(opt);
  create_link_x(map);
  create_link_y(map);
  open_serv(connect, client, opt, map);
  close(connect->fd);
}
