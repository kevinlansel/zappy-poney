#include	"Network.hh"

Network::Network()
{
  int	ip_addr;

  this->_host = "10.11.45.231";
  this->_team = 1;
  this->_kill = 0;
  this->_port = 4243;
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

Network::~Network()
{
}
