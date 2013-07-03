#include	<cstdlib>
#include	<iostream>
#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	"Windows.hpp"
#include	"Audio.hpp"
#include	"Network.hpp"
#include	<cstdlib>
#include	<ctime>

int		main(int ac, char **av)
{
  int		i = 1;
  std::string	host;
  int		port;
  std::string	team;
  Audio		music;

  srand(time(NULL));
  host = "localhost";
  while (i < ac)
    {
      if ((std::string)av[i] == "-n")
	team = std::string(av[i + 1]);
      else if ((std::string)av[i] == "-h")
	host = (std::string)av[i + 1];
      else if ((std::string)av[i] == "-p")
	port = atoi(av[i + 1]);
      i += 2;
    }
  Network	net(host, port, team);
  net.initConnexion();
  music.PlaySound();
  net.doLoop();
  Windows	window(net.getTailleX(), net.getTailleY());
  window.CreateWindows();
  
}
