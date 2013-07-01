/*
** init_map.c for  in /home/lund/Projets/zappy-poney/serveur
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu Jun 13 11:31:35 2013 florian dewulf
** Last update Mon Jul  1 15:44:16 2013 guillaume duez
*/

#include	<stdlib.h>
#include	"serveur.h"

void		put_in_random_case(t_map **map, int type)
{
  unsigned int	x;
  unsigned int	y;

  x = rand() % map[0][0].x_world;
  y = rand() % map[0][0].y_world;
  map[y][x].ress[type]++;
}

void		init_map(t_map **map, t_conf *config)
{
  unsigned int	i;
  unsigned int	ressource;

  i = 0;
  while (i < MAX)
    {
      ressource = 0;
      while ((int)ressource < config->max_repop[i])
	{
	  put_in_random_case(map, i);
	  ressource++;
	}
      i++;
    }
}
