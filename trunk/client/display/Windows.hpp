//
// Windows.hpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:00:59 2013 Maxime Wojciak
// Last update Thu Jul  4 16:31:33 2013 gery baudry
//

#ifndef		WINDOWS__
#define		WINDOWS__

#include	<SFML/Graphics.hpp>
#include	<SFML/Audio.hpp>
#include	"Network.hpp"
#include	"Case.hpp"
#include	"Texte.hpp"

class		Windows {
public:
  Windows(int, int, const Network &);
  virtual		~Windows();

public:
  void			CreateWindows();
  void			DrawMap();
  std::vector<Case>	getVector() const;

private:
  sf::Event		event;
  sf::RenderWindow	window;
  std::vector<Case>	map;
  int			_x;
  int			_y;
  sf::Vector2f		taille;
  Network		_net;
};

#endif			/* WINDOWS__ */
