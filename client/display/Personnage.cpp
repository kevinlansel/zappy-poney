//
// Personnage.cpp for Perso in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Tue Jul  2 11:38:16 2013 Maxime Wojciak
// Last update Thu Jul  4 16:14:37 2013 gery baudry
//

#include "Personnage.hpp"

Personnage::Personnage(int level) : _level(level)
{
  setImage();
 //  if (!(this->pokemon.loadFromFile("../ressources/pictures/aquali.png")))
//     std::cout << "Error loading texture" << std::endl;
}

Personnage::~Personnage() {
}

sf::Sprite		Personnage::loadPokemon() {
  sf::Vector2f	scale;
  sf::Sprite sprite(this->pokemon);
  scale = sf::Vector2f(0.4, 0.4);
  sprite.setScale(scale);
  return sprite;
}

void			Personnage::setImage()
{
  if (this->_level == 1)
    this->pokemon.loadFromFile("../ressources/pictures/aquali.png");
  else if (this->_level == 2)
    this->pokemon.loadFromFile("../ressources/pictures/evoli.png");
  else if (this->_level == 3)
    this->pokemon.loadFromFile("../ressources/pictures/givrali.png");
  else if (this->_level == 4)
    this->pokemon.loadFromFile("../ressources/pictures/mentali.png");
  else if (this->_level == 5)
    this->pokemon.loadFromFile("../ressources/pictures/noctali.png");
  else if (this->_level == 6)
    this->pokemon.loadFromFile("../ressources/pictures/phyllali.png");
  else if (this->_level == 7)
    this->pokemon.loadFromFile("../ressources/pictures/pyroli.png");
  else if (this->_level == 8)
    this->pokemon.loadFromFile("../ressources/pictures/voltali.png");
}
