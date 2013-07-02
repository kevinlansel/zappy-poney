//
// Windows.cpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:01:06 2013 Maxime Wojciak
// Last update Tue Jul  2 14:03:09 2013 Maxime Wojciak
//

#include	<iostream>
#include	<cstdlib>
#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	<vector>
#include	"Personnage.hpp"
#include	"Windows.hpp"
#include	"Texture.hpp"
#include	"Case.hpp"
#include	"Souris.hpp"

Windows::Windows(int x, int y) : window(sf::VideoMode(800, 600), "Client Zappy"), _x(x), _y(y)
{
}

Windows::~Windows() {

}

void		Windows::CreateWindows()
{
  Personnage		perso("../ressources/pictures/noctali.png");
  Souris		souris;
  sf::Vector2i		position;

  while (this->window.isOpen())
    {
      while (this->window.pollEvent(this->event))
        {
	  if ((this->event.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
	    {
	      std::cout << "Client exiting. Bye !" << std::endl;
	      this->window.close();
	    }
	}
      this->window.clear();
      DrawMap();
      this->window.draw(perso.loadPokemon());
      position = souris.CheckSouris(this->window, this->map, this->_x, this->_y);
      this->window.display();
    }
}

void		Windows::DrawMap()
{
  int		x = 0;
  int		y = 0;

  while (y <= ((this->_y - 1) * 50))
    {
      x = 0;
      while (x <= ((this->_x - 1) * 50))
	{
	  Case		macase(1, 2 , 3, 4 ,5, 6, 7);
	  macase.setPosition(sf::Vector2f(x, y));
	  this->map.push_back(macase);
	  x += 50;
	}
	y += 50;
    }
  for (std::vector<Case>::iterator it = this->map.begin(); it != this->map.end(); ++it)
    this->window.draw(it->getRectangle());
}

std::vector<Case>		Windows::getVector() const
{
  return (this->map);
}

// sf::Texture texture;
// if (!texture.loadFromFile("../ressources/pictures/noctali.png"))
//     return EXIT_FAILURE;
// sf::Sprite sprite(texture);
// this->window.draw(sprite);
// this->window.draw(text);
