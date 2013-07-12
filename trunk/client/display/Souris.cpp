//
// Mouse.cpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon Jul  1 15:58:05 2013 gery baudry
// Last update Fri Jul 12 16:20:07 2013 gery baudry
//


#include	<iostream>
#include	"Souris.hpp"
#include	"Windows.hpp"

Souris::Souris() : _position(0,0), _check(false)
{
  this->font.loadFromFile("../ressources/fonts/Sansation_Bold.ttf");
}

Souris::~Souris()
{
}

void			Souris::CheckSouris(sf::RenderWindow &window, std::vector<Case> map, int x, int y, sf::Vector2f taille, Player player)
{
  sf::Vector2<int>		_pos;
  sf::Vector2i			posplayer;

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true && this->_check == false)
    {
      setPosition(window);
      this->_position = getPosition();
      posplayer = player.getPosition();
      // Ajouter check position du player pour affichage d'info suppl !
      if ((this->_position.x <= (x * taille.x)) && (this->_position.y <= (y * taille.y)))
	{
	  for (std::vector<Case>::iterator it = map.begin(); it != map.end(); ++it)
	    {
	      _pos = sf::Vector2<int>(it->getPosition());
	      if ((this->_position.x >= _pos.x && !(this->_position.x >= (_pos.x + taille.x)) && this->_position.y >= _pos.y && !(this->_position.y >= (_pos.y + taille.y))))
		{
		  this->textcase = sf::Text(it->doTextCase(this->_position), this->font, 15);
		  this->textcase.move(sf::Vector2f(1110, 10));
		  this->textcase.setColor(sf::Color(100, 85, 12));
		  break;
		}
	      std::cout << posplayer.x << std::endl;
	      if ((this->_position.x >= posplayer.x && !(this->_position.x >= (posplayer.x + taille.x)) && this->_position.y >= posplayer.y && !(this->_position.y >= (posplayer.y + taille.y))))
		{
		  this->textplayer = sf::Text(player.doTextPlayer(this->_position), this->font, 15);
		  this->textplayer.move(sf::Vector2f(1130, 210));
		  this->textplayer.setColor(sf::Color(102, 0, 0));
		}
	    }
	}
      this->_check = true;
    }
  else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false && this->_check == true)
    {
      this->_check = false;
      this->textcase = sf::Text();
      this->textplayer = sf::Text();
    }
}


void			Souris::setPosition(sf::RenderWindow &window)
{
  sf::Vector2i			tmp;

  tmp = sf::Mouse::getPosition(window);
  this->_position.x = tmp.x;
  this->_position.y = tmp.y;
}

sf::Vector2<int>		Souris::getPosition() const
{
  return (this->_position);
}

sf::Text			Souris::getTextcase() const
{
  return (this->textcase);
}

sf::Text			Souris::getTextplayer() const
{
  return (this->textplayer);
}
