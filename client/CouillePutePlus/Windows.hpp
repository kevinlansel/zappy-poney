//
// Windows.hpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:00:59 2013 Maxime Wojciak
// Last update Mon Jul  1 13:35:39 2013 gery baudry
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
  void		CreateWindows();
  void		DrawMap();

private:
  Event			event;
  RenderWindow		window;
};

#endif		/* WINDOWS__ */
