/*
** send_receiv.c for  in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon May 27 15:15:13 2013 guillaume duez
** Last update Mon May 27 16:59:37 2013 guillaume duez
*/

#include	"serveur.h"

t_msg		*get_mess(t_client *client)
{
  t_msg	*msg;
  int		size;
  char		*str;

  str = xmalloc(1024);
  size = recv(client->fd, str, 1024, MSG_DONTWAIT);
  str[size] = '\0';
  printf("%s", str);
  if (size == 0)
    exit(0);
  return NULL;
  /*
  msg = xmalloc(sizeof(t_mess));
  size = recv(client->fd, msg, sizeof(t_mess), MSG_DONTWAIT);
  */
  if (size == sizeof(t_msg) - 1)
    return msg;
  else
    {
      printf("The client has leave\n");
      client = end_client(client);
      client = client_reset(client);
    }
  return NULL;
}
