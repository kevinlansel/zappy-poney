/*
** xmalloc.c for h in /home/duez_a//zappy/perso/tools
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 18:47:36 2013 guillaume duez
** Last update Tue Jul 16 16:13:52 2013 guillaume duez
*/

#include <stdlib.h>
#include <stdio.h>

void		*xmalloc(size_t size)
{
  void		*ptr;

  if (size <= 0)
    return NULL;
  ptr = malloc(size);
  if (ptr == NULL)
    {
      printf("Cannot malloc, error systems, exit\n");
      exit(0);
    }
  return ptr;
}
