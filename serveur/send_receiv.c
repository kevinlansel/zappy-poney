/*
** send_receiv.c for  in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon May 27 15:15:13 2013 guillaume duez
** Last update Thu Jun 20 20:20:34 2013 guillaume duez
*/

#include	"serveur.h"

t_msg		*remove_msg(t_msg *msg, t_client *client)
{
  while (msg && msg->end != 1)
    {
      if (msg->client == client && msg->prev)
	{
	  msg = msg->prev;
	  msg->nt = msg->nt->nt;
	  free(msg->nt->prev);
	  msg->nt->prev = msg;
	}
      else if (msg->client == client)
	{
	  msg = msg->nt;
	  free(msg->prev);
	  msg->prev = NULL;
	}
      if (msg && msg->end != 1)
	msg = msg->nt;
    }
  while (msg->prev)
    msg = msg->prev;
  return msg;
}

int		send_mess(t_msg *msg)
{
  int	ret;

  if (!msg || !msg->client)
    return -1;
  if ((ret = send(msg->client->fd, msg->cmd ,strlen(msg->cmd) + 1, MSG_OOB) <= 0))
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
  if (size > 0)
    {
      str[size - 1] = '\0';
      msg = xmalloc(sizeof(t_msg));
      msg->cmd = str;
      msg->client = client;
      return msg;
    }
  else
    {
      printf("The client has leave with fd :%d\n", client->fd);
      client = end_client(client);
      client = client_reset(client);
    }
  return (NULL);
}
