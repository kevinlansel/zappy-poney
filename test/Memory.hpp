//
// Memory.hpp<2> for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Tue Jul 16 00:27:16 2013 florian dewulf
// Last update Tue Jul 16 22:25:51 2013 gery baudry
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

# define	RES_X	800
# define	RES_Y	600

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
  void				close();
  bool				pool(sf::Event &);

  template<typename T>
  void				push(int type, T ptr)
  {
    if (type == 0)
      this->_player.push_back(reinterpret_cast<Player *>(ptr));
    else if (type == 1)
      this->_oeuf.push_back(reinterpret_cast<Oeuf *>(ptr));
    else if (type == 2)
      this->_team.push_back(*(reinterpret_cast<std::string *>(ptr)));
  }

  void				modifCase(int, Case *);
  void				modiflastCase(Case *);

public:
  void				clear_win();
  void				display_win();
  void				drawCase();
  void				drawPlayer();
  void				drawOeuf();
  void				loadText(const std::string &);
  void				printText();

private:
  sf::RenderWindow			_win;
  float					_sizex;
  float					_sizey;
  sf::Font				_font;
  std::list<std::string>		_team;
  std::vector<std::vector<Case *> >	_case;
  std::list<Oeuf *>			_oeuf;
  std::list<Player *>			_player;
  std::map<int, sf::Texture>		_lvlsprite;
  sf::Text				_txt;
};

#endif
