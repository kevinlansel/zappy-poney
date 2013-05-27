/*
** action.c for h in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon May 27 15:08:13 2013 guillaume duez
** Last update Mon May 27 16:01:02 2013 guillaume duez
*/

#include	"serveur.h"

static void	init_tab_func(void (*tab_func[NB_FUNC])(t_msg *, t_client *))
{
  //  tab_func[0] = &affich_chanel;
}

void	do_action(t_client *client)
{
  void	(*tab_func[NB_FUNC])(t_msg *, t_client *);
  t_msg	*msg;
  int	bool;
  int	i;
  static char	str[NB_FUNC][8] = { "test" };

  i = 0;
  bool = 0;
  if ((msg = get_mess(client)) != NULL)
    {
      while (i < NB_FUNC)
	{
	  if (strcmp(msg->cmd, str[i]) == 0)
	    {
	      // tab_func[i](msg, client);
	      printf("function call\n");
	      bool = 1;
	    }
	  i++;
	}
    }
  if (bool == 0)
    printf("No comand found from the client, or an error has come\n");
}
