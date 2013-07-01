#ifndef		__NETWORK_HH__
#define		__NETWORK_HH__

#include	<string>
#include	<iostream>
#include	<fstream>
#include	<cstring>
#include        <sys/types.h>
#include        <sys/socket.h>
#include	<sys/select.h>
#include        <netdb.h>
#include        <arpa/inet.h>
#include        <netinet/in.h>
#include	<unistd.h>
#include	<vector>

#include	"get_next_line.hpp"

class		Network
{
public:
  int		_port;
  int		_team;
  int		_kill;
  int		_sock;
  std::string	_host;
  std::string	_tailleX;
  std::string	_tailleY;

  Network(std::string &, int, int);
  virtual ~Network();
  void			initConnexion();
  std::string		recup_firstPart(std::string &data);
  void			checkData();
  std::vector<std::string>	recup_sizeMap(std::string &data);
  std::string		askForTimeUnit(std::string &data);
};

#endif
