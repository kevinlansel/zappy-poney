/*
** check_msg_srv.c for  in /home/lund/Projets/zappy-poney/serveur/dialog_client
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Tue Jun 18 11:00:16 2013 florian dewulf
** Last update Tue Jun 25 14:06:53 2013 florian dewulf
*/

#include		<string.h>
#include		"serveur.h"

static void		init_complement(t_protocol *proto)
{
  proto[5].cmd = strdup("plv ");
  proto[5].nb_arg = 1;
  proto[5].func = &getlevelplayer;
  proto[6].cmd = strdup("pin ");
  proto[6].nb_arg = 1;
  proto[6].func = &getinventaireplayer;
  proto[7].cmd = strdup("sgt\n");
  proto[7].nb_arg = 0;
  proto[7].func = &gettime;
  proto[8].cmd = strdup("sst ");
  proto[8].nb_arg = 1;
  proto[8].func = &settime;
}

static t_protocol	*init_proto()
{
  t_protocol		*proto;

  proto = xmalloc(SIZE_PROTOCOL * sizeof(t_protocol));
  proto[0].cmd = strdup("msz\n");
  proto[0].nb_arg = 0;
  proto[0].func = &getmapsize;
  proto[1].cmd = strdup("bct ");
  proto[1].nb_arg = 2;
  proto[1].func = &getcase;
  proto[2].cmd = strdup("mct\n");
  proto[2].nb_arg = 0;
  proto[2].func = &getcasemap;
  proto[3].cmd = strdup("tna\n");
  proto[3].nb_arg = 0;
  proto[3].func = &getteam;
  proto[4].cmd = strdup("ppo ");
  proto[4].nb_arg = 1;
  proto[4].func = &getposplayer;
  init_complement(proto);
  return (proto);
}

void			loop_answer(char *cmd, t_client *cl, t_map **map)
{
  t_protocol		*pr;
  int			i;

  i = 0;
  pr = init_proto();
  while (i < SIZE_PROTOCOL)
    {
      if (strncmp(pr[i].cmd, cmd, strlen(pr[i].cmd)) == 0)
	{
	  if (cmp_nb_arg(pr[i].nb_arg, cmd, strlen(pr[i].cmd)))
	    pr[i].func(to_tab(cmd), cl->fd, map, reroll(cl));
	  else
	    write(cl->fd, "sbp\n", 4);
	  i = SIZE_PROTOCOL;
	}
      i++;
    }
}
