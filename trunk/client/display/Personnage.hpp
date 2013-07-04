//
// Personnage.hpp for Perso in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Tue Jul  2 11:38:12 2013 Maxime Wojciak
// Last update Thu Jul  4 16:32:57 2013 gery baudry
//

#ifndef			PERSONNAGE__
# define		PERSONNAGE__

#include		<iostream>
#include		<SFML/Graphics.hpp>

class			Personnage {
public:
  Personnage(int);
  virtual		~Personnage();

public:
  sf::Sprite		loadPokemon();
  void			setImage();

private:
  int			_level;
  sf::Texture		pokemon;
};

#endif		/* !PERSONNAGE__ */
