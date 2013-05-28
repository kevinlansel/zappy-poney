/*
** serveur.h for h in /home/duez_a//zappy/perso/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 18:17:20 2013 guillaume duez
** Last update Mon May 27 17:20:06 2013 guillaume duez
*/

#ifndef         __SERVEUR_H__
#define         __SERVEUR_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/timeb.h>

#define	NB_FUNC	1

typedef struct  s_client
{
  int                   fd;
  char                  nick[128];
  char                  chanel[128];
  int                   end;
  void                  *id;
  struct s_client       *nt;
  struct s_client       *prev;
}               t_client;

typedef struct	s_msg
{
  char	cmd[1024];
  char	name[128];
  int	id;
}		t_msg;

typedef	struct	s_task
{
  struct timeb	time;
  struct s_task	*next;
  struct s_task	*prev;
}		t_task;

void            *xmalloc(size_t size);
void		xlisten(int fd);
int		xsocket(struct protoent *pe);
int		xaccept(int fd, struct sockaddr_in s_in, socklen_t s_in_size);
void		xbind(int fd, struct sockaddr_in s_in);
t_client	*create_client(int fd, t_client *client);
t_client	*client_reset(t_client *client);
t_msg          *get_mess(t_client *client);
t_client        *end_client(t_client *client);
void		do_action(t_client *client);
#endif
