#ifndef				__NETWORK_HH__
#define				__NETWORK_HH__

#include			<string>
#include			<iostream>
#include			<fstream>
#include			<cstring>
#include			<sys/types.h>
#include			<sys/socket.h>
#include			<sys/select.h>
#include			<netdb.h>
#include			<arpa/inet.h>
#include			<netinet/in.h>
#include			<unistd.h>
#include			<vector>
#include			<sstream>

#include			"get_next_line.hpp"
#include			"Windows.hh"

class				Network
{
private:
  int				_port;
  int				_team;
  int				_kill;
  int				_sock;
  std::string			_host;
  int				_tailleX;
  int				_tailleY;

public:
  Network(std::string &, int, int);
  virtual ~Network();
  void				doLoop();
  int				getPort() const;
  int				getSock() const;
  std::string			getHost() const;
  void				initConnexion();
  std::string			recup_firstPart(std::string &data);
  void				checkData(std::string &data);
  std::vector<int>		recup_sizeMap(std::string &data);
  std::string			askForTimeUnit(std::string &data);
  std::vector<std::string>	recup_mapContent(std::string &data);
  std::vector<std::string>	recup_caseContent(int y, int x);
  std::string			recup_teamName(std::string &data);
  std::vector<std::string>	recup_playerPosition(int idPlayer);
  std::string			recup_playerLevel(int idPlayer);
  std::vector<std::string>	recup_playerInventaire(int idPlayer);
  void				setTimeUnit(int timeValue);
};

#endif
