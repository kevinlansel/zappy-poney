//
// Mouse.cpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon Jul  1 15:58:05 2013 gery baudry
// Last update Tue Jul  2 13:32:18 2013 gery baudry
//


#include	<iostream>
#include	"Souris.hpp"
#include	"Windows.hpp"

Souris::Souris() : _toto(false)
{
}

Souris::~Souris()
{
}

sf::Vector2i			Souris::CheckSouris(sf::RenderWindow &window, std::vector<Case> &map, int x, int y)
{
  sf::Vector2f		_pos;
  sf::Font	font;
  font.loadFromFile("../ressources/fonts/Sansation_Bold.ttf");

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true && this->_toto == false)
    {
      setPosition(window);
      this->_position = getPosition();
      if ((this->_position.x <= (x * 50)) && (this->_position.y <= (y * 50)))
	{
	  for (std::vector<Case>::iterator it = map.begin(); it != map.end(); ++it)
	    {
	      _pos = it->getPosition();
	      if (this->_position.x > _pos.x && this->_position.y > _pos.y)
		{
		  sf::Text text(it->doText(), font, 20);
		  text.move(sf::Vector2f(550, 100));
		  text.setColor(sf::Color(100, 340, 12));
		  window.draw(text);
		}
	    }
	  std::cout << "pos X = " << this->_position.x << "pos Y = " << this->_position.y << std::endl;
	}
      this->_toto = true;
    }
  else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false && this->_toto == true)
    this->_toto = false;
  return (this->_position);
}


void		Souris::setPosition(sf::RenderWindow &window)
{
  this->_position = sf::Mouse::getPosition(window);
}

sf::Vector2i		Souris::getPosition() const
{
  return (this->_position);
}
