/*
** serveur.h for h in /home/duez_a//zappy/perso/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 18:17:20 2013 guillaume duez
** Last update Thu Jun 20 20:24:19 2013 guillaume duez
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

#define	NB_FUNC		8
#define	LEN		12
#define	OPT_INT		5
#define	SIZE_PTR_FUNC	14

typedef enum	e_direct
  {
    NORD,
    EST,
    OUEST,
    SUD
  }		e_direct;

typedef enum	e_ressource
  {
    NOURRITURE,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    MAX
  }		e_object;

typedef struct	s_conf
{
  int		time_repop[MAX];
  int		max_repop[MAX];
}		t_conf;

typedef struct	s_ptr_func_parse
{
  char		*str;
  int		off;
}		t_ptr_func_parse;

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
  int		x_world;
  int		y_world;
  int		ress[MAX];
  e_direct	direct;
  struct s_map	*left;
  struct s_map	*right;
  struct s_map	*down;
  struct s_map	*up;
}		t_map;

typedef struct  s_client
{
  int                   fd;
  char                  *nick;
  int                   end;
  void                  *id;
  double		ress[MAX];
  t_map			*map;
  int			time;
  int			level;
  double	       	time_eat;
  struct s_client       *nt;
  struct s_client       *prev;
}               t_client;

typedef	struct s_connect
{
  struct protoent       *pe;
  struct sockaddr_in    s_in;
  struct sockaddr_in    s_in_client;
  socklen_t             s_in_size;
  int			fd;
  int			port;
}		t_connect;

typedef struct	s_msg
{
  char		*cmd;
  double	time;
  t_client	*client;
  int		end;
  struct s_msg	*nt;
  struct s_msg	*prev;
}		t_msg;


void            avance(t_msg *msg, t_client *client, t_map **map);

t_client	*create_client(int fd, t_client *client, t_opt *opt, t_map **map);
void            create_link_x(t_map **map);
void            create_link_y(t_map **map);
t_client	*client_reset(t_client *client);

t_client        *end_client(t_client *client);
t_msg           *exec_task(t_msg *task);

t_msg		*do_action(t_client *client, t_map **map, t_msg *msg);
void            droite(t_msg *msg, t_client *client, t_map **map);

void            gauche(t_msg *msg, t_client *client, t_map **map);
t_msg           *get_mess(t_client *client);
double          get_time();

void            inventaire(t_msg *mess, t_client *client, t_map **map);
void            voir(t_msg *mess, t_client *client, t_map **map);
t_msg           *into_order_task(t_msg *first, t_msg *new);

void            run_server(t_opt *opt);
t_msg           *remove_msg(t_msg *msg, t_client *client);

int             send_mess(t_msg *msg);
void            sub_food(t_msg *msg, t_client *client, const char *str);

void            *xmalloc(size_t size);
void		xlisten(int fd);
int		xsocket(struct protoent *pe);
int		xaccept(int fd, struct sockaddr_in s_in, socklen_t s_in_size);
void		xbind(int fd, struct sockaddr_in s_in);


#endif
