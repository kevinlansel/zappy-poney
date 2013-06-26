/*
** msg.c for  in /home/lund/Projets/zappy-poney/serveur/tmp
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Fri Jun 14 16:25:39 2013 florian dewulf
** Last update Wed Jun 26 14:23:22 2013 florian dewulf
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"serveur.h"

void		snd_msg_broadcast(char *str, int dir, int fd)
{
  char		*msg;
  int		size;

  if (str[0] == ' ')
    str++;
  size = snprintf(NULL, 0, "message %d,%s\n", dir, str);
  msg = xmalloc((size + 1) * sizeof(char));
  snprintf(msg, size, "message %d,%s\n", dir, str);
  write(fd, msg, strlen(msg));
  free(msg);
}

void		send_to_graphic(t_client *cl, char *str)
{
  t_client	*begin;

  begin = cl;
  while (begin->prev != NULL)
    begin = begin->prev;
  while (begin && begin->end != 1)
    {
      if (begin->graphic == 1)
	write(begin->fd, str, strlen(str));
      begin = begin->nt;
    }
}
