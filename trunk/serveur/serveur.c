/*
** serveur.c for  in /home/duez_a//zappy/perso/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 17:52:10 2013 guillaume duez
** Last update Tue May 28 20:18:53 2013 guillaume duez
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

static void		open_serv(t_connect *co, t_client *client, t_opt *opt)
{
  int		error;
  fd_set        fd_read;
  int		max;

  error = 0;
  while (error != -1)
    {
      set_fd(&fd_read, client, &max, co->fd);
      if ((error = select(max + 1, &fd_read, NULL, NULL, NULL)) != -1)
        {
          if (FD_ISSET(co->fd, &fd_read))
	    client = create_client(xaccept(co->fd, co->s_in_client,
					   co->s_in_size), client);
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

void		run_server(t_opt *opt)
{
  t_connect	*connect;
  t_client      *client;

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
  client = create_client(0, NULL);
  open_serv(connect, client, opt);
  close(connect->fd);
}
