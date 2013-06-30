//
// Windows.hpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:00:59 2013 Maxime Wojciak
// Last update Sun Jun 30 16:11:24 2013 Maxime Wojciak
//

#ifndef		WINDOWS__
#define		WINDOWS__

#include	<SFML/Graphics.hpp>
#include	<SFML/Audio.hpp>

using		namespace sf;

class		Windows {
public:
  Windows();
  ~Windows();

public:
  int		CreateWindows();

private:
  Event			event;
  sf::RenderWindow	window;
};

#endif		/* WINDOWS__ */
