//
// Text.hpp for Text in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Fri Jun 28 16:07:58 2013 Maxime Wojciak
// Last update Fri Jun 28 16:30:46 2013 Maxime Wojciak
//

#ifndef		TEXT__
#define		TEXT__

#include	<SFML/Graphics.hpp>

class	Texte {
public:
  Texte();
  ~Texte();

public:
  sf::Text	setText(const std::string &, int);
  void		setFont();

  private:
  sf::Font	font;
};

#endif		/* TEXT__ */
