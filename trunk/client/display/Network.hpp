//
// Network.hpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu Jul  4 12:01:16 2013 gery baudry
// Last update Thu Jul  4 12:01:41 2013 gery baudry
//

#ifndef					__NETWORK_HPP__
# define				__NETWORK_HPP__

#include				<sstream>
#include				<sys/types.h>
#include				<sys/socket.h>
#include				<arpa/inet.h>
#include				<netdb.h>
#include				<unistd.h>
#include				<cstdlib>
#include				<cstring>
#include				<cstdio>
#include				<vector>

#include				"get_next_line.hpp"

class					Network
{
private:
  std::string				_host;
  int					_port;
  std::string				_team;
  int					_sock;
  int					_kill;
  int					_tailleX;
  int					_tailleY;
  std::string				_sgt;
  std::vector<std::vector<int> >	_carte;
  std::vector<int>			_playerInfos;

public:
  Network(const std::string &, int, const std::string &);
  virtual ~Network();
  int					getPort() const;
  int					getSock() const;
  std::string				getHost() const;
  std::string				getTeam() const;
  int					getTailleX() const;
  int					getTailleY() const;
  std::vector<std::vector<int> >	getCarte() const;
  std::vector<int>			getPlayerInfos() const;
  void					initConnexion();
  void					doLoop();
  std::string				recup_firstPart(std::string &data);
  void					checkData(std::string &data);
  std::vector<int>			recup_sizeMap(std::string &data);
  std::vector<int>			recup_mapContent(std::string &data);
  std::vector<int>			recup_caseContent(int y, int x);
  std::string				recup_teamName(std::string &data);
  void					recup_playerInfos(std::string &data);
  void					recup_playerPosition(int idPlayer);
  void					recup_playerLevel(int idPlayer);
  void					recup_playerInventaire(int idPlayer);
  std::string				askForTimeUnit(std::string &data);
  void					setTimeUnit(int timeValue);
};

#endif
