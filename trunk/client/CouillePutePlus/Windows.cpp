//
// Windows.cpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:01:06 2013 Maxime Wojciak
// Last update Mon Jul  1 12:04:01 2013 gery baudry
//

#include	<iostream>
#include	<cstdlib>
#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	"Windows.hpp"
#include	"Texture.hpp"
#include	"Case.hpp"

Windows::Windows() : window(sf::VideoMode(800, 600), "Client Zappy") {
}

Windows::~Windows() {

}

int	Windows::CreateWindows() {
  Case macase;
  macase.setPosition(sf::Vector2f(50, 50));
  sf::Font font;
  if (!font.loadFromFile("../ressources/fonts/Sansation_Bold.ttf"))
    return EXIT_FAILURE;
  sf::Text text("Yooo Negro", font, 50);
  sf::Texture texture;
  if (!texture.loadFromFile("../ressources/pictures/noctali.png"))
    return EXIT_FAILURE;
  sf::Sprite sprite(texture);
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
      this->window.draw(sprite);
      this->window.draw(text);
      this->window.draw(macase.getRectangle());
      this->window.display();
    }
}
