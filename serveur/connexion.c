/*
** connexion.c for  in /home/lund/Projets/zappy-poney/serveur
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu Jun 27 10:38:25 2013 florian dewulf
** Last update Tue Jul 16 14:59:38 2013 florian dewulf
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"serveur.h"

static void	graphic_connect(t_client *cl, t_map **map, t_opt *opt)
{
  t_client	*tmp;

  tmp = reroll(cl);
  getmapsize(NULL, cl->fd, map, cl);
  gettime(NULL, cl->fd, NULL, cl);
  getcasemap(NULL, cl->fd, map, cl);
  getteam(opt->name_team, cl->fd, NULL, cl);
  while (tmp && tmp->end != 1)
    {
      if (tmp->type == CLIENT)
	  connexion_player(NULL, cl->fd, NULL, tmp);
      else if (tmp->type == EGG)
	connec_egg(cl->fd, tmp);
      tmp = tmp->nt;
    }
  tmp = reroll(cl);
  while (tmp && tmp->end != 1)
    {
      if (tmp->type == CLIENT)
	giveinventaire(cl->fd, tmp);
      tmp = tmp->nt;
    }
}

static t_client	*transform_egg_to_client(t_client *egg, t_client **cl)
{
  egg_connect(egg->id, reroll(egg));
  egg->fd = (*cl)->fd;
  egg->id = (*cl)->id;
  egg->type = CLIENT;
  egg->level = 1;
  egg->time = (*cl)->time;
  *cl = delete_client(*cl);
  return (egg);
}

static t_client	*check_egg(char *name_team, t_client **cl)
{
  t_client	*tmp;

  tmp = *cl;
  while (tmp && tmp->prev)
    tmp = tmp->prev;
  while (tmp && tmp->end != 1)
    {
      if (tmp->type == EGG && strcmp(tmp->team, name_team) == 0)
	return (tmp);
      tmp = tmp->nt;
    }
  return (NULL);
}

static int	ia_connect(char *name_team, t_client **cl, t_opt *opt)
{
  int		i;
  int		size;
  char		*str;
  t_client	*tmp;

  i = -1;
  while (opt->name_team && opt->name_team[++i] &&
	 strcmp(opt->name_team[i], name_team) != 0);
  if (opt->name_team[i] == NULL)
    return (0);
  if ((tmp = check_egg(name_team, cl)) != NULL)
    *cl = transform_egg_to_client(tmp, cl);
  if (opt->nb_player[i] >= 1)
    {
      size = snprintf(NULL, 0, "%d\n", opt->nb_player[i]) + 1;
      str = xmalloc((size + 1) * sizeof(char));
      snprintf(str, size, "%d\n", opt->nb_player[i]);
      write((*cl)->fd, str, strlen(str));
      free(str);
      opt->nb_player[i]--;
      (*cl)->type = CLIENT;
      (*cl)->team = strdup(name_team);
      return (1);
    }
  return (0);
}

void		connexion(t_client **cl, t_map **map, t_opt *opt)
{
  t_msg		*msg;
  int		size;
  char		*str;

  if ((msg = get_mess(*cl, opt)) != NULL)
    {
      if (strcmp(msg->comand, "GRAPHIC") == 0)
	graphic_connect(*cl, map, opt);
      else if (ia_connect(msg->comand, cl, opt) == 1)
	{
	  size = snprintf(NULL, 0, "%d %d\n",
			  map[0][0].x_world, map[0][0].y_world) + 1;
	  str = xmalloc((size + 1) * sizeof(char));
	  snprintf(str, size, "%d %d\n", map[0][0].x_world, map[0][0].y_world);
	  write((*cl)->fd, str, strlen(str));
	  free(str);
	}
      else
	{
	  close((*cl)->fd);
	  *cl = delete_client(*cl);
	}
    }
}
