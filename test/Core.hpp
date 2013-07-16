//
// Core.hpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Tue Jul 16 09:07:48 2013 florian dewulf
// Last update Tue Jul 16 10:41:48 2013 florian dewulf
//

#ifndef		CORE_HPP__
# define	CORE_HPP__

#include	<string>
#include	"Memory.hpp"
#include	"Message.hpp"
#include	"get_next_line.hpp"
#include	"Network.hpp"
#include	"Player.hpp"
#include	"Oeuf.hpp"
#include	"Except.hpp"

class		Core
{
public:
  Core(const std::string &, int, const std::string &);
  virtual	~Core();

  void		init();
  void		update();
  void		draw();

private:
  Memory	*_mem;
  Network	_net;
  Message	_mess;
  gnl		_gnl;
};

#endif
