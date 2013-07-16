//
// main.cpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Tue Jul 16 16:16:35 2013 gery baudry
// Last update Tue Jul 16 16:17:52 2013 gery baudry
//

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

int		main(int ac, char **av)
{
  int		i = 1;
  std::string	host;
  int		port;
  std::string	team;
  Audio		music;
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
          ss.str(string(av[i + 1]));
          ss >> port;
          ss.str("");
        }
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
