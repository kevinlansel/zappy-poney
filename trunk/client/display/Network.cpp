//
// Network.cpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu Jul  4 12:01:21 2013 gery baudry
// Last update Mon Jul 15 13:16:36 2013 gery baudry
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

std::string	Network::getTeam() const
{
  return (this->_team);
}

std::vector<std::string>	Network::getPlayerInfos() const
{
  return (this->_playerInfos);
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

void			Network::doLoop(gnl &gl)
{
  fd_set		fd_read;
  int			a;
  std::string		req = "";
  std::vector<int>	list;
  int			x;
  int			y;
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
      cpt++;
    }
  cpt = 0;
  req = "";
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
  this->_carte.erase(this->_carte.begin());
}

std::string		Network::recup_firstPart(std::string &data)
{
  unsigned int		i = 0;
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

void            Network::init_ptr()
{
  this->ptr_func[0] = (&Network::recup_teamName);
  this->ptr_func[1] = (&Network::askForTimeUnit);
  this->ptr_func[2] = (&Network::recup_playerInfos);
  this->ptr_func[3] = (&Network::playerExpulse);
  this->ptr_func[4] = (&Network::playerBroadcast);
  this->ptr_func[5] = (&Network::launchIncantation);
  this->ptr_func[6] = (&Network::endOfIncantation);
  this->ptr_func[7] = (&Network::putAnEgg);
  this->ptr_func[8] = (&Network::dropARessource);
  this->ptr_func[9] = (&Network::takeARessource);
  this->ptr_func[10] = (&Network::hungryDead);
  this->ptr_func[11] = (&Network::eggPutByPlayer);
  this->ptr_func[12] = (&Network::eggHatched);
  this->ptr_func[13] = (&Network::playerConnectedForEgg);
  this->ptr_func[14] = (&Network::eggDied);
  this->ptr_func[15] = (&Network::endOfGame);
  this->ptr_func[16] = (&Network::serverMessage);
}

std::vector<std::string>			Network::checkData2(std::string &data)
{
  std::string		word;
  std::vector<std::string>	list;
  int           i;
  static char   str[MAX][5] = { "tna", "sgt", "pnw", "pex",
				"pbc", "pic", "pie", "pfk", "pdr",
				"pgt", "pdi", "enw", "eht", "ebo",
				"edi", "seg", "smg"};

  word = recup_firstPart(data);
  init_ptr();
  i = 0;
  while (i < MAX)
    {
      if (word.c_str() == str[i])
        list = (this->*ptr_func[i]) (data);
      i++;
    }
  return list;
}

void			Network::checkData3(std::string &data)
{
  std::string		word;

  word = recup_firstPart(data);
  if (word == "suc")
    {
      std::cout << "suc" << std::endl;
      unknownCommand();
    }
  else if (word == "spb")
    {
      std::cout << "spb" << std::endl;
      wrongParameters();
    }
}

std::vector<int>			Network::checkData(std::string &data)
{
  std::string		word;
  std::vector<int>	list;

  word = recup_firstPart(data);
  if (word == "msz")
    {
      std::cout << "msz" << std::endl;
      list = recup_sizeMap(data);
    }
  else if (word == "bct")
    {
      std::cout << "bct" << std::endl;
      list = recup_mapContent(data);
    }
  return list;
}

std::vector<int>	Network::recup_sizeMap(std::string &data)
{
  unsigned int		i = 4;
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
  list.push_back(x);
  list.push_back(y);
  return list;
}

std::vector<int>		Network::recup_mapContent(std::string &data)
{
  std::vector<int>		s2;
  unsigned int			i = 0;
  unsigned int			cpt = 0;
  int				ressource;
  std::string			ress = "";

  while (i <= data.size())
    {
      if (data[i] != ' ' && data[i] != '\0')
	{
	  if (cpt == 3)
	    ress += data[i];
	}
      else
	{
	  if (cpt == 3)
	    {
	      if (ress != "")
		{
		  std::istringstream ss(ress);
		  ss >> ressource;
		  s2.push_back(ressource);
		  ress = "";
		}
	    }
	  else
	    cpt++;
	}
      i++;
    }
  return (s2);
}

std::vector<std::string>	Network::playerExpulse(std::string &data)
{
  unsigned int		i = 5;
  std::string	res = "";
  std::vector<std::string>	list;

  while (i < data.size() && data[i] != '\n')
    {
      res += data[i];
      i++;
    }
  list.push_back(res);
  return list;
}

std::vector<std::string>	Network::playerBroadcast(std::string &data)
{
  unsigned int		i = 5;
  std::vector<std::string>	list;
  std::string	res = "";

  while (data[i] != ' ')
    {
      res += data[i];
      i++;
    }
  list.push_back(res);
  res = "";
  i++;
  while (data[i] != '\n' && i < data.size())
    {
      res += data[i];
      i++;
    }
  list.push_back(res);
  return list;
}

std::vector<std::string>	Network::launchIncantation(std::string &data)
{
  unsigned int		i = 4;
  std::string		res = "";
  std::vector<std::string>	list;
  unsigned int		cpt = 0;

  while (cpt < 3)
    {
      while (data[i] != ' ')
	{
	  res += data[i];
	  i++;
	}
      list.push_back(res);
      res = "";
      i++;
      cpt++;
    }
  while (i < data.size() && data[i] != '\n')
    {
      if (data[i] == '#')
	{
	  i++;
	  while (data[i] != ' ' && data[i] != '\n')
	    {
	      res += data[i];
	      i++;
	    }
	  list.push_back(res);
	  res = "";
	}
      else
	i++;
    }
  return list;
}

std::vector<std::string>	Network::endOfIncantation(std::string &data)
{
  std::string		res = "";
  std::vector<std::string>	list;
  unsigned int		i = 4;
  unsigned int		cpt = 0;

  while (cpt < 3)
    {
      while (data[i] != ' ' && data[i] != '\n' && i < data.size())
	{
	  res += data[i];
	  i++;
	}
      list.push_back(res);
      res = "";
      i++;
      cpt++;
    }
  return list;
}

std::vector<std::string>		Network::putAnEgg(std::string &data)
{
  unsigned int		i = 5;
  std::string	res = "";
  std::vector<std::string>	list;

  while (i < data.size())
    {
      res += data[i];
      i++;
    }
  list.push_back(res);
  return list;
}

std::vector<std::string>		Network::dropARessource(std::string &data)
{
  unsigned int	i = 5;
  std::string	res = "";
  std::vector<std::string>	list;

  while (i < data.size())
    {
      res += data[i];
      i++;
    }
  i++;
  list.push_back(res);
  res = "";
  while (i < data.size())
    {
      res += data[i];
      i++;
    }
  list.push_back(res);
  res = "";
  return list;
}

std::vector<std::string>		Network::takeARessource(std::string &data)
{
  unsigned int	i = 5;
  std::string	res = "";
  std::vector<std::string>	list;

  while (i < data.size())
    {
      res += data[i];
      i++;
    }
  i++;
  list.push_back(res);
  res = "";
  while (i < data.size())
    {
      res += data[i];
      i++;
    }
  list.push_back(res);
  res = "";
  return list;
}

std::vector<std::string>		Network::hungryDead(std::string &data)
{
  unsigned int	i = 5;
  std::string	res = "";
  std::vector<std::string>	list;

  while (i < data.size())
    {
      res += data[i];
      i++;
    }
  list.push_back(res);
  return list;
}

std::vector<std::string>		Network::eggPutByPlayer(std::string &data)
{
  unsigned int		i = 4;
  std::string		res = "";
  std::vector<std::string>	list;
  unsigned int		cpt = 0;

  while (cpt < 2)
    {
      if (data[i] == '#')
	{
	  while (data[i] != ' ')
	    {
	      res += data[i];
	      i++;
	    }
	  list.push_back(res);
	  res = "";
	  i++;
	  cpt++;
	}
    }
  while (i < data.size() && data[i] != '\n')
    {
      while (data[i] != ' ' && data[i] != '\n')
	{
	  res += data[i];
	  i++;
	}
      list.push_back(res);
      res = "";
      i++;
    }
  return list;
}

std::vector<std::string>		Network::eggHatched(std::string &data)
{
  unsigned int	i = 5;
  std::string	res = "";
  std::vector<std::string>	list;

  while (i < data.size())
    {
      res += data[i];
      i++;
    }
  list.push_back(res);
  return list;
}

std::vector<std::string>		Network::playerConnectedForEgg(std::string &data)
{
  unsigned int	i = 5;
  std::string	res = "";
  std::vector<std::string>	list;

  while (i < data.size())
    {
      res += data[i];
      i++;
    }
  list.push_back(res);
  return list;
}

std::vector<std::string>		Network::eggDied(std::string &data)
{
  unsigned int	i = 5;
  std::string	res = "";
  std::vector<std::string>	list;

  while (i < data.size())
    {
      res += data[i];
      i++;
    }
  list.push_back(res);
  return list;
}

std::vector<int>		Network::recup_caseContent(int y, int x)
{
  std::string			posX;
  std::string			posY;
  std::string			chaine;
  std::string			ress = "";
  std::vector<int>		list;
  char				data[1024];
  std::string			data2;
  unsigned int			i = 0;
  std::ostringstream		posy;
  std::ostringstream		posx;
  unsigned int			cpt = 0;
  int				ressource;

  posy << y;
  posx << x;
  posY = posy.str();
  posX = posx.str();
  chaine = "bct " + posX + " " + posY + "\n";
  write(this->_sock, chaine.c_str(), chaine.size());
  read(this->_sock, data, 1024);
  data2 = (std::string)data;
  while (i <= data2.size() && data2[i] != '\n')
    {
      if (data2[i] != ' ' && data[i] != '\0')
	{
	  if (cpt == 3)
	    ress += data[i];
	}
      else
	{
	  if (cpt == 3)
	    {
	      if (ress != "")
		{
		  std::istringstream ss(ress);
		  ss >> ressource;
		  list.push_back(ressource);
		  ress = "";
		}
	    }
	  else
	    cpt++;
	}
      i++;
    }
  return (list);
}

std::vector<std::string>	Network::recup_teamName(std::string &data)
{
  std::string		team = "";
  unsigned int		i = 4;
  std::vector<std::string>	list;

  while (i < data.size())
    {
      while (data[i] != '\n' && data[i])
	{
	  team += data[i];
	  i++;
	}
      i++;
    }
  list.push_back(team);
  return list;
}

std::vector<std::string>	Network::recup_playerInfos(std::string &data)
{
  unsigned int		i = 5;
  std::string		s = "";
  std::vector<std::string>	tmp;

  while (i < data.size())
    {
      while (data[i] != ' ' && i < data.size() && data[i] != '\n')
	{
	  s += data[i];
	  i++;
	}
      if (data[i] == ' ' || data[i] == '\n' || i == data.size())
	{
	  tmp.push_back(s);
	  s = "";
	  i++;
	}
    }
  this->_playerInfos = tmp;
  return tmp;
}

void	Network::recup_playerPosition(int idPlayer)
{
  std::string		chaine;
  char			data[2048];
  std::string		data2;
  unsigned int		i = 5;
  std::string		s = "";
  std::ostringstream	idp;
  unsigned int		j = 1;
  unsigned int		cpt = 0;

  idp << idPlayer;
  chaine = "ppo #" + idp.str() + "\n";
  write(this->_sock, chaine.c_str(), chaine.size());
  read(this->_sock, data, 2048);
  data2 = (std::string)data;
  while (i < data2.size())
    {
      if (cpt == 1)
	{
	  while (data2[i] != ' ' && i < data2.size() && data2[i] != '\n')
	    {
	      s += data2[i];
	      i++;
	    }
	  if (data2[i] == ' ' || data2[i] == '\n' || i == data2.size())
	    {
	      this->_playerInfos[j] = s;
	      s = "";
	      i++;
	      j++;
	    }
	}
      else
	{
	  if (data2[i] == ' ')
	    cpt++;
	  i++;
	}
    }
}

void	Network::recup_playerLevel(int idPlayer)
{
  std::string		chaine;
  char			data[2048];
  std::string		data2;
  std::string		s = "";
  std::ostringstream	idp;
  unsigned int		i = 5;
  unsigned int		cpt = 0;
  bool			trouve = false;

  idp << idPlayer;
  chaine = "plv #" + idp.str() + "\n";
  write(this->_sock, chaine.c_str(), chaine.size());
  read(this->_sock, data, 2048);
  data2 = (std::string)data;
  while (i < data2.size() && trouve == false)
    {
      if (cpt == 1)
	{
	  while (data2[i] != ' ' && i < data2.size() && data2[i] != '\n')
	    {
	      s += data2[i];
	      i++;
	    }
	  if (data2[i] == ' ' || data2[i] == '\n' || i == data2.size())
	    {
	      this->_playerInfos[3] = s;
	      s = "";
	      trouve = true;
	      i++;
	    }
	}
      else
	{
	  if (data2[i] == ' ')
	    cpt++;
	  i++;
	}
    }
}

void       Network::recup_playerInventaire(int idPlayer)
{
  std::string		chaine;
  char			data[2048];
  std::string		data2;
  unsigned int		i = 5;
  unsigned int		cpt = 0;
  std::string		s = "";
  std::ostringstream	idp;

  idp << idPlayer;
  chaine = "pin #" + idp.str() + "\n";
  write(this->_sock, chaine.c_str(), chaine.size());
  read(this->_sock, data, 2048);
  data2 = (std::string)data;
  while (i < data2.size())
    {
      if (cpt == 3)
	{
	  while (data2[i] != ' ' && i < data2.size() && data2[i] != '\n')
	    {
	      s += data2[i];
	      i++;
	    }
	  if (data2[i] == ' ' || data2[i] == '\n' || i == data2.size())
	    {
	      this->_playerInfos.push_back(s);
	      s = "";
	      i++;
	    }
	}
      else
	{
	  if (data2[i] == ' ')
	    cpt++;
	  i++;
	}
    }
}

std::vector<std::string>	Network::askForTimeUnit(std::string &data)
{
  unsigned int		i = 4;
  std::string		chaine = "";
  std::vector<std::string>	list;

  while (i < data.size())
    {
      chaine += data[i];
      i++;
    }
  list.push_back(chaine);
  return list;
}

void			Network::setTimeUnit(int timeValue)
{
  std::string		chaine;
  std::ostringstream	tv;

  tv << timeValue;
  chaine = "sst " + tv.str() + "\n";
  write(this->_sock, chaine.c_str(), chaine.size());
}

std::vector<std::string>	Network::endOfGame(std::string &data)
{
  unsigned int	i = 5;
  std::string	res = "";
  std::vector<std::string>	list;

  while (i < data.size())
    {
      res += data[i];
      i++;
    }
  list.push_back(res);
  return list;
}

std::vector<std::string>		Network::serverMessage(std::string &data)
{
  unsigned int	i = 5;
  std::string	res = "";
  std::vector<std::string>	list;

  while (i < data.size())
    {
      res += data[i];
      i++;
    }
  list.push_back(res);
  return list;
}

void		Network::unknownCommand()
{
  std::cout << "Unknown Command" << std::endl;
}

void		Network::wrongParameters()
{
  std::cout << "Wrong Parameters" << std::endl;
}

Network::~Network()
{
}
