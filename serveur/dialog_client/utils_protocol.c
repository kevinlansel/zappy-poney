/*
** utils_protocol.c for  in /home/lund/Projets/zappy-poney/serveur/dialog_client
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Tue Jun 18 11:50:21 2013 florian dewulf
** Last update Tue Jun 18 14:42:26 2013 florian dewulf
*/

#include	<stdlib.h>
#include	<string.h>
#include	"serveur.h"

int		cmp_nb_arg(const int nb_waiting, const char *cmd, const int offset)
{
  int		i;
  int		nb;
  char		*tmp;

  i = -1;
  nb = 1;
  tmp = cmd + offset;
  while (cmd && (cmd[++i] == ' ' || cmd[i] == '\t' || cmd[i] == '\n'));
  while (cmd && cmd[i])
    {
      if (cmd[i] == ' ' || cmd[i] == '\t')
	{
	  nb++;
	  while (cmd && (cmd[i] == ' ' || cmd[i] == '\t' || cmd[i] == '\n'))
	    i++;
	}
      else
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t')
	  i++;
    }
  i -= strlen(cmd - 2);
  while (i > 0 && cmd[i] == ' ' || cmd[i] == '\t')
    i--;
  nb = (i == strlen(cmd) - 2) ? nb : (nb - 1);
  return ((nb == nb_waiting) ? 1 : 0);
}

char		**to_tab(const char *cmd, int offset, const int size)
{
  char		**tab;
  char		*str;
  int		i;
  int		j;
  int		tmp;

  i = -1;
  j = 0;
  tab = xmalloc((size + 1) * sizeof(char *));
  str = cmd + offset;
  while (str[++i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'));
  while (str[i])
    if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
      while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	i++;
    else
      {
	tmp = i;
	while (str[tmp] && str[tmp] != ' ' && str[tmp] != '\t' && str[tmp] != '\n')
	  tmp++;
	tab[j] = xmalloc((tmp - i + 1) * sizeof(char));
	strncpy(tab[j], str + i ,tmp - i);
	i = tmp;
      }
  return ((tab[j] = NULL) ? tab : tab);
}

t_client	*reroll(t_client *cl)
{
  t_client	*tmp;

  tmp = cl;
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  return (tmp);
}
