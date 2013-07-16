//
// Memory.hpp<2> for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Tue Jul 16 00:27:16 2013 florian dewulf
// Last update Tue Jul 16 15:50:22 2013 florian dewulf
//

#ifndef		MEMORY___
# define	MEMORY___

#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	<SFML/Window.hpp>
#include	<string>
#include	<list>
#include	<vector>
#include	<map>
#include	"Case.hpp"
#include	"Player.hpp"
#include	"Oeuf.hpp"
#include	"Except.hpp"

# define	RES_X	1280
# define	RES_Y	1024

class		Memory {
public:
  Memory();
  virtual	~Memory();

  std::list<Player *>		getPlayerlist() const;
  std::list<Oeuf *>		getOeuf() const;
  std::list<std::string>	getTeamlist() const;
  Case				*getCase(int, int) const;
  void				setSizeMap(int, int);
  int				getX() const;
  int				getY() const;

public:
  void				clear_win();
  void				display_win();
  void				drawCase();
  void				drawPlayer();
  void				drawOeuf();

private:
  sf::RenderWindow			_win;
  int					_sizex;
  int					_sizey;
  std::list<std::string>		_team;
  std::vector<std::vector<Case *> >	_case;
  std::list<Oeuf *>			_oeuf;
  std::list<Player *>			_player;
  std::map<int, sf::Texture>		_lvlsprite;
};

#endif
