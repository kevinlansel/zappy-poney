//
// Windows.hpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:00:59 2013 Maxime Wojciak
// Last update Mon Jul 15 19:19:59 2013 gery baudry
//

#ifndef		WINDOWS__
#define		WINDOWS__

#include	<SFML/Graphics.hpp>
#include	<SFML/Audio.hpp>
#include	"Network.hpp"
#include	"Case.hpp"
#include	"Texte.hpp"
#include	"Memory.hpp"

class		Windows {
public:
  Windows(int, int, const Network &);
  virtual		~Windows();

public:
  void			CreateWindows(gnl &);
  void			DrawMap();
  void			checkMess(int);

private:
  sf::Event		event;
  sf::RenderWindow	window;
  int			_x;
  int			_y;
  sf::Vector2f		taille;
  Network		_net;
  Memory		*_mem;
  Message		mess;
};

#endif			/* WINDOWS__ */
