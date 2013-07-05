//
// Mouse.hpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon Jul  1 15:59:10 2013 gery baudry
// Last update Fri Jul  5 10:17:40 2013 gery baudry
//

#ifndef		SOURIS__
# define	SOURIS__

#include	<SFML/Window.hpp>
#include	"Windows.hpp"

class		Souris
{
public:
  Souris();
  virtual		~Souris();

public:
  sf::Vector2<int>	getPosition() const;
  void			setPosition(sf::RenderWindow &);
  sf::Text		CheckSouris(sf::RenderWindow &, std::vector<Case> &, int, int, sf::Vector2f);

public:
  sf::Vector2<int>	_position;
  bool			_check;
  sf::Font		font;
  sf::Text		text;
};

#endif
