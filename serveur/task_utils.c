/*
** task_utils.c for h in /home/duez_a//zappy/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Mon Jun  3 15:13:05 2013 guillaume duez
** Last update Mon Jun 10 16:34:55 2013 guillaume duez
*/

#include	"serveur.h"

//execution des taches
t_msg		*exec_task(t_msg *task)
{
  while (task && task->end != 1 && task->time < get_time())
    {
      if (send_mess(task) == -1)
	{
	  //find and suppres  client of the task 
	  printf("TO DO\n");
	}
      task = task->nt;
      free(task->prev);
    }
  if (task)
    task->prev = NULL;
  return task;
}

// crztion du premier maillon
t_msg		*create_first()
{
  t_msg *new;
  
  new =	xmalloc(sizeof(t_msg));
  new->time = get_time() * 2;
  new->end = 1;
  return new;
}

//met le maillon au bonne endroit
t_msg		*into_order_task(t_msg *first, t_msg *new)
{
  while (first && new && new->time > first->time && first->end != 1)
    first = first->nt;
  if (first && first->prev)
    first = first->prev;
  if (first && first->end != 1)
    {
      new->nt = first->nt;
      new->prev = first;
      first->nt = new;
      new->nt->prev = new;
      new->end = 0;
      while (first->prev != NULL)
	first = first->prev;
    }
  else if (new)
    {
      first = create_first();
      new->end = 0;
      new->nt = first;
      new->prev = NULL;
      first->prev = new;
      return new;
    }
  return first;
}

//recupere le time actuellen en seconde , et les milliseconde 
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

//soustrait la nouriture et renvoie mort s il y a plus de nourriture
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
    strcpy(msg->cmd, "mort\n");
}
