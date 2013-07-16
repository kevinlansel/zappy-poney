//
// Core.cpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Tue Jul 16 09:20:23 2013 florian dewulf
// Last update Tue Jul 16 14:35:21 2013 florian dewulf
//

#include	"Core.hpp"

using namespace std;

Core::Core(const string &host, int port, const string &team) : _mem(new Memory), _net(host, port, team)
{
}

Core::~Core()
{
  delete this->_mem;
}

void		Core::init()
{
  int		i = 51;

  this->_net.initConnexion();
  gnl		tmp(this->_net.getSock());

  this->_gnl = tmp;
  while (--i > 0 && !this->_net.checkBinary())
    {
      if (this->_net.init(this->_gnl))
	{
	  string tempo = this->_gnl.get_next_line();
	  if (this->_net.initConnexion(tempo))
	    this->_mess.work(tempo, this->_mem);
	}
    }
  if (i == 0)
    throw Except("Timeout");
}

bool		Core::update()
{
  if (this->_net.init(this->_gnl))
    return (this->_mess.work(this->_gnl.get_next_line(), this->_mem));
  return (true);
}

void		Core::draw()
{
  this->_mem->drawCase();
  this->_mem->drawPlayer();
  this->_mem->drawOeuf();
}
