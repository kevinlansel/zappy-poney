//
// Network.hpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu Jul  4 12:01:16 2013 gery baudry
// Last update Tue Jul 16 13:40:23 2013 florian dewulf
//

#ifndef			__NETWORK_HPP__
# define		__NETWORK_HPP__

#include		<sstream>
#include		<vector>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<arpa/inet.h>
#include		<netdb.h>
#include		<sys/select.h>
#include		<sys/time.h>
#include		<sys/types.h>
#include		<unistd.h>
#include		"Memory.hpp"
#include		"get_next_line.hpp"
#include		"Except.hpp"

class			Network
{
private:
  std::string		_host;
  int			_port;
  std::string		_team;
  int			_sock;
  int			_binary;

public:
  Network(const std::string &, int, const std::string &);
  virtual		~Network();
  int			getPort() const;
  int			getSock() const;
  std::string		getHost() const;
  std::string		getTeam() const;
  void			initConnexion();
  bool			init(const gnl &);
  bool			initConnexion(const std::string &);
  bool			checkBinary() const;
};

#endif
