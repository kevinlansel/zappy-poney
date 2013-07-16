#include	<cstdlib>
#include	<iostream>
#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	"Windows.hpp"
#include	"Audio.hpp"
#include	"Network.hpp"
#include	<cstdlib>
#include	<ctime>

static int	usage()
{
  std::cout << "Usage : -n team [-p port] [-h ip]" << std::endl;
}

static void	loop(const std::string &host, int port, const std::string &team)
{
  Core		core(host, port, team);

  try
    {
      core.init();
      while (core.update())
	core.draw();
    }
  catch (const Except &e)
    {
      std::cerr << "Error : " << e.what() << std::endl;
      return;
    }
}

int		main(int ac, char **av)
{
  int		i = 1;
  std::string	host;
  int		port;
  std::string	team;
  srand(time(NULL));
  std::stringstream	ss;

  host = "localhost";
  while (i < ac)
    {
      if ((std::string)av[i] == "-n" && i + 1 < ac)
	team = std::string(av[i + 1]);
      else if ((std::string)av[i] == "-h" && i + 1 < ac)
	host = (std::string)av[i + 1];
      else if ((std::string)av[i] == "-p" && i + 1 < ac)
	{
	  ss.str(std::string(av[i + 1]));
	  ss >> port;
	  ss.str("");
	}
      i += 2;
    }
  if (team == "")
    return (usage());
  loop(host, port, team);
  return (0);
}
