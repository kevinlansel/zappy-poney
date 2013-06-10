/*
** map_utils.c for  in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Fri Jun  7 18:09:18 2013 guillaume duez
** Last update Mon Jun 10 16:35:09 2013 guillaume duez
*/

#include	"serveur.h"


// creation de lien en x
void            create_link_x(t_map **map)
{
  int   y;
  int   x;

  y = 0;
  while (y < map[0][0].y_world)
    {
      x = 0;
      while (x < map[0][0].x_world)
        {
          if (x + 1 < map[0][0].x_world)
            map[y][x].left = &(map[y][x + 1]);
          else
            map[y][x].left = &(map[y][0]);
          if (x - 1 >= 0)
            map[y][x].right = &(map[y][x - 1]);
          else
            map[y][x].right = &(map[y][map[0][0].x_world]);
          x++;
        }
      y++;
    }
}

// creation de lien en y
void            create_link_y(t_map **map)
{
  int   y;
  int   x;

  x = 0;
  while (x < map[0][0].x_world)
    {
      y = 0;
      while (y < map[0][0].y_world)
        {
          if (y + 1 < map[0][0].y_world)
            map[y][x].up = &(map[y + 1][x]);
          else
            map[y][x].up = &(map[0][x]);
          if (y - 1 >= 0)
            map[y][x].down = &(map[y - 1][x]);
          else
            map[y][x].down = &(map[map[0][0].y_world][x]);
          y++;
        }
      x++;
    }

}

