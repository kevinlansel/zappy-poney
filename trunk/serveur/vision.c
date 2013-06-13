/*
** vision.c for  in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon Jun  3 18:42:55 2013 guillaume duez
** Last update Thu Jun 13 16:21:21 2013 guillaume duez
*/

#include	"serveur.h"

static char	*get_object(char *str, int i, int nb)
{
  static char	tab[MAX][20] = { "NOURRITURE", "LINEMATE", "DERAUMERE",
				 "SIBUR", "MENDIANE", "PHIRAS", "THYSTAME" };
  int		size;

  size = 0;
  if (!str)
    {
      size = strlen(tab[i]) + snprintf(NULL, size, "%s %d", tab[i] , nb) + 1;
      str = xmalloc(size + 1);
      snprintf(str, size,  "%s %d", tab[i] , nb);
    }
  else
    {
      size = strlen(str) + strlen(tab[i]) + snprintf(NULL, size, "%s %d", tab[i] , nb) + 1;
      str = realloc(str, size + 1);
      snprintf(str, size, "%s %d", tab[i] , nb);
    }
  return (str);
}

char		*get_object_case(t_map *map)
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

char		**get_line(t_map *map, int len, e_direct dir)
{
  int	i;
  t_map	*move;
  char	**str;
  char	*tmp;

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


char		*transform(char **str, char *final)
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
	  snprintf(final + strlen(final), len + 1,  ",%s", str[i]);
	}
      i++;
    }
  return final;
}

void            voir(t_msg *msg, t_client *client, t_map **map)
{
  int		level;
  t_map		*tmp;
  e_direct	dir;
  char		*fin;
  int		len;

  len = 1;
  dir = client->map->direct;
  tmp = client->map;
  level = /* client->level */ 6;
  fin = NULL;
  while (level > 0 && map)
    {
      //      printf("map x: %d  y = %d\n", client->map->x, client->map->y);
      fin = transform(get_line(client->map, len, client->map->direct), fin);
      if (dir == NORD)
	client->map = client->map->up->left;
      else if (dir == SUD)
	client->map = client->map->down->right;
      else if (dir == OUEST)
	client->map = client->map->left->down;
      else if (dir == EST)
	client->map = client->map->right->up;
      level--;
      len += 2;
    }
  if (fin)
    {
      fin = realloc(fin, strlen(fin) + 2 * sizeof(char));
      snprintf(fin + strlen(fin), strlen(fin) + 2,  "}\n");
      msg->cmd = fin;
    }
  client->map = tmp;
}

