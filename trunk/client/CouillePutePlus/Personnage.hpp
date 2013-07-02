//
// Personnage.hpp for Perso in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Tue Jul  2 11:38:12 2013 Maxime Wojciak
// Last update Tue Jul  2 12:32:11 2013 Maxime Wojciak
//

#ifndef		PERSONNAGE__
#define		PERSONNAGE__

#include	<iostream>
#include	<SFML/Graphics.hpp>

class	Personnage {
public:
  Personnage(const std::string &);
  ~Personnage();

public:
  sf::Sprite	getPokemon();

private:
  sf::Texture	pokemon;
};

#endif		/* !PERSONNAGE__ */
