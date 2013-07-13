//
// Mouse.hpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon Jul  1 15:59:10 2013 gery baudry
// Last update Sat Jul 13 17:19:47 2013 gery baudry
//

#ifndef		SOURIS__
# define	SOURIS__

#include	<SFML/Window.hpp>
#include	"Player.hpp"
#include	"Windows.hpp"

class		Souris
{
public:
  Souris(Memory *);
  virtual		~Souris();

public:
  sf::Vector2<int>	getPosition() const;
  void			setPosition(sf::RenderWindow &);
  void			CheckSouris(sf::RenderWindow &, std::vector<Case>, int, int, sf::Vector2f taille);
  sf::Text		getTextcase() const;
  sf::Text		getTextplayer() const;

public:
  sf::Vector2<int>	_position;
  bool			_check;
  Memory		*_mem;
  sf::Font		font;
  sf::Text		textcase;
  sf::Text		textplayer;
};

#endif
