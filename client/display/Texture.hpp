//
// Texture.hpp for Texture in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Fri Jun 28 16:47:27 2013 Maxime Wojciak
// Last update Thu Jul  4 16:31:52 2013 gery baudry
//

#ifndef		TEXTURE__
#define		TEXTURE__

#include	<iostream>
#include	<SFML/Graphics.hpp>

class	Textur {
public:
  Textur();
  virtual	~Textur();

public:
  void	setTextur(const std::string &);
  void	setSprite();

private:
  sf::Texture	texture;
  sf::Sprite	sprite;
};

#endif		/* !TEXTURE__ */
