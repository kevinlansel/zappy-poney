#include	<unistd.h>
#include	<string>
#include	<iostream>
#include	<cstdlib>

void		launchDisplay(const std::string &s)
{
  execlp("./display", "display", s.c_str(), NULL);
}

void		launchIA(char *s)
{

}

int		main(int ac, char **av)
{
  std::string	s;
  int		i = 1;

  if (ac == 5 || ac == 7)
    {
      while (i < ac)
	{
	  s += (std::string)av[i] + " ";
	  i++;
	} 
      launchDisplay(s);
    }
  else
    {
      std::cout << "USAGE: ./Client [-h hote] [-n equipe] [-p port]" << std::endl;
      exit(-1);
    }
  return (0);
}
