/*
** send_receiv.c for  in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon May 27 15:15:13 2013 guillaume duez
** Last update Mon Jun 10 17:22:39 2013 guillaume duez
*/

#include	"serveur.h"

int		send_mess(t_msg *msg)
{
  if (!msg || !msg->client)
    return -1;
  if (msg && msg->client && send(msg->client->fd, msg->cmd , strlen(msg->cmd) + 1, MSG_OOB) == -1)
    {
      printf("Unable to send message, for client :%s", msg->client->nick);
      close(msg->client->fd);
      return -1;
    }
  return 0;
}

t_msg		*get_mess(t_client *client)
{
  t_msg		*msg;
  int		size;
  char		*str;

  str = xmalloc(1024);
  size = recv(client->fd, str, 1024, MSG_DONTWAIT);
  str[size - 1] = '\0';
  printf("%s\n", str);
  if (size != 0)
    {
      msg = xmalloc(sizeof(t_msg));
      msg->cmd = str;
      msg->client = client;
      return msg;
    }
  else
    {
      printf("The client has leave\n");
      client = end_client(client);
      client = client_reset(client);
    }
  return NULL;
}
