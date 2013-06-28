//
// Font.cpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Fri Jun 28 17:41:16 2013 gery baudry
// Last update Fri Jun 28 17:48:56 2013 gery baudry
//

#include	"Font.hpp"

Font::Font(std::string text, int size) : _Text(text), _Size(size)
{
  this->_Font = ("../ressource/fonts/Sansation_Bold.ttf")
}

Font::~Font()
{
}

sf::Text		Font::printText()
{
  sf::Text	text;

  return (text(this->_Text, this->_Font, this->_Size));
}
