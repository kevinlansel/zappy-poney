//
// Windows.hpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:00:59 2013 Maxime Wojciak
// Last update Mon Jul  1 16:35:01 2013 gery baudry
//

#ifndef		WINDOWS__
#define		WINDOWS__

#include	<SFML/Graphics.hpp>
#include	<SFML/Audio.hpp>
#include	"Case.hpp"

class		Windows {
public:
  Windows();
  ~Windows();

public:
  void			CreateWindows();
  void			DrawMap();
  std::vector<Case>	getVector() const;

private:
  sf::Event			event;
  sf::RenderWindow		window;
  std::vector<Case>	map;
};

#endif		/* WINDOWS__ */
