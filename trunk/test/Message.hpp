//
// Message.hpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Mon Jul 15 23:16:18 2013 florian dewulf
// Last update Tue Jul 16 14:22:48 2013 florian dewulf
//

#ifndef		MESSAGE_HPP__
# define	MESSAGE_HPP__

#include	<sstream>
#include	<string>
#include	<vector>
#include	"Memory.hpp"
#include	"Oeuf.hpp"

class		Message
{
public:
  Message();
  virtual	~Message();
  void		init();
  bool		work(const std::string &, Memory *);

private:
  bool		setSizeMap(Memory *);
  bool		setCaseContent(Memory *);
  bool		addTeamName(Memory *);
  bool		newPlayer(Memory *);
  bool		setPosPlayer(Memory *);
  bool		setLvlPlayer(Memory *);
  bool		setInvPlayer(Memory *);
  bool		expulsePlayer(Memory *);
  bool		broadcastPlayer(Memory *);
  bool		beginIncant(Memory *);
  bool		endIncant(Memory *);
  bool		eggPop(Memory *);
  bool		dropRess(Memory *);
  bool		takeRess(Memory *);
  bool		dead(Memory *);
  bool		eggOnCase(Memory *);
  bool		eggSpawn(Memory *);
  bool		eggConnexion(Memory *);
  bool		eggDead(Memory *);
  bool		setTime(Memory *);
  bool		endGame(Memory *);

private:
  std::map<std::string, int>	pattern;
  std::map<std::string, bool (Message::*)(Memory *)>	ptr;
  std::vector<std::string>	vec;
};

#endif
