//
// Network.hpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu Jul  4 12:01:16 2013 gery baudry
// Last update Mon Jul 15 20:18:00 2013 gery baudry
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
#include	"Message.hpp"

#include				"get_next_line.hpp"

#define		MAX	18

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
  std::vector<std::string>		_sgt;
  std::vector<std::vector<int> >	_carte;
  std::vector<std::string>		_playerInfos;
  void					 (Network::*ptr_func[MAX])(std::string &req);
  Memory				*_mem;
  Message				mess;


public:
  Network(const std::string &, int, const std::string &);
  virtual ~Network();
  int					getPort() const;
  int					getSock() const;
  std::string				getHost() const;
  std::string				getTeam() const;
  Memory				getMem() const;
  Message				getMess() const;
  int					getTailleX() const;
  int					getTailleY() const;
  std::vector<std::vector<int> >	getCarte() const;
  std::vector<std::string>		getPlayerInfos() const;
  void					initConnexion();
  void					doLoop(gnl &);
  std::string				recup_firstPart(std::string &data);
  void					checkData(std::string &data);
  void					checkData2(std::string &data);
  void					checkData3(std::string &data);
  std::vector<int>			recup_sizeMap(std::string &data);
  std::vector<int>			recup_mapContent(std::string &data);
  std::vector<int>			recup_caseContent(int y, int x);
  void					recup_teamName(std::string &data);
  void					recup_playerInfos(std::string &data);
  void					recup_playerPosition(int idPlayer);
  void					recup_playerLevel(int idPlayer);
  void					recup_playerInventaire(int idPlayer);
  void					askForTimeUnit(std::string &data);
  void					setTimeUnit(int timeValue);
  void					playerExpulse(std::string &data);
  void					playerBroadcast(std::string &data);
  void					launchIncantation(std::string &data);
  void					endOfIncantation(std::string &data);
  void					putAnEgg(std::string &data);
  void					dropARessource(std::string &data);
  void					takeARessource(std::string &data);
  void					hungryDead(std::string &data);
  void					eggPutByPlayer(std::string &data);
  void					eggHatched(std::string &data);
  void					playerConnectedForEgg(std::string &data);
  void					eggDied(std::string &data);
  void					endOfGame(std::string &data);
  void					serverMessage(std::string &data);
  void					unknownCommand();
  void					wrongParameters();
  void					init_ptr();
};

#endif
