//
// Network.hpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu Jul  4 12:01:16 2013 gery baudry
// Last update Fri Jul 12 14:50:16 2013 guillaume duez
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
  void (Network::*ptr_func[MAX])(std::string req);

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
  std::vector<std::string>		getPlayerInfos() const;
  void					initConnexion();
  void					doLoop(gnl &);
  std::string				recup_firstPart(std::string &data);
  std::vector<int>			checkData(std::string &data);
  std::vector<std::string>		checkData2(std::string &data);
  void					checkData3(std::string &data);
  std::vector<int>			recup_sizeMap(std::string &data);
  std::vector<int>			recup_mapContent(std::string &data);
  std::vector<int>			recup_caseContent(int y, int x);
  std::vector<std::string>		recup_teamName(std::string &data);
  std::vector<std::string>		recup_playerInfos(std::string &data);
  void					recup_playerPosition(int idPlayer);
  void					recup_playerLevel(int idPlayer);
  void					recup_playerInventaire(int idPlayer);
  std::vector<std::string>		askForTimeUnit(std::string &data);
  void					setTimeUnit(int timeValue);
  std::vector<std::string>		playerExpulse(std::string &data);
  std::vector<std::string>		playerBroadcast(std::string &data);
  std::vector<std::string>		launchIncantation(std::string &data);
  std::vector<std::string>		endOfIncantation(std::string &data);
  std::vector<std::string>		putAnEgg(std::string &data);
  std::vector<std::string>		dropARessource(std::string &data);
  std::vector<std::string>		takeARessource(std::string &data);
  std::vector<std::string>		hungryDead(std::string &data);
  std::vector<std::string>		eggPutByPlayer(std::string &data);
  std::vector<std::string>		eggHatched(std::string &data);
  std::vector<std::string>		playerConnectedForEgg(std::string &data);
  std::vector<std::string>		eggDied(std::string &data);
  std::vector<std::string>		endOfGame(std::string &data);
  std::vector<std::string>		serverMessage(std::string &data);
  void					unknownCommand();
  void					wrongParameters();
  void					init_ptr();
};

#endif
