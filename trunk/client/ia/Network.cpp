#include	"Network.hpp"

Network::Network(const std::string &host, int port, const std::string &team):
  _host(host), _port(port), _team(team)
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

std::string		Network::communicate(std::string &data)
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
  std::string		data2;

  while (1)
    {
      FD_ZERO(&fd_read);
      FD_SET(this->_sock, &fd_read);
      if (gl.getbuffer() != "")
	req = gl.get_next_line();
      else if ((a = select(this->_sock + 1, &fd_read, NULL, NULL, NULL)) != -1)
        {
	  if (data != NULL)
	    {
	      data2 = data + "\n";
	      write(this->_sock, data2.c_str(), data2.size());
	    }
	  if (FD_ISSET(this->_sock, &fd_read))
	    {
	      req = gl.get_next_line();
	      return req;
	    }
	}
    }
  return NULL;
}

Network::~Network()
{
}
