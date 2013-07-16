/*
** check_args.c for  in /home/duez/project/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue Jul 16 16:42:00 2013 guillaume duez
** Last update Tue Jul 16 16:56:22 2013 guillaume duez
*/

#include	<string.h>
#include	<stdio.h>
#include	"serveur.h"

int		print_code_error(int error)
{
  if (error == 0)
    printf("Error : argument -n not specified\n");
  else if (error == -1)
    printf("Un nom d'équipe est vide\n");
  else if (error == -2)
    printf("Deux équipes possèdent le même nom\n");
  else
    return (1);
  return (-1);
}

int		check_name_team(char **name_team)
{
  int		i;
  int		k;
  char		*tmp;

  if (!name_team)
    return (0);
  i = 0;
  while (name_team && name_team[i])
    {
      if (strcmp(name_team[i], "") == 0)
	return (-1);
      k = i;
      tmp = name_team[i];
      while (name_team && name_team[i])
	{
	  if (strcmp(name_team[i], tmp) == 0 && k != i)
	    return (-2);
	  i++;
	}
      i = k;
      i++;
    }
  return (1);
}
