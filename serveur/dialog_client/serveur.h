/*
** serveur.h for  in /home/lund/Projets/zappy-poney/serveur/dialog_client
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Jun 17 16:48:18 2013 florian dewulf
** Last update Wed Jun 19 11:54:15 2013 florian dewulf
*/

#ifndef		SERVEUR_H__
# define	SERVEUR_H__

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



/*
** NE RECOPIER QUE CE QUI EST CI DESSUS
*/

#define		SIZE_PROTOCOL	9
/*
** - - - - - - - - - - - - - - - - - - - - - - - - - -
** nb_arg is the number of arguments waiting
** func takes 4 params
** Number one is the arguments behind the cmd
** Number two is the file descriptor to send the answer
** Number three is a pointer on the t_map list
** Number four is a pointer on the t_client list
** - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

typedef struct	s_protocol
{
  char		*cmd;
  int		nb_arg;
  void		(*func)(char **, int, t_map **, t_client *);
}		t_protocol;



#endif
