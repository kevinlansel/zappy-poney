//
// Windows.cpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:01:06 2013 Maxime Wojciak
// Last update Mon Jul  1 16:37:41 2013 gery baudry
//

#include	<iostream>
#include	<cstdlib>
#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	<vector>
#include	"Windows.hpp"
#include	"Texture.hpp"
#include	"Case.hpp"
#include	"Souris.hpp"

Windows::Windows() : window(sf::VideoMode(800, 600), "Client Zappy") {
}

Windows::~Windows() {

}

void		Windows::CreateWindows()
{
  Souris	souris;
  sf::Vector2i	position;

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
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
	  souris.setPosition();
	  position = souris.getPosition();
	}
      std::cout << "pos X = " << position.x << "pos Y = " << position.y << std::endl;
      this->window.display();
    }
}

void		Windows::DrawMap()
{
  int		x = 0;
  int		y = 0;

  while (y <= 450)
    {
      x = 0;
      while (x <= 450)
	{
	  Case		macase;
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

// sf::Font font;
// if (!font.loadFromFile("../ressources/fonts/Sansation_Bold.ttf"))
//     return EXIT_FAILURE;
// sf::Text text("Yooo Negro", font, 50);
// sf::Texture texture;
// if (!texture.loadFromFile("../ressources/pictures/noctali.png"))
//     return EXIT_FAILURE;
// sf::Sprite sprite(texture);
// this->window.draw(sprite);
// this->window.draw(text);
