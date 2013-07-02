//
// main.cpp for client in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 17:45:52 2013 Maxime Wojciak
// Last update Tue Jul  2 10:44:25 2013 gery baudry
//

#include	<iostream>
#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	"Windows.hpp"
#include	"Audio.hpp"

using namespace sf;

int		main(int ac, char *av[])
{
  Windows	window(10, 10);
  Audio		music;

  if (ac == 7)
    {
      music.PlaySound();
      window.CreateWindows();
    }
  else
    std::cout << "Usage: ./client [-h hote] [-n equipe] [-p port]" << std::endl;
}
