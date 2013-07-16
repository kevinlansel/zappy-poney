//
// Player.hpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Tue Jul 16 01:07:42 2013 florian dewulf
// Last update Wed Jul 17 00:15:14 2013 gery baudry
//

#ifndef		PLAYER__
# define	PLAYER__

#include	<string>
#include	<vector>
#include	<sstream>
#include	"Case.hpp"

class		Player
{
public:
  Player(int, int, int, int, int, const std::string &);
  virtual		~Player();
  void			setCase(Case *);
  int			getId() const;
  int			getLvl() const;
  void			majPos(int, int, int);
  void			setLvl(int);
  void			majInv(int, int, int, int, int, int, int);
  int			getDirec() const;
  void			drop(int);
  void			take(int);
  std::vector<int>	getInventaire() const;
  int			getX() const;
  int			getY() const;
  std::string		doText();

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
