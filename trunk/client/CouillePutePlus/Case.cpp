//
// Case.cpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon Jul  1 11:12:44 2013 gery baudry
// Last update Mon Jul  1 17:38:38 2013 gery baudry
//

#include	"Case.hpp"

Case::Case() : rectangle(sf::Vector2f(50, 50))
{
  this->rectangle.setFillColor(sf::Color(250, 150, 100));
  this->rectangle.setOutlineThickness(1);
  this->rectangle.setOutlineColor(sf::Color(150, 50, 250));
}

Case::~Case()
{
}

void		Case::setPosition(const sf::Vector2f &pos)
{
  this->rectangle.move(pos);
}

sf::RectangleShape		Case::getRectangle() const
{
  return (this->rectangle);
}
