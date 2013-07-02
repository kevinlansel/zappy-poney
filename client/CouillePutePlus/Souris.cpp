//
// Mouse.cpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon Jul  1 15:58:05 2013 gery baudry
// Last update Tue Jul  2 12:13:39 2013 gery baudry
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

sf::Vector2i			Souris::CheckSouris(sf::RenderWindow &window)
{
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true && this->_toto == false)
    {
      setPosition(window);
      this->_position = getPosition();
      for (std::vector<Case>::iterator it = window.map.begin(); it != window.map.end(); ++it)
	{
	  if (this->_position.x > it._pos.x && this->_position.y > it._pos.y)
	    text = it.doText();
	}
      std::cout << "pos X = " << this->_position.x << "pos Y = " << this->_position.y << std::endl;
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

// sf::Font	font;
// font.loadFromFile("../ressources/fonts/Sansation_Bold.ttf");
// sf::Text text("Yooo Negro", font, 30);
// text.move(sf::Vector2f(550, 100));
// text.setColor(sf::Color(100, 340, 12));
// window.draw(text);
