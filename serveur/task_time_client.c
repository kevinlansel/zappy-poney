/*
** task_time_client.c for  in /home/duez/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon Jun 24 15:22:19 2013 guillaume duez
** Last update Wed Jun 26 14:20:49 2013 florian dewulf
*/

#include	<sys/timeb.h>
#include	"serveur.h"

double		get_time_client(t_client *client, int action)
{
  struct timeb   tp;
  double         time;
  double         milli;

  ftime(&tp);
  milli =  (double)tp.millitm / 1000;
  time = (double)tp.time + milli;
  if (client && time < client->action)
    time = client->action;
  if (client)
    client->action = time + (action / client->time);
  return  client->action;
}
