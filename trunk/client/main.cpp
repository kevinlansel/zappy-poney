#include	<unistd.h>
#include	<string>

void		launchDisplay(char *s)
{
  execlp("./display", "./display", s);
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
	} 
      launchDisplay(s.c_str());
    }
  else
    {
      std::cout << "USAGE: ./Client [-h hote] [-n equipe] [-p port]" << std::endl;
      exit(-1);
    }
  return (0);
}
