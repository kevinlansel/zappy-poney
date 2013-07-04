//
// Network.cpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu Jul  4 12:01:21 2013 gery baudry
// Last update Thu Jul  4 12:09:26 2013 gery baudry
//

#include	"Network.hpp"

Network::Network(const std::string &host, int port, const std::string &team):
  _host(host), _port(port), _team(team)
{
  this->_kill = 0;
  this->_tailleX = 0;
  this->_tailleY = 0;
}

int		Network::getPort() const
{
  return (this->_port);
}

int		Network::getSock() const
{
  return (this->_sock);
}

std::string	Network::getHost() const
{
  return (this->_host);
}

int		Network::getTailleX() const
{
  return (this->_tailleX);
}

int		Network::getTailleY() const
{
  return (this->_tailleY);
}

std::vector<std::vector<int> >	Network::getCarte() const
{
  return (this->_carte);
}

void		Network::initConnexion()
{
  struct sockaddr_in	s_in;
  struct protoent	*pe;

  pe = getprotobyname("TCP");
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(this->_port);
  s_in.sin_addr.s_addr = inet_addr(this->_host.c_str());
  this->_sock = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  connect(this->_sock, (struct sockaddr *)&s_in, sizeof(s_in));
}

void			Network::doLoop()
{
  fd_set		fd_read;
  char			buff[4096];
  int			a;
  std::string		req = "";
  std::vector<int>	list;
  int			x;
  int			y;
  gnl gl(this->_sock);
  int			cpt = 0;

  while (cpt < 2)
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
	      else if (recup_firstPart(req) == "msz")
		{
		  list = recup_sizeMap(req);
		  x = list.front();
		  y = list.back();
		  if (x == 0 || y == 0)
		    {
		      std::cout << "Taille de la map incorrecte:\nTaille en X: " << x << "\nTaille en Y: " << y << std::endl;
		      close(this->_sock);
		      exit(-1);
		    }
		}
	    }
	}
      // std::cout << req << std::endl;
      cpt++;
    }
  cpt = 0;
  req = "";
  // std::cout << "-----------------------" << std::endl;
  while (cpt < x * y + 1)
    {
      FD_ZERO(&fd_read);
      FD_SET(this->_sock, &fd_read);
      if (gl.getbuffer() != "")
	{
	  req = gl.get_next_line();
	  this->_carte.push_back(recup_mapContent(req));
	}
      else if ((a = select(this->_sock + 1, &fd_read, NULL, NULL, NULL)) != -1)
        {
	  if (FD_ISSET(this->_sock, &fd_read))
	    {
	      req = gl.get_next_line();
	      if (recup_firstPart(req) == "sgt")
		this->_sgt = askForTimeUnit(req);
	    }
	}
      cpt++;
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

void			Network::checkData(std::string &data)
{
  std::string		word;

  word = recup_firstPart(data);
  if (word == "msz")
    recup_sizeMap(data);
  else if (word == "bct")
    recup_mapContent(data);
  else if (word == "tna")
    recup_teamName(data);
  else if (word == "sgt")
    askForTimeUnit(data);
  else
    std::cout << "Unknown Command" << std::endl;
}

std::vector<int>	Network::recup_sizeMap(std::string &data)
{
  int			i = 4;
  std::string		coordX = "";
  std::string		coordY = "";
  std::vector<int>	list;
  int			x;
  int			y;

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
      std::istringstream buffer(coordX);
      std::istringstream buffer2(coordY);
      buffer >> x;
      buffer2 >> y;
      this->_tailleX = x;
      this->_tailleY = y;
    }
  //  std::cout << "X: " << coordX << "\tY: " << coordY << std::endl;
  list.push_back(x);
  list.push_back(y);
  return list;
}

