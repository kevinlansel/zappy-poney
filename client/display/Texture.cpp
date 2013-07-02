//
// Texture.cpp for Texture in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Fri Jun 28 16:47:34 2013 Maxime Wojciak
// Last update Fri Jun 28 18:11:59 2013 Maxime Wojciak
//

#include	"Texture.hpp"

Textur::Textur() {
}

Textur::~Textur() {

}

void	Textur::setTextur(const std::string &filePath) {
  if (!this->texture.loadFromFile(filePath))
    std::cout << "Failed load Texture" << std::endl;
}

void	Textur::setSprite() {
  /*  if (!sf::Sprite sprite(this->texture))
    std::cout << "TA MERE " << std::endl;
  */
}
