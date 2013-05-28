/*
** send_receiv.c for  in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon May 27 15:15:13 2013 guillaume duez
** Last update Tue May 28 16:44:08 2013 guillaume duez
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
  if (size != 0)
    {
      msg = xmalloc(sizeof(t_msg));
      msg->cmd = str;
      msg->client = client;
      return msg;
    }
  if (size == 0)
    {
      printf("The client has leave\n");
      client = end_client(client);
      client = client_reset(client);
    }
  return NULL;
}
