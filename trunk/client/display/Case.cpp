//
// Case.cpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon Jul  1 11:12:44 2013 gery baudry
// Last update Wed Jul  3 14:56:00 2013 gery baudry
//

#include	<iostream>
#include	"Case.hpp"

Case::Case(sf::Vector2f taille, int nourriture, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame) : rectangle(taille), _nourriture(nourriture), _linemate(linemate), _deraumere(deraumere), _sibur(sibur), _mendiane(mendiane), _phiras(phiras), _thystame(thystame)
{
  std::cout << taille.x << " " << taille.y << std::endl;
  this->rectangle.setFillColor(sf::Color(0, 204, 204));
  this->rectangle.setOutlineThickness(1);
  this->rectangle.setOutlineColor(sf::Color(150, 50, 250));
}

Case::~Case()
{
}

std::string			Case::doText()
{
  std::stringstream		inv;

  inv << "Inventaire de la case \nX = " << this->_pos.x << " Y = " << this->_pos.y << "\nNourriture = " << this->_nourriture << " \n" << "Linemate = " << this->_linemate << " \n" << "Deraumere = " << this->_deraumere << " \n" << "Sibur = " << this->_sibur << " \n" << "Mediane = " << this->_mendiane << " \n" << "Phiras = " << this->_phiras << " \n" << "Thystame = " << this->_thystame << " \n";
  return (inv.str());
}

//
//		Getter
//

sf::RectangleShape		Case::getRectangle() const
{
  return (this->rectangle);
}

sf::Vector2f			Case::getPosition() const
{
  return (this->_pos);
}

int				Case::getNourriture() const
{
  return (this->_nourriture);
}

int				Case::getLinemate() const
{
  return (this->_linemate);
}

int				Case::getDeraumere() const
{
  return (this->_deraumere);
}

int				Case::getSibur() const
{
  return (this->_sibur);
}

int				Case::getMendiane() const
{
  return (this->_mendiane);
}

int				Case::getPhiras() const
{
  return (this->_phiras);
}

int				Case::getThystame() const
{
  return (this->_thystame);
}

//
//		Setter
//

void				Case::setPosition(const sf::Vector2f &pos)
{
  this->_pos = pos;
  this->rectangle.move(pos);
}

void				Case::setNourriture(int val)
{
  this->_nourriture = val;
}

void				Case::setLinemate(int val)
{
  this->_linemate = val;
}

void				Case::setDeraumere(int val)
{
  this->_deraumere = val;
}

void				Case::setSibur(int val)
{
  this->_sibur = val;
}

void				Case::setMendiane(int val)
{
  this->_mendiane = val;
}

void				Case::setPhiras(int val)
{
  this->_phiras = val;
}

void				Case::setThystame(int val)
{
  this->_thystame = val;
}
