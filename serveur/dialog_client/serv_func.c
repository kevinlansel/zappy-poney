/*
** serv_func.c for  in /home/lund/Projets/zappy-poney/serveur/dialog_client
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Jun 19 14:10:39 2013 florian dewulf
** Last update Wed Jun 26 14:27:00 2013 florian dewulf
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"../serveur.h"

void		gettime(char **arg, int fd, t_map **map, t_client *cl)
{
  int		size;
  char		*str;

  (void)(arg);
  (void)(map);
  size = snprintf(NULL, 0, "sgt %d\n", cl->time);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "sgt %d\n", cl->time);
  write(fd, str, strlen(str));
  free(str);
}

void		settime(char **arg, int fd, t_map **map, t_client *cl)
{
  int		size;
  char		*str;
  int		new_time;
  t_client	*tmp;

  (void)(map);
  tmp = cl;
  new_time = atoi(arg[0]);
  while (tmp)
    {
      tmp->time = new_time;
      tmp = tmp->nt;
    }
  size = snprintf(NULL, 0, "sgt %d\n", new_time);
  str = xmalloc((size + 1) * sizeof(char));
  snprintf(str, size, "sgt %d\n", new_time);
  write(fd, str, strlen(str));
  free(str);
}
