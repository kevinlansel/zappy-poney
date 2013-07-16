//
// main.cpp for  in /home/lund/Projets/zappy-poney/client/ia
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Mon Jul 15 16:26:43 2013 florian dewulf
// Last update Tue Jul 16 10:38:14 2013 kevin lansel
//

#include	<sstream>
#include	<string>
#include	"Network.hpp"
#include	"tmp.hpp"
#include	"get_next_line.hpp"

using namespace	std;

static int	string_to_int(const string &str)
{
  stringstream	ss;
  int		ret;

  ss.str(str);
  ss >> ret;
  return (ret);
}

static int	usage()
{
  std::cout << "Usage : -n team [-h ip] [-p port]" << std::endl;
  return (0);
}

static int	main_loop(const string &str, const int &port, const string &team)
{
  Network	net(str, port, team);
  string	data;
  int		nb_connexion;
  stringstream	ss;
  int		x = 0;
  int		y = 0;

  net.initConnexion();
  gnl		getnext(net.getSock());
  data = getnext.get_next_line();
  if (data == "BIENVENUE")
    {
      write(net.getSock(), team.c_str(), team.size());
      data = getnext.get_next_line();
      nb_connexion = string_to_int(data);
      std::cout << nb_connexion << " connexion remaining" << std::endl;
      data = getnext.get_next_line();
    }
  else
    {
      std::cout << "Error on initialisation of the connexion" << std::endl;
      return (0);
    }
  ss.str(data);
  ss >> x;
  ss >> y;
  Tmp		ia(x, y, team);
  ia.loop(getnext, net.getSock());
  return (0);
}

int		main(int ac, char **av)
{
  string	str = "127.0.0.1";
  int		port = 4243;
  string	team = "";
  int		i = 1;

  while (av[i])
    {
      if (string(av[i]) == "-n")
	{
	  if (i + 1 >= ac)
	    return (usage());
	  team = av[i + 1];
	  i += 2;
	}
      else if (string(av[i]) == "-h")
	{
	  if (i + 1 >= ac)
	    return (usage());
	  str = av[i + 1];
	  i += 2;
	}
      else if (string(av[i]) == "-p")
	{
	  if (i + 1 >= ac)
	    return (usage());
	  port = string_to_int(string(av[i + 1]));
	  i += 2;
	}
      else
	return (usage());
    }
  if (team == "")
    return (usage());
  team += "\n";
  return (main_loop(str, port, team));
}
