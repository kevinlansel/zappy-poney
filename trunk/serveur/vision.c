/*
** vision.c for  in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon Jun  3 18:42:55 2013 guillaume duez
** Last update Tue Jul 16 10:51:52 2013 florian dewulf
*/

#include	<stdio.h>
#include	<string.h>
#include	"serveur.h"

static char	*get_object(char *str, int i, int nb)
{
  static char	tab[MAX][20] = { "nourriture", "linemate", "deraumere",
				 "sibur", "mendiane", "phiras", "thystame" };
  int		size;

  size = 0;
  while (nb > 0)
    {
      if (!str)
	{
	  size = strlen(tab[i]) + snprintf(NULL, size, " %s", tab[i]) + 1;
	  str = xmalloc(size + 1);
	  snprintf(str, size + 1,  " %s", tab[i]);
	}
      else
	{
	  size = strlen(str) + strlen(tab[i]) + snprintf(NULL, size, " %s", tab[i]) + 1;
	  str = realloc(str, size + 1);
	  snprintf(str + strlen(str), size + 1, " %s", tab[i]);
	}
      nb--;
    }
  return (str);
}

static char	*get_object_case(t_map *map)
{
  int		i;
  char		*str;

  i = 0;
  str = NULL;
  while (i < MAX)
    {
      if (map && map->ress[i] != 0)
	str = get_object(str, i, map->ress[i]);
      i++;
    }
  return (str);
}

static char	**get_line(t_map *map, int len, e_direct dir)
{
  int		i;
  t_map		*move;
  char		**str;
  char		*tmp;

  str = xmalloc(sizeof(char *) * len + 8);
  i = 0;
  move = map;
  while (i < len)
    {
      tmp = get_object_case(map);
      str[i] = (tmp ? tmp : "");
      if (move && dir == NORD)
	move = move->right;
      else if (move && dir == SUD)
	move = move->left;
      else if (move && dir == OUEST)
	move = move->up;
      else if (move)
	move = move->down;
      i++;
    }
  str[i] = NULL;
  return (str);
}


static char	*transform(char **str, char *final)
{
  int		i;
  int		len;

  i = 0;
  len = 0;
  while (str && str[i])
    {
      if (final == NULL)
	{
	  final = xmalloc(3 + strlen(str[i]));
	  snprintf(final, 2, "{");
	  len = 1 + strlen(str[i]);
	  snprintf(final + strlen(final), len + 1,  "%s", str[i]);
	}
      else
	{
	  len = strlen(str[i]) + strlen(final) + 1;
	  if (len > 0)
	    final = realloc(final, len + 1 * sizeof(char));
	  snprintf(final + strlen(final), len + 1,  ", %s", str[i]);
	}
      i++;
    }
  return final;
}

void            voir(t_msg *msg, t_client *client, t_map **map, t_opt *opt)
{
  int		level;
  t_map		*t;
  char		*fin;
  int		len;

  (void)opt;
  t = (len = 1) ? client->map : client->map;
  level = (fin = NULL) ? client->level + 1 : client->level + 1;
  while (level > 0 && map)
    {
      fin = transform(get_line(client->map, len, client->direct), fin);
      if (client->direct == NORD)
	client->map = client->map->up->left;
      else if (client->direct == SUD)
	client->map = client->map->down->right;
      else if  (client->direct== OUEST)
	client->map = client->map->left->down;
      else if (client->direct == EST)
	client->map = client->map->right->up;
      len += (level -= 1) ? 2 : 2;
    }
  client->map = (fin = realloc(fin, strlen(fin) + (3 * sizeof(char)))) ? t : t;
  snprintf(fin + strlen(fin), strlen(fin) + 3,  "}\n");
  sub_food(msg, client, fin);
  msg->time = get_time_client(client, 7);
}
