//
// Interpret.hpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Tue Jul 16 14:41:03 2013 florian dewulf
// Last update Tue Jul 16 14:50:21 2013 florian dewulf
//

#ifndef		INTERPRET_HPP__
# define	INTERPRET_HPP__

#include	<string>
#include	<vector>
#include	<list>
#include	"Memory.hpp"
#include	"Oeuf.hpp"
#include	"Player.hpp"

class		Interpret
{
public:
  Interpret() {};
  virtual	~Interpret() {};
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
  void		setVec(const std::vector<std::string> &);

private:
  std::vector<std::string>	vec;
};

#endif
