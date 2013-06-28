//
// Text.cpp for Text in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Fri Jun 28 16:09:34 2013 Maxime Wojciak
// Last update Fri Jun 28 16:36:37 2013 Maxime Wojciak
//

#include	"Texte.hpp"

Texte::Texte() {
  this->font.loadFromFile("../ressources/font/Sansation_Bold.ttf");
}

Texte::~Texte() {
}

sf::Text	Texte::setText(const std::string &msg, int size) {
  sf::Text	text;

  setFont();
  return text(msg, this->font, 50);
}