std::vector<int>	Network::recup_mapContent(std::string &data)
{
  int				idMax;
  std::vector<int>	s2;
  int				i = 4;
  int				cpt = 0;
  int				ressource;
  std::string			ress = "";

  while (i < data.size())
    {
      if (data[i] == ' ')
	{
	  if (cpt == 2)
	    {
	      std::istringstream ss(ress);
	      ss >> ressource;
	      s2.push_back(ressource);
	      ress = "";
	    }
	  else
	    cpt++;
	}
      else
	{
	  if (cpt == 2)
	    ress += data[i];
	}
      i++;
    }
  // for (std::vector<int>::iterator it = s2.begin(); it != s2.end(); ++it)
  //   std::cout << *it;
  // std::cout << std::endl;
  return (s2);
}

std::vector<std::string>	Network::recup_caseContent(int y, int x)
{
  std::string			posX;
  std::string			posY;
  std::string			chaine;
  std::string			ress = "";
  std::vector<std::string>	list;
  char				*data;
  std::string			data2;
  int				i = 4;
  std::ostringstream		posy;
  std::ostringstream		posx;

  posy << y;
  posx << x;
  posY = posy.str();
  posX = posx.str();
  chaine = "bct " + posX + " " + posY + "\n";
  write(this->_sock, chaine.c_str(), chaine.size());
  read(this->_sock, data, 1024);
  data2 = (std::string)data;
  while (i < data2.size())
    {
      if (data2[i] == ' ' || i+1 == data2.size())
	{
	  list.push_back(ress);
	  ress = "";
	}
      else
	ress += data2[i];
      i++;
    }
  return (list);
}

std::string		Network::recup_teamName(std::string &data)
{
  std::string		team = "";
  int			i = 4;

  while (i < data.size())
    {
      while (data[i] != '\n' && data[i])
	{
	  team += data[i];
	  i++;
	}
      i++;
    }
}

std::vector<std::string>	Network::recup_playerPosition(int idPlayer)
{
  std::string		chaine;
  char			*data;
  std::string		data2;
  int			i = 7;
  std::vector<std::string>	list;
  std::string		ress = "";
  std::ostringstream	idp;

  idp << idPlayer;
  chaine = "ppo #" + idp.str() + "\n";
  write(this->_sock, chaine.c_str(), chaine.size());
  read(this->_sock, data, 2048);
  data2 = (std::string)data;
  while (i < data2.size() && data2[i] != '\n')
    {
      if (data2[i] == ' ')
	{
	  list.push_back(ress);
	  ress = "";
	}
      else
	ress += data2[i];
      i++;
    }
  return list;
}

std::string		Network::recup_playerLevel(int idPlayer)
{
  std::string		chaine;
  char			*data;
  std::string		data2;
  int			i = 7;
  std::string		ress = "";
  std::ostringstream	idp;

  idp << idPlayer;
  chaine = "plv #" + idp.str() + "\n";
  write(this->_sock, chaine.c_str(), chaine.size());
  read(this->_sock, data, 2048);
  data2 = (std::string)data;
  while (i < data2.size() && data2[i] != '\n')
    {
      ress += data2[i];
      i++;
    }
  return ress;
}

std::vector<std::string>	Network::recup_playerInventaire(int idPlayer)
{
  std::string		chaine;
  char			*data;
  std::string		data2;
  int			i = 7;
  std::vector<std::string>	list;
  std::string		ress = "";
  std::ostringstream	idp;

  idp << idPlayer;
  chaine = "pin #" + idp.str() + "\n";
  write(this->_sock, chaine.c_str(), chaine.size());
  read(this->_sock, data, 2048);
  data2 = (std::string)data;
  while (i < data2.size() && data2[i] != '\n')
    {
      if (data2[i] == ' ')
	{
	  list.push_back(ress);
	  ress = "";
	}
      else
	ress += data2[i];
      i++;
    }
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

void			Network::setTimeUnit(int timeValue)
{
  std::string		chaine;
  std::ostringstream	tv;

  tv << timeValue;
  chaine = "sst " + tv.str() + "\n";
  write(this->_sock, chaine.c_str(), chaine.size());
}

Network::~Network()
{
}
