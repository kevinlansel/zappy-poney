//
// Text.hpp for Text in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Fri Jun 28 16:07:58 2013 Maxime Wojciak
// Last update Thu Jul  4 16:32:30 2013 gery baudry
//

#ifndef		TEXT__
#define		TEXT__

#include	<SFML/Graphics.hpp>

class	Texte {
public:
  Texte();
  virtual	~Texte();

public:
  sf::Text	setText(const std::string &, int);
  void		setFont();

  private:
  sf::Font	font;
};

#endif		/* TEXT__ */
