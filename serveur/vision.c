/*
** vision.c for  in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon Jun  3 18:42:55 2013 guillaume duez
** Last update Tue Jun 11 15:26:41 2013 guillaume duez
*/

#include	"serveur.h"


char		*get_object_case(t_map *map)
{
  int		i;
  char		*str;
  static char	tab[MAX][20] = { "NOURRITURE", "LINEMATE", "DERAUMERE",
				  "SIBUR", "MENDIANE", "PHIRAS", "THYSTAME" };
  int		size;
  int		bool;

  bool = 0;
  size = 0;
  i = 0;
  while (i < MAX)
    {
      if (map->ress[i] != 0 && bool == 0)
	{
	  str = malloc((size = strlen(tab[i])));
	  strcpy(str, tab[i]);
	  bool = 1;
	}
      else if (map->ress[i] != 0)
	{
	  str = realloc(str, size + strlen(tab[i]));
	  strcpy(str + size , tab[i]);
	  size += strlen(tab[i]);
	}
      i++;
    }
  return (str);
}

char		**get_object_line(t_map *map, int len, e_direct dir)
{
  int	i;
  t_map	*move;
  char	**str;

  str = xmalloc(sizeof(char *) * len + 1);
  i = 0;
  move = map;
  while (i < len)
    {
      str[i] = get_object_case(map);
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

void            voir(t_msg *msg, t_client *client, t_map **map)
{
  int		level;
  t_map		*tmp;
  e_direct	dir;
  char		**str;
  int		len;

  len = 1;
  dir = client->map->direct;
  tmp = client->map;
  level = /* client->level */ 10;
  printf("level ? %d\n", level);
  while (level > 0)
    {
      printf("recal map x: %d  y = %d\n", client->map->x, client->map->y);
      str = get_object_line(client->map, len, client->map->direct);
      printf("pl\n");
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
      /*
      //tempory for print
      int i = 0;
      while (str[i] != NULL)
	{
	  printf("%s\n", str[i]);
	  i++;
	}
      */
    }
  client->map = tmp;
}

