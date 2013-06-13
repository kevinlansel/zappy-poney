/*
** tools_socket.c for  in /home/duez_a//zappy/perso/tools
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu May 23 17:54:04 2013 guillaume duez
** Last update Thu May 23 18:46:57 2013 guillaume duez
*/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>

int     xaccept(int fd, struct sockaddr_in s_in, socklen_t s_in_size)
{
  int ret;

  if ((ret = accept(fd, (struct sockaddr *)&s_in, &s_in_size))  == -1)
    {
      printf("Cannot connect to the server\n");
      close(fd);
      exit(-1);
    }
  return ret;
}

void    xbind(int fd, struct sockaddr_in s_in)
{
  if (bind(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      printf("Cannot bind\n");
      close(fd);
      exit(-1);
    }
}

void    xlisten(int fd)
{
  if (listen(fd, 42) == -1)
    {
      printf("Cannot listen");
      close(fd);
      exit(-1);
    }
}

int     xsocket(struct protoent *pe)
{
  int fd;

  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    {
      printf("Could not create the socket\n");
      exit(-1);
    }
  return fd;
}
