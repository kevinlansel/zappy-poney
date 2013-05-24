/*
** serveur.h for h in /home/duez_a//zappy/perso/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 18:17:20 2013 guillaume duez
** Last update Thu May 23 18:50:41 2013 guillaume duez
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

void            *xmalloc(size_t size);
void		xlisten(int fd);
int		xsocket(struct protoent *pe);
int		xaccept(int fd, struct sockaddr_in s_in, socklen_t s_in_size);
void		xbind(int fd, struct sockaddr_in s_in);
t_client	*create_client(int fd, t_client *client);
t_client	*client_reset(t_client *client);

#endif
