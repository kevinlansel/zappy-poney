//
// Network.hpp for  in /home/lund/Projets/zappy-poney/client/ia
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Mon Jul 15 17:11:03 2013 florian dewulf
// Last update Mon Jul 15 19:12:38 2013 kevin lansel
//

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
  //  std::string	communicate(std::string &);
  int		getPort() const;
  int		getSock() const;
  std::string	getHost() const;
};

#endif
