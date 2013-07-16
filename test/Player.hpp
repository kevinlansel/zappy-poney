//
// Player.hpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Tue Jul 16 01:07:42 2013 florian dewulf
// Last update Tue Jul 16 11:46:58 2013 florian dewulf
//

#ifndef		PLAYER__
# define	PLAYER__

#include	<string>
#include	<vector>
#include	"Case.hpp"

class		Player
{
public:
  Player(int, int, int, int, int, const std::string &);
  virtual		~Player();
  void			setCase(const Case *);
  int			getId() const;
  int			getLvl() const;
  void			majPos(int, int, int);
  void			setLvl(int);
  void			majInv(int, int, int, int, int, int, int);
  int			getDirec() const;
  void			drop(int);
  void			take(int);
  std::vector<int>	getInventaire() const;

private:
  int		_id;
  int		x;
  int		y;
  int		dir;
  int		lvl;
  std::string	team;
  Case		*_case;
  int		ress[7];
};

#endif
