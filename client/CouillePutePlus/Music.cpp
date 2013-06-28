//
// Music.cpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Fri Jun 28 17:36:41 2013 gery baudry
// Last update Fri Jun 28 17:40:17 2013 gery baudry
//

#include	"Music.hpp"

Music::Music()
{
}

Music::~Music()
{
}

Music::playMusic()
{
  Music		music;
  if (!music.openFromFile("../ressource/audio/contact.wav"))
    return EXIT_FAILURE;
  music.play();
}
