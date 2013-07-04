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

#include	"Windows.hpp"
#include	"get_next_line.hpp"

class		Network
{
private:
  std::string	_host;
  int		_port;
  std::string	_team;
  int		_sock;
  int		_kill;
  int		_tailleX;
  int		_tailleY;
  std::string	_sgt;
  std::vector<std::vector<int> >	_carte;

public:
  Network(const std::string &, int, const std::string &);
  virtual ~Network();
  int		getPort() const;
  int		getSock() const;
  std::string	getHost() const;
  int		getTailleX() const;
  int		getTailleY() const;
  void		initConnexion();
  void		doLoop();
  std::string		recup_firstPart(std::string &data);
  void			checkData(std::string &data);
  std::vector<int>	recup_sizeMap(std::string &data);
  std::vector<int>	recup_mapContent(std::string &data);
  std::vector<std::string>	recup_caseContent(int y, int x);
  std::string		recup_teamName(std::string &data);
  std::vector<std::string>	recup_playerPosition(int idPlayer);
  std::string		recup_playerLevel(int idPlayer);
  std::vector<std::string>	recup_playerInventaire(int idPlayer);
  std::string		askForTimeUnit(std::string &data);
  void			setTimeUnit(int timeValue);
};

#endif
