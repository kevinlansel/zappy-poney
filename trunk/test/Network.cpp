//
// Network.cpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu Jul  4 12:01:21 2013 gery baudry
// Last update Tue Jul 16 15:39:21 2013 florian dewulf
//

#include	"Network.hpp"

Network::Network(const std::string &host, int port, const std::string &team) : _host(host), _port(port), _team(team), _sock(0), _binary(0)
{
}

Network::~Network()
{
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

std::string	Network::getTeam() const
{
  return (this->_team);
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
  if (connect(this->_sock, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      close(this->_sock);
      throw Except("Probleme lors de la connexion");
    }
}

bool			Network::init(const gnl &gl)
{
  fd_set		fd_read;
  int			a;
  struct timeval	tv;

  tv.tv_sec = 0;
  tv.tv_usec = 1000;
  FD_ZERO(&fd_read);
  FD_SET(this->_sock, &fd_read);
  if (gl.getbuffer() != "")
    return (true);
  else if ((a = select(this->_sock + 1, &fd_read, NULL, NULL, &tv)) != -1)
    if (FD_ISSET(this->_sock, &fd_read))
      return (true);
  return (false);
}

bool		Network::initConnexion(const std::string &str)
{
  std::cout << "str = " << str << std::endl;
  if (str == "BIENVENUE")
    {
      this->_binary = this->_binary | 0x001;
      std::cout << "GRAPHIC SEND" << std::endl;
      write(this->_sock, "GRAPHIC\n", 8);
      return (false);
    }
  else if (str == "msz")
    {
      this->_binary = this->_binary | 0x010;
      return (true);
    }
  else if (str.find("bct") == 0)
    {
      this->_binary = this->_binary | 0x100;
      return (true);
    }
  return (true);
}

bool		Network::checkBinary() const
{
  std::cout << this->_binary << std::endl;
  if ((this->_binary & 0x111) == 0x111)
    return (true);
  return (false);
}
