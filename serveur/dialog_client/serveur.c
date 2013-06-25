/*
** serveur.c for  in /home/duez_a//zappy/perso/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 17:52:10 2013 guillaume duez
** Last update Tue Jun 18 10:18:04 2013 florian dewulf
*/

#include	"serveur.h"

//creation de chaque case de la map || creation de ressource aléatoire a faire
static void		create_case(t_map *map, int x, int y, int x_world, int y_world)
{
  map->ress[NOURRITURE] = 0;
  map->ress[LINEMATE] = 0;
  map->ress[DERAUMERE] = 0;
  map->ress[SIBUR] = 0;
  map->ress[MENDIANE] = 0;
  map->ress[PHIRAS] = 0;
  map->ress[THYSTAME] = 0;
  map->x = x;
  map->y = y;
  map->x_world = x_world;
  map->y_world = y_world;
}

//creation de la map
static t_map		**create_map(int y_world, int x_world)
{
  t_map			**map;
  int			y;
  int			x;
  t_conf		*conf;

  y = 0;
  map = xmalloc(sizeof(t_map *) * y_world);
  while (y < y_world)
    {
      x = 0;
      map[y] = xmalloc(sizeof(t_map) * x_world);
      while (x < x_world)
	{
	  create_case(&map[y][x], x, y, x_world, y_world);
	  x++;
	}
      y++;
    }
  conf = parseconf(map);
  init_map(map, conf);
  return (map);
}

int		main(int ac, char **av)
{
  int		y_world = atoi(av[1]);
  int		x_world = atoi(av[1]);
  t_map		**map = create_map(y_world, x_world);

  
}
