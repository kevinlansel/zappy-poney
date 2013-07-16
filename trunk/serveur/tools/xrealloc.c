/*
** xrealloc.c for  in /home/duez/project/zappy-poney/serveur
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue Jul 16 16:27:37 2013 guillaume duez
** Last update Tue Jul 16 16:30:26 2013 guillaume duez
*/

#include	<stdlib.h>
#include	<stdio.h>

void		*xrealloc(void *ptr, int size)
{
  if (size <= 0)
    return NULL;
  ptr = realloc(ptr, size);
  if (ptr == NULL)
    {
      printf("Can't realloc\n");
      exit(0);
    }
  return ptr;
}
