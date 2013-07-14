/*
** action.c for h in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon May 27 15:08:13 2013 guillaume duez
** Last update Sun Jul 14 14:11:54 2013 florian dewulf
*/

#include	<stdio.h>
#include	<string.h>
#include	"serveur.h"

static char	str[NB_FUNC][LEN] = { "avance", "droite", "gauche", "voir",
				      "inventaire", "prend", "pose",
				      "broadcast", "expulse", "incantation",
				      "fork", "connect_nbr"};

static void	init_tab_func(void (*tab_func[NB_FUNC])(t_msg *, t_client *,
							t_map **, t_opt *))
{
  tab_func[0] = &avance;
  tab_func[1] = &droite;
  tab_func[2] = &gauche;
  tab_func[3] = &voir;
  tab_func[4] = &inventaire;
  tab_func[5] = &prend_objet;
  tab_func[6] = &pose_objet;
  tab_func[7] = &broadcast;
  tab_func[8] = &expulse;
  tab_func[9] = &level_up;
  tab_func[10] = &fork_egg;
  tab_func[11] = &connecnb;
}

static t_msg	*check_and_call(t_client *client, t_map **map,
				void (*tab_func[NB_FUNC])
				(t_msg *, t_client *, t_map **, t_opt *),
				t_opt *opt)
{
  t_msg		*msg;
  int		bool;
  char		*tmp;
  int		i;

  i = -1;
  bool = 0;
  if ((msg = get_mess(client, opt)) != NULL)
    {
      printf("%s\n", msg->comand);
      while (++i < NB_FUNC)
	{
	  tmp = my_str_to_wordtab(msg->comand, ' ')[0];
	  if (tmp  && strcmp(tmp, str[i]) == 0)
	    {
	      tab_func[i](msg, client, map, opt);
	      bool = 1;
	    }
	}
    }
  if (msg && i == NB_FUNC)
    loop_answer(msg->comand, client, map, opt);
  bool = ((msg && bool == 0) ? 0 : (msg ? 1 : -1));
  if (bool != -1)
    msg->bool = bool;
  return msg;
}

t_msg		*do_action(t_client **client, t_map **map,
			   t_msg *msg, t_opt *opt)
{
  t_msg		*new;
  void		(*tab_func[NB_FUNC])(t_msg *, t_client *, t_map **, t_opt *);

  if (*client && (*client)->type == WAIT_CO)
    {
      connexion(client, map, opt);
      return (msg);
    }
  else
    {
      init_tab_func(tab_func);
      new = check_and_call(*client, map, tab_func, opt);
      if (new != NULL && new->bool == 1)
	msg = into_order_task(msg, new);
      else if (msg != NULL && new == NULL)
	msg = remove_msg(msg, *client);
    }
  return msg;
}
