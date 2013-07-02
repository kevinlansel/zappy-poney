//
// Texture.hpp for Texture in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Fri Jun 28 16:47:27 2013 Maxime Wojciak
// Last update Fri Jun 28 17:45:17 2013 Maxime Wojciak
//

#ifndef		TEXTURE__
#define		TEXTURE__

#include	<iostream>
#include	<SFML/Graphics.hpp>

class	Textur {
public:
  Textur();
  ~Textur();

public:
  void	setTextur(const std::string &);
  void	setSprite();

private:
  sf::Texture	texture;
  sf::Sprite	sprite;
};

#endif		/* !TEXTURE__ */
