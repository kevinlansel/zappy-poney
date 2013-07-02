//
// Font.hpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Fri Jun 28 17:41:23 2013 gery baudry
// Last update Fri Jun 28 17:49:48 2013 gery baudry
//

#ifndef		FONT__
# define	FONT__

#include	<SFML/Graphics.hpp>

class		Font
{
public:
  Font(sf::Text, int);
  ~Font();

public:
  sf::Font	_Font;
  std::string	_Text
  int		_Size;
};

#endif
