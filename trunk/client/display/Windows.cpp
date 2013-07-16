//
// Windows.cpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:01:06 2013 Maxime Wojciak
// Last update Tue Jul 16 12:16:52 2013 gery baudry
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
	  std::cout << this->_net.getSock() << std::endl;
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

  std::cout << "drawmap1" << std::endl;
  ress = this->_net.getCarte();
  std::cout << "drawmap2" << std::endl;
  for (std::vector<std::vector<int> >::iterator it = ress.begin(); it != ress.end(); ++it)
    {
      std::cout << "print ress" << std::endl;
      for (std::vector<int>::iterator ti = it->begin(); ti != it->end(); ++ti)
	std::cout << *ti;
      std::cout << std::endl;
    }
  while (y <= ((this->_y - 1) * this->taille.y))
    {
      std::cout << "drawmap3" << std::endl;
      x = 0;
      while (x <= ((this->_x - 1) * this->taille.x))
	{
	  std::cout << "drawmap4" << std::endl;
	  Case		macase(taille, ress, i);
	  std::cout << "drawmap5" << std::endl;
	  macase.setPosition(sf::Vector2f(x, y));
	  std::cout << "drawmap6" << std::endl;
	  this->_mem->pushCase(macase);
	  std::cout << "drawmap7" << std::endl;
	  x += this->taille.x;
	  i += 1;
	}
      y += this->taille.y;
    }
  this->_mem->DrawRec(this->window);
}
