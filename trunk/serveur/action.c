/*
** action.c for h in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon May 27 15:08:13 2013 guillaume duez
** Last update Wed Jun 26 15:33:58 2013 florian dewulf
*/

#include	<stdio.h>
#include	<string.h>
#include	"serveur.h"

static char	str[NB_FUNC][LEN] = { "avance", "droite", "gauche", "voir",
				      "inventaire", "prend", "pose",
				      "broadcast", "expulse"};

static void	init_tab_func(void (*tab_func[NB_FUNC])(t_msg *, t_client *, t_map **))
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
}

static t_msg	*check_and_call(t_client *client, t_map **map)
{
  void		(*tab_func[NB_FUNC])(t_msg *, t_client *, t_map **);
  t_msg		*msg;
  int		bool;
  char		*tmp;
  int		i;

  i = -1;
  bool = 0;
  init_tab_func(tab_func);
  if ((msg = get_mess(client)) != NULL)
    {
      while (++i < NB_FUNC)
	{
	  tmp = my_str_to_wordtab(msg->comand, ' ')[0];
	  if (tmp  && strcmp(tmp, str[i]) == 0)
	    {
	      tab_func[i](msg, client, map);
	      bool = 1;
	    }
	}
    }
  if (i == NB_FUNC)
    loop_answer(msg->comand, client, map);
  bool = ((msg && bool == 0) ? 0 : (msg ? 1 : -1));
  if (bool != -1)
    msg->bool = bool;
  return msg;
}

t_msg		*do_action(t_client *client, t_map **map, t_msg *msg)
{
  t_msg		*new;

  new = check_and_call(client, map);
  if (new != NULL && new->bool == 1)
    {
      printf("enter\n");
      msg = into_order_task(msg, new);
    }
  else if (msg != NULL && new == NULL)
    msg = remove_msg(msg, client);
  else
    {
      printf("else\n");
    }
  return msg;
}
