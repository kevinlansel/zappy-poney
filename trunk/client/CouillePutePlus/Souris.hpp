//
// Mouse.hpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon Jul  1 15:59:10 2013 gery baudry
// Last update Tue Jul  2 13:32:28 2013 gery baudry
//

#ifndef		SOURIS__
# define	SOURIS__

#include	<SFML/Window.hpp>
#include	"Windows.hpp"

class		Souris
{
public:
  Souris();
  ~Souris();

public:
  sf::Vector2i		getPosition() const;
  void			setPosition(sf::RenderWindow &);
  sf::Vector2i		CheckSouris(sf::RenderWindow &, std::vector<Case> &, int, int);

public:
  sf::Vector2i		_position;
  bool			_toto;
};

#endif
