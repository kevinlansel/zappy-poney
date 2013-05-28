/*
** serveur.h for h in /home/duez_a//zappy/perso/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 18:17:20 2013 guillaume duez
** Last update Tue May 28 20:19:54 2013 guillaume duez
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

#define	NB_FUNC		9
#define	LEN		20
#define	OPT_INT		5

typedef enum	e_direct
  {
    NORD,
    EST,
    OUEST,
    SUD
  }		e_direct;

typedef	struct	s_inventory
{
  int		food;
  int		linemate;
  int		deraumere;
  int		sibur;
  int		mendiane;
  int		phiras;
  int		thystame;
}		t_inventory;

typedef	struct	s_pos
{
  int		x;
  int		y;
  e_direct	pos;
}		t_pos;

typedef struct  s_client
{
  int                   fd;
  char                  *nick;
  int                   end;
  void                  *id;
  t_inventory		*inventory;
  t_pos			*pos;
  struct s_client       *nt;
  struct s_client       *prev;
}               t_client;

typedef struct	s_msg
{
  char		*cmd;
  t_client	*client;
}		t_msg;

typedef	struct	s_task
{
  char		*ret;
  float		time;
  int		fd;
  struct s_task	*next;
  struct s_task	*prev;
}		t_task;

typedef	struct	s_opt
{
  int		port;
  int		x_world;
  int		y_world;
  int		nb_player;
  int		time_world;
  char		**name_team;
}		t_opt;

typedef	struct	s_map
{
  int		x;
  int		y;
}		t_map;

typedef	struct s_connect
{
  struct protoent       *pe;
  struct sockaddr_in    s_in;
  struct sockaddr_in    s_in_client;
  socklen_t             s_in_size;
  int			fd;
  int			port;
}		t_connect;


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
void            run_server(t_opt *opt);

#endif
