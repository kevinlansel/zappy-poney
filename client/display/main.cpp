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
  int		team;
  Audio		music;

  srand(time(NULL));
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
      Network	net(host, port, team);
      net.initConnexion();
      net.doLoop();
      music.PlaySound();
      // recuperer les premieres infos du serveur
      Windows	window(net.getTailleX(), net.getTailleY());
      std::cout << net.getTailleX() << std::endl;
      window.CreateWindows();
      // dans le create window, mettre le select etc.. dans la sfml loop
    }
}