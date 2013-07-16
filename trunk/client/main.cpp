//
// main.cpp for zappy main princ in /home/peelou/SVN/zappy-poney/client
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Wed Jul  3 10:28:42 2013 gery baudry
// Last update Wed Jul  3 10:29:00 2013 gery baudry
//
#include	<unistd.h>
#include	<string>
#include	<iostream>
#include	<cstdlib>
#include	<cstdio>
#include	<pthread.h>

void		*launchDisplay(void *str)
{
  char		*s = (char *)str;
  execlp("./display", "display", s, NULL);
  //std::cout << (std::string)s << "DISPLAY" << std::endl;
}

void		*launchIA(void *str)
{
  char		*s = (char *)str;
  execlp("./ia", "ia", s, NULL);
  //std::cout << (std::string)s << "IA" << std::endl;
}

int		main(int ac, char **av)
{
  std::string	s;
  char		*str;
  int		i = 1;
  pthread_t	th1, th2;
  void		*ret;

  if (ac == 5 || ac == 7)
    {
      while (i < ac)
	{
	  s += (std::string)av[i] + " ";
	  i++;
	}
      str = (char *)s.c_str();
      if (pthread_create(&th1, NULL, launchDisplay, str) < 0) {
	std::cerr << "Erreur lors de la création du thread Display" << std::endl;
	exit(1);
      }
      if (pthread_create(&th2, NULL, launchIA, str) < 0) {
	std::cerr << "Erreur lors de la création du thread IA" << std::endl;
	exit(1);
      }
      (void)pthread_join(th1, &ret);
      (void)pthread_join(th2, &ret);
    }
  else
    {
      std::cout << "USAGE: ./Client [-h hote] [-n equipe] [-p port]" << std::endl;
      exit(-1);
    }
  return (0);
}
