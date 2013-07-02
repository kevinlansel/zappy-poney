//
// Personnage.cpp for Perso in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Tue Jul  2 11:38:16 2013 Maxime Wojciak
// Last update Tue Jul  2 14:02:51 2013 Maxime Wojciak
//

#include "Personnage.hpp"

Personnage::Personnage(const std::string &_file) {
  if (!(this->pokemon.loadFromFile(_file)))
    std::cout << "Error loading texture" << std::endl;
}

Personnage::~Personnage() {
}

sf::Sprite	Personnage::loadPokemon() {
  sf::Sprite sprite(this->pokemon);
  return sprite;
}
