/*
** action.c for h in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon May 27 15:08:13 2013 guillaume duez
** Last update Thu Jun  6 21:29:39 2013 guillaume duez
*/

#include	"serveur.h"

static void	init_tab_func(void (*tab_func[NB_FUNC])(t_msg *, t_client *, t_map **))
{
  tab_func[0] = &avance;
  tab_func[1] = &droite;
  tab_func[2] = &gauche;
  tab_func[3] = &voir;
  tab_func[4] = &inventaire;
}

static t_msg	*check_and_call(t_client *client, t_map **map)
{
  void	(*tab_func[NB_FUNC])(t_msg *, t_client *, t_map **);
  t_msg	*msg;
  int	bool;
  int	i;
  static char	str[NB_FUNC][LEN] = { "avance", "droite", "gauche", "voir",
				      "inventaire", "prend objet", "pose objet",
				      "expulse"};
  i = 0;
  bool = 0;
  init_tab_func(tab_func);
  if ((msg = get_mess(client)) != NULL)
    {
      while (i < NB_FUNC)
	{
	  if (strcmp(msg->cmd, str[i]) == 0 && i < 5)
	    {
	      tab_func[i](msg, client, map);
	      bool = 1;
	    }
	  i++;
	}
    }
  if (bool == 0)
    return NULL;
  return msg;
}

t_msg		*do_action(t_client *client, t_map **map, t_msg *msg)
{
  t_msg *new;

  new = check_and_call(client, map);
  if (new != NULL)
    msg = into_order_task(msg, new);
  return msg;
}
