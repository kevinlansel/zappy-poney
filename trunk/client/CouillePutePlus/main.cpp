//
// main.cpp for client in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 17:45:52 2013 Maxime Wojciak
// Last update Fri Jun 28 18:05:55 2013 gery baudry
//

#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	"Windows.hpp"
#include	"Audio.hpp"

using namespace sf;

int		main(int ac, char *av[])
{
  Windows	window;
  Audio		music;

  music.PlaySound();
  window.CreateWindows();
  return 0;
}
