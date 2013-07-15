//
// Windows.cpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:01:06 2013 Maxime Wojciak
// Last update Mon Jul 15 20:51:45 2013 gery baudry
//

#include	<iostream>
#include	<cstdlib>
#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	<vector>
#include	"Personnage.hpp"
#include	"Player.hpp"
#include	"Network.hpp"
#include	"Windows.hpp"
#include	"Texture.hpp"
#include	"Case.hpp"
#include	"Souris.hpp"
#include	"Message.hpp"

Windows::Windows(int x, int y, const Network &net) : window(sf::VideoMode(1280, 1024), "Client Zappy", sf::Style::Fullscreen), _x(x), _y(y), _net(net), _mem(new Memory), mess(this->_mem)
{
  this->taille = sf::Vector2f((1100 / this->_x), (960 / this->_y));
}

Windows::~Windows() {

}

void		Windows::CreateWindows(gnl &gl)
{
  Souris		souris(this->_mem);
  fd_set			fd_read;
  int				a;
  std::string			req = "";
  struct timeval tv;

  tv.tv_sec = 0;
  tv.tv_usec = 50;

  while (this->window.isOpen())
    {
      std::cout << "avant boucle" << std::endl;
      while (this->window.pollEvent(this->event))
        {
	  std::cout << "debut boucle" << std::endl;
	  if ((this->event.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
	    {
	      std::cout << "Client exiting. Bye !" << std::endl;
	      this->window.close();
	    }
	  std::cout << "apres if" << std::endl;
	  FD_ZERO(&fd_read);
	  FD_SET(this->_net.getSock(), &fd_read);
	  std::cout << "apres sock" << std::endl;
	  if (gl.getbuffer() != "")
	    {
	      req = gl.get_next_line();
	      this->_net.checkData(req);
	      std::cout << "toto" << std::endl;
	      this->_net.checkData2(req);
	      std::cout << "toto2" << std::endl;
	      this->_net.checkData3(req);
	      std::cout << "toto3" << std::endl;
	    }
	  else if ((a = select(this->_net.getSock() + 1, &fd_read, NULL, NULL, &tv)) != -1)
	    {
	      if (FD_ISSET(this->_net.getSock(), &fd_read))
		{
		  req = gl.get_next_line();
		  this->_net.checkData(req);
		  std::cout << "toto" << std::endl;
		  this->_net.checkData2(req);
		  std::cout << "toto2" << std::endl;
		  this->_net.checkData3(req);
		  std::cout << "toto3" << std::endl;
		}
	    }
	  std::cout << "fin boucle" << std::endl;
	}
      this->window.clear();
      DrawMap();
      souris.CheckSouris(this->window, this->_mem->getMap(), this->_x, this->_y, this->taille);
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
	  this->_mem->pushCase(macase);
	  x += this->taille.x;
	  i += 1;
	}
      y += this->taille.y;
    }
  this->_mem->DrawRec(this->window);
}
