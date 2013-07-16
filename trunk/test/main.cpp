#include	<cstdlib>
#include	<iostream>
#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	"Windows.hpp"
#include	"Audio.hpp"
#include	"Network.hpp"
#include	<cstdlib>
#include	<ctime>

int		toInt(const std::string &str)
{
  std::stringstream	ss;
  int			ret;

  ss.str(str);
  ss >> ret;
  return (ret);
}

static int	usage()
{
  std::cout << "Usage : -n team [-p Port] [-h Ip]" << std::endl;
}

int		main(int ac, char **av)
{
  int			i = 1;
  std::string		host = "127.0.0.1";
  int			port = 4243;
  std::string		team;
  std::stringstream	ss;

  srand(time(NULL));
  while (i < ac)
    {
      if ((std::string)av[i] == "-n" && i + 1 < ac)
	team = std::string(av[i + 1]);
      else if ((std::string)av[i] == "-h" && i + 1 < ac)
	host = (std::string)av[i + 1];
      else if ((std::string)av[i] == "-p" && i + 1 < ac)
	port = toInt(string(av[i + 1]));
      i += 2;
    }
  if (team == "")
    return (usage());
  Network	net(host, port, team);
  net.initConnexion();
  gnl gl(net.getSock());
  music.PlaySound();
  net.doLoop(gl);
  Windows	window(net.getTailleX(), net.getTailleY(), net);
  window.CreateWindows(gl);
}
