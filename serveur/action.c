/*
** action.c for h in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon May 27 15:08:13 2013 guillaume duez
** Last update Thu Jun 20 20:21:10 2013 guillaume duez
*/

#include	"serveur.h"


//initialisation du tableau de pointeur sur func
static void	init_tab_func(void (*tab_func[NB_FUNC])(t_msg *, t_client *, t_map **))
{
  tab_func[0] = &avance;
  tab_func[1] = &droite;
  tab_func[2] = &gauche;
  tab_func[3] = &voir;
  tab_func[4] = &inventaire;
}


// recuperation du message avec get_mess et boucle pour trouver la fonction correspondante
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
      printf("%s\n", msg->cmd);
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

//enregistrement des message a renvoyer avec les times
t_msg		*do_action(t_client *client, t_map **map, t_msg *msg)
{
  t_msg *new;

  new = check_and_call(client, map);
  if (new != NULL)
    msg = into_order_task(msg, new);
  else
    msg = remove_msg(msg, client);
  return msg;
}
