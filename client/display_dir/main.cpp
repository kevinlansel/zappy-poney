#include	"Network_display.hh"

int		main(int ac, char **av)
{
  std::cout << (std::string)av[0] << std::endl;
  int		i = 1;
  std::string	host;
  int		port;
  int		team;

  host = "localhost";
  while (i < ac)
    {
      if ((std::string)av[i] == "-n")
	team = (int)av[i + 1];
      else if ((std::string)av[i] == "-h")
	host = (std::string)av[i + 1];
      else if ((std::string)av[i] == "-p")
	port = (int)av[i + 1];
      i += 2;
    }
  Network	net(host, port, team);
  //  Network net;
  
  //net.initConnexion();
}
