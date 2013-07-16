//
// Case.cpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon Jul  1 11:12:44 2013 gery baudry
// Last update Tue Jul 16 13:19:24 2013 florian dewulf
//

#include	"Case.hpp"

Case::Case(const sf::Vector2<float> &size, int x, int y) : _rectangle(size), _x(x), _y(y)
{
  this->_rectangle.setFillColor(sf::Color(0, 204, 0));
  this->_rectangle.setOutlineThickness(1);
  this->_rectangle.setOutlineColor(sf::Color(150, 50, 250));
  this->_rectangle.move(sf::Vector2<float>(size.x * x, size.y * y));
  this->_ress[0] = 0;
  this->_ress[1] = 0;
  this->_ress[2] = 0;
  this->_ress[3] = 0;
  this->_ress[4] = 0;
  this->_ress[5] = 0;
  this->_ress[6] = 0;
}

Case::~Case()
{
}

//
//		Getter
//

sf::RectangleShape		Case::getRectangle() const
{
  return (this->_rectangle);
}

std::vector<int>		Case::getInv() const
{
  return (std::vector<int>(this->_ress, this->_ress + sizeof(this->_ress) / sizeof(int)));
}

//
//		Setter
//

void				Case::setRessource(int a, int b, int c, int d, int e, int f, int g)
{
  this->_ress[0] = a;
  this->_ress[1] = b;
  this->_ress[2] = c;
  this->_ress[3] = d;
  this->_ress[4] = e;
  this->_ress[5] = f;
  this->_ress[6] = g;
}

void			Case::changeColor()
{
  ;//
}

void			Case::upRess(int index)
{
  this->_ress[index] += 1;
}

void			Case::downRess(int index)
{
  this->_ress[index] -= 1;
}
