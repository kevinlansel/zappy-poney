//
// Windows.hpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:00:59 2013 Maxime Wojciak
// Last update Fri Jun 28 17:49:40 2013 gery baudry
//

#ifndef		WINDOWS__
#define		WINDOWS__

#include	<SFML/Graphics.hpp>

using		namespace sf;

class		Windows {
public:
  Windows();
  ~Windows();

public:
  void		CreateWindows();

private:
  Event		event;
};

#endif		/* WINDOWS__ */
