/*
** serveur.h for h in /home/duez_a//zappy/perso/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 18:17:20 2013 guillaume duez
** Last update Fri Jul  5 14:42:33 2013 florian dewulf
*/

#ifndef			__SERVEUR_H__
# define		__SERVEUR_H__

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netdb.h>
#include		<stdlib.h>
#include		<arpa/inet.h>
#include		<netinet/in.h>
#include		<limits.h>

#define			NB_FUNC		10
#define			LEN		12
#define			OPT_INT		5
#define			SIZE_PTR_FUNC	14
#define			SIZE_PROTOCOL	9

typedef enum		e_direct
  {
    NORD,
    EST,
    OUEST,
    SUD
  }			e_direct;

typedef enum		e_ressource
  {
    NOURRITURE,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    MAX
  }			e_object;

typedef enum		e_co
  {
    CLIENT,
    GRAPHIC,
    WAIT_CO,
    EGG
  }			e_type_co;

typedef struct		s_conf
{
  int			time_repop[MAX];
  int			max_repop[MAX];
}			t_conf;

typedef struct		s_ptr_func_parse
{
  char			*str;
  int			off;
}			t_ptr_func_parse;

typedef	struct		s_task
{
  char			*ret;
  float			time;
  int			fd;
  struct s_task		*next;
  struct s_task		*prev;
}			t_task;

typedef	struct		s_opt
{
  int			port;
  int			x_world;
  int			y_world;
  int			*nb_player;
  int			time_world;
  char			**name_team;
}			t_opt;

typedef	struct		s_map
{
  int			x;
  int			y;
  int			x_world;
  int			y_world;
  int			ress[MAX];
  struct s_map		*left;
  struct s_map		*right;
  struct s_map		*down;
  struct s_map		*up;
}			t_map;

typedef struct		s_client
{
  char			type;
  int			fd;
  int			end;
  int			id;
  char			*team;
  int			ress[MAX];
  t_map			*map;
  int			time;
  int			level;
  double		action;
  double		time_eat;
  e_direct		direct;
  struct s_client	*nt;
  struct s_client	*prev;
}			t_client;

typedef	struct		s_connect
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  struct timeval        *tv;
  int			fd;
  int			port;
}			t_connect;

typedef struct		s_msg
{
  char			*cmd;
  char			*comand;
  char			bool;
  double		time;
  t_client		*client;
  int			end;
  struct s_msg		*nt;
  struct s_msg		*prev;
}			t_msg;

typedef struct		s_angle
{
  int			borne[2];
  char			pond;
  struct s_angle	*next;
}			t_angle;

typedef struct		s_protocol
{
  char			*cmd;
  int			nb_arg;
  void			(*func)(char **, int, t_map **, t_client *);
}			t_protocol;

void			avance(t_msg *msg, t_client *client, t_map **map);

void			begin_incant(int, t_client *, int, int);
void			broadcast(t_msg *, t_client *, t_map **);

int			calcul_K(t_client *, t_client *);
int			cmp_nb_arg(int, char *, int);
void			connec_egg(int, t_client *);
void			connexion(t_client **, t_map **, t_opt *);
void			connexion_player(char **, int, t_map **, t_client *);
t_client		*create_cl(int, t_client *, t_opt *, t_map **);
void			create_link_x(t_map **map);
void			create_link_y(t_map **map);
t_client		*client_reset(t_client *client);

t_client		*delete_client(t_client *);
void			drop_ress(int, int, t_client *);
t_msg			*do_action(t_client **, t_map **, t_msg *, t_opt *);
void			droite(t_msg *msg, t_client *client, t_map **map);

void			egg_connect(int, t_client *);
void			egg_dead(int, t_client *);
void			egg_drop(int, t_client *);
void			egg_drop_by(int, int, t_client *);
void			egg_open(int, t_client *);
void			end_incant(int, t_client *);
t_client		*end_client(t_client *client);
t_msg			*exec_task(t_msg *task);
void			expulse(t_msg *msg, t_client *client, t_map **map);

void			gauche(t_msg *msg, t_client *client, t_map **map);
void			getcase(char **, int, t_map **, t_client *);
void			getcasemap(char **, int, t_map **, t_client *);
t_msg			*get_mess(t_client *client);
void			getinvplayer(char **, int, t_map **, t_client *);
void			getlevelplayer(char **, int, t_map **, t_client *);
void			getmapsize(char **, int, t_map **, t_client *);
void			getposplayer(char **, int, t_map **, t_client *);
void			getteam(char **, int, t_map **, t_client *);
void			gettime(char **, int, t_map **, t_client *);
double			get_time();
double			get_time_client(t_client *client, int action);
int			give_id();

void			inventaire(t_msg *mess, t_client *client, t_map **map);
void			init_map(t_map **map, t_conf *config);
t_msg			*into_order_task(t_msg *first, t_msg *new);

void			level_up(t_msg *msg, t_client *client, t_map **map);
void			loop_answer(char *, t_client *, t_map **, t_opt *);

char			**my_str_to_wordtab(char *str, char c);

void			new_inventory(t_client *client);
void			new_map(t_client *client, t_opt *opt, t_map **map);

void			parse_args(int, char **);
t_conf			*parseconf(t_map **);
void			player_dead(int, t_client *);
void			player_expulse(int, t_client *);
void			player_message(int, char *, t_client *);
void			prend_objet(t_msg *msg, t_client *client, t_map **map);
void			pose_objet(t_msg *msg, t_client *client, t_map **map);

t_client		*reroll(t_client *);
void			run_server(t_opt *opt);
t_msg			*remove_msg(t_msg *msg, t_client *client);

int			send_mess(t_msg *msg);
void			send_to_graphic(t_client *, char *);
void			settime(char **, int, t_map **, t_client *);
void			snd_msg_broadcast(char *, int, int);
void			sub_food(t_msg *, t_client *, const char *);
int			strlen_tab(char **str);

void			take_ress(int, int, t_client *);
char			**to_tab(char *, int, int);

void			voir(t_msg *mess, t_client *client, t_map **map);

void			*xmalloc(size_t size);
void			xlisten(int fd);
int			xsocket(struct protoent *pe);
int			xaccept(int, struct sockaddr_in, socklen_t);
void			xbind(int fd, struct sockaddr_in s_in);


#endif
