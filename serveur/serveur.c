/*
** serveur.c for  in /home/duez_a//zappy/perso/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 17:52:10 2013 guillaume duez
** Last update Mon May 27 16:43:02 2013 guillaume duez
*/

#include	"serveur.h"

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

static void		open_serv(int fd,  socklen_t s_in_s,
				  struct sockaddr_in s_in_c, t_client *client)
{
  int		error;
  fd_set        fd_read;
  int		max;
  
  error = 0;
  while (error != -1)
    {
      set_fd(&fd_read, client, &max, fd);
      if ((error = select(max + 1, &fd_read, NULL, NULL, NULL)) != -1)
        {
          if (FD_ISSET(fd, &fd_read))
	    client = create_client(xaccept(fd, s_in_c, s_in_s), client);
          while (client && client->end != 1)
            {
              if (FD_ISSET(client->fd, &fd_read))
		do_action(client);
              if (client->end != 1)
                client = client->nt;
            }
        }
      client = client_reset(client);
    }
}

static void		run_server(int port)
{
  struct protoent       *pe;
  struct sockaddr_in    s_in;
  struct sockaddr_in    s_in_client;
  int                   fd;
  socklen_t             s_in_size;
  t_client      *client;

  s_in_size = sizeof(s_in_client);
  pe = getprotobyname("TCP");
  if (!pe)
    return;
  fd = xsocket(pe);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  xbind(fd, s_in);
  xlisten(fd);
  client = create_client(0, NULL);
  open_serv(fd, s_in_size, s_in_client, client);
  close(fd);
}

int		main(int ac, char **av)
{
  int                   port;

  if (ac != 2)
    return 1;
  port = atoi(av[1]);
  run_server(port);
  return 0;
}
