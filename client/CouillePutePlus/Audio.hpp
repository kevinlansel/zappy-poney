//
// Music.hpp for Music in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Fri Jun 28 14:47:20 2013 Maxime Wojciak
// Last update Fri Jun 28 15:58:22 2013 Maxime Wojciak
//

#ifndef	        AUDIO__
#define		AUDIO__

#include	<SFML/Graphics.hpp>
#include	<SFML/Audio.hpp>

class Audio {
public:
  Audio();
  ~Audio();
  void	PlaySound();
private:
  sf::Music		music;
};

#endif		/* AUDIO__ */
