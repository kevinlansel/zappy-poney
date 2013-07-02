//
// Personnage.cpp for Perso in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Tue Jul  2 11:38:16 2013 Maxime Wojciak
// Last update Tue Jul  2 14:41:18 2013 Maxime Wojciak
//

#include "Personnage.hpp"

Personnage::Personnage(const std::string &_file) {
  if (!(this->pokemon.loadFromFile(_file)))
    std::cout << "Error loading texture" << std::endl;
}

Personnage::~Personnage() {
}

sf::Sprite	Personnage::loadPokemon() {
  sf::Vector2f	scale;
  sf::Sprite sprite(this->pokemon);
  scale = sf::Vector2f(0.4, 0.4);
  sprite.setScale(scale);
  return sprite;
}
