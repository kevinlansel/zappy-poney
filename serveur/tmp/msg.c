/*
** msg.c for  in /home/lund/Projets/zappy-poney/serveur/tmp
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Fri Jun 14 16:25:39 2013 florian dewulf
** Last update Fri Jun 14 17:31:19 2013 florian dewulf
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"serveur.h"

void		snd_msg_broadcast(char *str, int dir, int fd)
{
  char		*msg;
  int		size;

  size = snprint(msg, NULL, "message %d,%s\n", dir, str);
  msg = xmalloc((size + 1) * sizeof(char));
  snprintf(msg, size, "message %d,%s\n", dir, str);
  write(fd, msg, strlen(msg));
  free(msg);
}
