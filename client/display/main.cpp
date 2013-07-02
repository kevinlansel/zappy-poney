#include	<cstdlib>
#include	<iostream>
#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	"Windows.hpp"
#include	"Audio.hpp"
#include	"Network.hpp"

int		main(int ac, char **av)
{
  int		i = 1;
  std::string	host;
  int		port;
  int		team;
  Windows	window(10, 10);
  Audio		music;

  host = "localhost";
  while (i < ac)
    {
      if ((std::string)av[i] == "-n")
	team = atoi(av[i + 1]);
      else if ((std::string)av[i] == "-h")
	host = (std::string)av[i + 1];
      else if ((std::string)av[i] == "-p")
	port = atoi(av[i + 1]);
      i += 2;
      music.PlaySound();
      window.CreateWindow();
    }
  Network	net(host, port, team);
  //net.initConnexion();
}
