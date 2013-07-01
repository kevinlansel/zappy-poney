#include	"Network_display.hh"

Network::Network(std::string &host, int port, int team):
  _host(host), _port(port), _team(team)
{
  this->_kill = 0;
  this->_tailleX = "";
  this->_tailleY = "";
}

void	Network::initConnexion()
{
  struct sockaddr_in s_in;
  struct protoent *pe;
  fd_set        fd_read;
  char		buff[4096];
  int		a;
  std::string	req = "";

  pe = getprotobyname("TCP");
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(this->_port);
  s_in.sin_addr.s_addr = inet_addr(this->_host.c_str());
  this->_sock = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  connect(this->_sock, (struct sockaddr *)&s_in, sizeof(s_in));

  gnl gl(this->_sock);
  while (1)
    {
      FD_ZERO(&fd_read);
      FD_SET(this->_sock, &fd_read);
      if (gl.getbuffer() != "")
	req = gl.get_next_line();
      else if ((a = select(this->_sock + 1, &fd_read, NULL, NULL, NULL)) != -1)
        {
          if (FD_ISSET(this->_sock, &fd_read))
	    {
	      req = gl.get_next_line();
	      if (req == "BIENVENUE")
		write(this->_sock, "GRAPHIC\n", 8);
	    }
	}
      std::cout << req << std::endl;

    }
}

std::string		Network::recup_firstPart(std::string &data)
{
  int			i = 0;
  std::string		param = "";
  bool			trouve = false;

  while (i < data.size() && trouve == false)
    {
      while (data[i] != ' ' && data[i] != '\n' && data[i])
	{
	  param += data[i];
	  trouve = true;
	  i++;
	}
      i++;
    }
  return param;
}

void			Network::checkData()
{

}

std::vector<std::string>	Network::recup_sizeMap(std::string &data)
{
  int			i = 4;
  std::string		coordX = "";
  std::string		coordY = "";
  std::vector<std::string>	list;

  while (i < data.size())
    {
      while (data[i] != ' ')
	{
	  coordX += data[i];
	  i++;
	}
      i++;
      while (i < data.size())
	{
	  coordY += data[i];
	  i++;
	}
      this->_tailleX = coordX;
      this->_tailleY = coordY;
    }
  std::cout << "X: " << coordX << "\tY: " << coordY << std::endl;
  list.push_back(coordX);
  list.push_back(coordY);
  return list;
}

std::string		Network::askForTimeUnit(std::string &data)
{
  int			i = 4;
  std::string		chaine = "";

  while (i < data.size())
    {
      chaine += data[i];
      i++;
    }
  return chaine;
}

Network::~Network()
{
}
