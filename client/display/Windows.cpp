//
// Windows.cpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:01:06 2013 Maxime Wojciak
// Last update Fri Jul  5 11:49:33 2013 gery baudry
//

#include	<iostream>
#include	<cstdlib>
#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	<vector>
#include	"Personnage.hpp"
#include	"Player.hpp"
#include	"Windows.hpp"
#include	"Texture.hpp"
#include	"Case.hpp"
#include	"Souris.hpp"

Windows::Windows(int x, int y, const Network &net) : window(sf::VideoMode(1280, 1024), "Client Zappy", sf::Style::Fullscreen), _x(x), _y(y), _net(net)
{
  this->taille = sf::Vector2f((1100 / this->_x), (960 / this->_y));
}

Windows::~Windows() {

}

void		Windows::CreateWindows()
{
  //Personnage		perso("../ressources/pictures/noctali.png");
  Player		player(sf::Vector2i(89, 68), 2, 2, 1, 4, 3, 1, 4, 1, "toto");
  Souris		souris;
  sf::Text		text;
  sf::Text		text2;

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
      player.setImage(4);
      this->window.draw(player.getImage().loadPokemon());
      //this->window.draw(perso.loadPokemon());
      souris.CheckSouris(this->window, this->map, this->_x, this->_y, this->taille, player);
      text = souris.getTextcase();
      text2 = souris.getTextplayer();
      this->window.draw(text);
      this->window.draw(text2);
      this->window.display();
    }
}

void		Windows::DrawMap()
{
  int		x = 0;
  int		y = 0;
  int		i = 0;
  std::vector<std::vector<int> >		ress;

  ress = this->_net.getCarte();
  while (y <= ((this->_y - 1) * this->taille.y))
    {
      x = 0;
      while (x <= ((this->_x - 1) * this->taille.x))
	{
	  Case		macase(taille, ress, i);
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
