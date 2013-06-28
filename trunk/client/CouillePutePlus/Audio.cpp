//
// Music.cpp for Music in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Fri Jun 28 14:47:26 2013 Maxime Wojciak
// Last update Fri Jun 28 16:45:43 2013 Maxime Wojciak
//

#include	<iostream>
#include	"Audio.hpp"

Audio::Audio() {
  if (!this->music.openFromFile("../ressources/audio/contact.wav"))
    std::cout << "Failed to Load Music" << std::endl;
}

Audio::~Audio() {
}

void	Audio::PlaySound() {
  this->music.play();
}
