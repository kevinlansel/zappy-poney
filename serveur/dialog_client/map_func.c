/*
** map_func.c for  in /home/lund/Projets/zappy-poney/serveur/dialog_client
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Tue Jun 18 14:50:20 2013 florian dewulf
** Last update Tue Jul 16 17:30:14 2013 guillaume duez
*/

#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	"../serveur.h"

void		getmapsize(char **arg, int fd, t_map **map, t_client *cl)
{
  char		*str;
  int		size;

  (void)arg;
  (void)cl;
  size = snprintf(NULL, 0, "msz %d %d\n", map[0][0].x_world,
		  map[0][0].y_world) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "msz %d %d\n", map[0][0].x_world, map[0][0].y_world);
  write(fd, str, strlen(str));
  free(str);
}

void		getcase(char **arg, int fd, t_map **m, t_client *cl)
{
  char		*str;
  int		size;
  int		x;
  int		y;

  (void)(cl);
  x = atoi(arg[0]);
  y = atoi(arg[1]);
  size = snprintf(NULL, 0, "bct %d %d %d %d %d %d %d %d %d\n",
		  x, y, m[y][x].ress[0], m[y][x].ress[1], m[y][x].ress[2],
		  m[y][x].ress[3], m[y][x].ress[4], m[y][x].ress[5],
		  m[y][x].ress[6]) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "bct %d %d %d %d %d %d %d %d %d\n",
	   x, y, m[y][x].ress[0], m[y][x].ress[1], m[y][x].ress[2],
	   m[y][x].ress[3], m[y][x].ress[4], m[y][x].ress[5],
	   m[y][x].ress[6]);
  write(fd, str, strlen(str));
  free(str);
}

void		getcasemap(char **arg, int fd, t_map **m, t_client *cl)
{
  char		*str;
  int		size;
  int		x;
  int		y;

  (void)cl;
  (void)((x = -1) ? arg : arg);
  while (++x < m[0][0].x_world)
    {
      y = -1;
      while (++y < m[0][0].y_world)
	{
	  size = snprintf(NULL, 0, "bct %d %d %d %d %d %d %d %d %d\n",
			  x, y, m[y][x].ress[0], m[y][x].ress[1],
			  m[y][x].ress[2], m[y][x].ress[3], m[y][x].ress[4],
			  m[y][x].ress[5], m[y][x].ress[6]) + 1;
	  str = xmalloc((size + 1) * sizeof(char));
	  snprintf(str, size, "bct %d %d %d %d %d %d %d %d %d\n",
		   x, y, m[y][x].ress[0], m[y][x].ress[1],
		   m[y][x].ress[2], m[y][x].ress[3], m[y][x].ress[4],
		   m[y][x].ress[5], m[y][x].ress[6]);
	  write(fd, str, strlen(str));
	  free(str);
	}
    }
}

void		givecaseall(t_client *cl)
{
  char		*str;
  int		size;
  t_map		*m;
  t_client	*tmp;

  tmp = reroll(cl);
  m = cl->map;
  size = snprintf(NULL, 0, "bct %d %d %d %d %d %d %d %d %d\n",
		  m->x, m->y, m->ress[0], m->ress[1], m->ress[2],
		  m->ress[3], m->ress[4], m->ress[5],
		  m->ress[6]) + 1;
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "bct %d %d %d %d %d %d %d %d %d\n",
	   m->x, m->y, m->ress[0], m->ress[1], m->ress[2],
	   m->ress[3], m->ress[4], m->ress[5],
	   m->ress[6]);
  while (tmp && tmp->end != 1)
    {
      if (tmp->type == GRAPHIC)
	write(tmp->fd, str, strlen(str));
      tmp = tmp->nt;
    }
  free(str);
}
