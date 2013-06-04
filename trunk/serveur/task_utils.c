/*
** task_utils.c for h in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon Jun  3 15:13:05 2013 guillaume duez
** Last update Tue Jun  4 18:17:39 2013 guillaume duez
*/

#include	"serveur.h"

t_msg		*exec_task(t_msg *task)
{
  t_msg *msg;

  while (task && task->time > get_time())
    {
      if (send_mess(task) == -1)
	{
	  //find and suppres  client of the task 
	  printf("TO DO\n");
	}
      msg = task;
      task = task->nt;
      task->prev = NULL;
      //      free(msg);
    }
  return task;
}

t_msg		*into_order_task(t_msg *first, t_msg *new)
{
  return new;

  while (first && new->time > first->time && first->nt)
    first = first->nt;
  if (first)
    {
      new->nt = first;
      new->prev = first->prev;
      first = first->prev;
      first->nt = new;
      while (first->prev != NULL)
	first = first->prev;
    }
  else
    {
      first = new;
      if (new)
	{
	  first->nt = NULL;
	  first->prev = NULL;
	}
    }
  return first;
}

double		get_time()
{
 struct timeb	tp;
 double		time;
 double		milli;

 ftime(&tp);
 milli =  (double)tp.millitm / 1000;
 time = (double)tp.time + milli;
 // printf("%f , milli %f time:%f\n", (double)tp.time, milli, time);
 return  time;
}

void		sub_food(t_msg *msg, t_client *client, const char *str)
{
  double	time_elipse;
  double	current;

  current = get_time();
  time_elipse = current - client->time_eat;
  //  printf("time eat :%f, current : %f, time elipse :%f\n", client->time_eat, current, time_elipse);
  time_elipse = time_elipse / (1. / client->time);
  client->ress[NOURRITURE] = client->ress[NOURRITURE] - time_elipse;
  client->time_eat = current;
  if (client->ress[NOURRITURE] > 0)
    strcpy(msg->cmd, str);
  else
    strcpy(msg->cmd, "mort");
}
