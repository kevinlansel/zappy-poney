/*
** check_end.c for  in /home/duez/project/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue Jul 16 17:55:08 2013 guillaume duez
** Last update Tue Jul 16 20:36:20 2013 florian dewulf
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"serveur.h"

static int	check_team(t_client *client)
{
  t_client	*tmp;
  char		*str;

  str = NULL;
  tmp = client;
  client = client_reset(client);
  while (client && client->end != 1)
    {
      if (!str && client->type == CLIENT)
	str = client->team;
      else if (str && client->type == CLIENT)
	{
	  if (strcmp(str, client->team) != 0)
	    {
	      client = tmp;
	      return 0;
	    }
	}
      client = client->nt;
    }
  client = tmp;
  printf("The team %s has win\n", str);
  end_game(client, str);
  return 1;
}

int		check_end(t_client *client)
{
  static int	conec = 0;
  t_client	*tmp;
  char		*str;

  tmp = client;
  client = client_reset(client);
  str = NULL;
  while (conec == 0 && client && client->end != 1)
    {
      if (client->type == CLIENT && !str)
	str = client->team;
      else if (str && client->type == CLIENT)
	{
	  if (strcmp(str, client->team) != 0)
	    conec = 1;
	}
      client = client->nt;
    }
  client = tmp;
  if (conec == 1)
    return check_team(client);
  else
    return 0;
}
