//
// Windows.cpp for Windows in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 18:01:06 2013 Maxime Wojciak
// Last update Mon Jul 15 17:50:46 2013 gery baudry
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

Windows::Windows(int x, int y, const Network &net) : window(sf::VideoMode(1280, 1024), "Client Zappy", sf::Style::Fullscreen), _x(x), _y(y), _net(net), _mem(new Memory)
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
	      std::cout << "Client exiting. Bye !" << std::endl;
	      this->window.close();
	    }
	  FD_ZERO(&fd_read);
	  FD_SET(this->_net.getSock(), &fd_read);
	  if (gl.getbuffer() != "")
	    {
	      req = gl.get_next_line();
	      this->_net.checkData(req);
	      this->_net.checkData2(req);
	      this->_net.checkData3(req);
	    }
	  else if ((a = select(this->_net.getSock() + 1, &fd_read, NULL, NULL, &tv)) != -1)
	    {
	      if (FD_ISSET(this->_net.getSock(), &fd_read))
		{
		  req = gl.get_next_line();
		  this->_net.checkData(req);
		  this->_net.checkData2(req);
		  this->_net.checkData3(req);
		}
	    }
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

void				Windows::checkMess()
{
  int		i;
  Message		mess;

  switch (i)
    {
    case 0:
      {
	mess.setPex(int);
	break;
      }
    case 1:
      {
	mess.setPbc(string, string);
	break;
      }
    case 2:
      {
	mess.setPic(int, int, int, string);
	break;
      }
    case 3:
      {
	mess.setPie(int, int, int, int);
	break;
      }
    case 4:
      {
	mess.setPfk(int, int);
	break;
      }
    case 5:
      {
	mess.setPdr(int, int);
	break;
      }
    case 6:
      {
	mess.setPgt(int, int);
	break;
      }
    case 7:
      {
	mess.setPdi(int);
	break;
      }
    case 8:
      {
	mess.setEnw(int, int, int, int);
	break;
      }
    case 9:
      {
	mess.setEht(int);
	break;
      }
    case 10:
      {
	mess.setEbo(int);
	break;
      }
    case 11:
      {
	mess.setEdi(int);
	break;
      }
    case 12:
      {
	mess.setSgt(int);
	break;
      }
    case 13:
      {
	mess.setSeg(string);
	break;
      }
    case 14:
      {
	mess.setSmg(string);
	break;
      }
    case 15:
      {
	mess.setPnw(int, int, int, int, int, string);
	break;
      }
    case 15:
      {
	mess.setSuc();
	break;
      }
    }
  return (void);
}

// std::vector<Case>		Windows::getVector() const
// {
//   return (this->map);
// }
