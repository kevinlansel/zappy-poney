//
// Windows.cpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:01:06 2013 Maxime Wojciak
// Last update Tue Jul 16 13:47:20 2013 gery baudry
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

Windows::Windows(int x, int y, const Network &net) : window(sf::VideoMode(1280, 1024), "Client Zappy"/*, sf::Style::Fullscreen*/), _x(x), _y(y), _net(net), _mem(new Memory), mess(this->_mem)
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
      while (this->window.pollEvent(this->event))
        {
	  if ((this->event.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
	    {
	      this->window.close();
	    }
	  FD_ZERO(&fd_read);
	  FD_SET(this->_net.getSock(), &fd_read);
	  if (gl.getbuffer() != "")
	    {
	      std::cout << "if" << std::endl;
	      req = gl.get_next_line();
	      //std::cout << req << std::endl;
	      this->_net.checkData(req);
	      this->_net.checkData2(req);
	      this->_net.checkData3(req);
	    }
	  else if ((a = select(this->_net.getSock() + 1, &fd_read, NULL, NULL, &tv)) != -1)
	    {
	      if (FD_ISSET(this->_net.getSock(), &fd_read))
		{
		  std::cout << "else if" << std::endl;
		  req = gl.get_next_line();
		  //		  std::cout << req << std::endl;
		  this->_net.checkData(req);
		  this->_net.checkData2(req);
		  this->_net.checkData3(req);
		}
	    }
	}
      this->window.clear();
      std::cout << "player draw 1" << this->_mem->getPliste().size() << std::endl;
      for (std::vector<Player>::iterator it = this->_mem->getPliste().begin(); it != this->_mem->getPliste().end(); ++it)
	{
	  std::cout << "player draw 2" << std::endl;
	  this->window.draw(it->getImage().loadPokemon(it->getPosition()));
	}
      std::cout << "player draw 3" << std::endl;
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
    /*    for (std::vector<std::vector<int> >::iterator it = ress.begin(); it != ress.end(); ++it)
    {
      for (std::vector<int>::iterator ti = it->begin(); ti != it->end(); ++ti)
	std::cout << *ti;
      std::cout << std::endl;
      }*/
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
