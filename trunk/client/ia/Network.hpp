#ifndef		__NETWORK_HPP__
#define		__NETWORK_HPP__

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<arpa/inet.h>
#include	<netdb.h>
#include	<unistd.h>
#include	<cstdlib>
#include	<cstring>
#include	<cstdio>

#include	"get_next_line.hpp"

class		Network
{
private:
  std::string	_host;
  int		_port;
  std::string	_team;
  int		_sock;

public:
  Network(const std::string &, int, const std::string &);
  virtual ~Network();
  void		initConnexion();
  std::string	communicate(std::string &);
};

#endif
