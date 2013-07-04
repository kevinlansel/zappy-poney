//
// Windows.cpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:01:06 2013 Maxime Wojciak
// Last update Thu Jul  4 12:26:45 2013 gery baudry
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

Windows::Windows(int x, int y, const Network &net) : window(sf::VideoMode(1280, 1024), "Client Zappy"), _x(x), _y(y), _net(net)
{
  this->taille = sf::Vector2f((1100 / this->_x), (960 / this->_y));
}

Windows::~Windows() {

}

void		Windows::CreateWindows()
{
  //Personnage		perso("../ressources/pictures/noctali.png");
  Souris		souris;
  sf::Text		text;

  std::cout << "create windob 1" << std::endl;
  while (this->window.isOpen())
    {
      std::cout << "create windob 2" << std::endl;
      while (this->window.pollEvent(this->event))
        {
	  std::cout << "create windob 3" << std::endl;
	  if ((this->event.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
	    {
	      std::cout << "Client exiting. Bye !" << std::endl;
	      this->window.close();
	    }
	}
      std::cout << "create windob 4" << std::endl;
      this->window.clear();
      std::cout << "create windob 5" << std::endl;
      DrawMap();
      std::cout << "create windob 6" << std::endl;
      //this->window.draw(perso.loadPokemon());
      text = souris.CheckSouris(this->window, this->map, this->_x, this->_y, this->taille);
      std::cout << "create windob 7" << std::endl;
      this->window.draw(text);
      std::cout << "create windob 8" << std::endl;
      this->window.display();
    }
}

void		Windows::DrawMap()
{
  int		x = 0;
  int		y = 0;
  int		i = 0;

  while (y <= ((this->_y - 1) * this->taille.y))
    {
      x = 0;
      while (x <= ((this->_x - 1) * this->taille.x))
	{
	  std::cout << "draw map 1" << std::endl;
	  Case		macase(taille, this->_net.getCarte(), i);
	  std::cout << "draw map 2" << std::endl;
	  macase.setPosition(sf::Vector2f(x, y));
	  this->map.push_back(macase);
	  x += this->taille.x;
	  i += 1;
	}
      y += this->taille.y;
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
