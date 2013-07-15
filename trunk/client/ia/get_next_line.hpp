//
// get_next_line.hpp for  in /home/lund/Projets/zappy-poney/client
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Thu Jun 27 16:21:12 2013 florian dewulf
// Last update Mon Jul 15 11:25:38 2013 florian dewulf
//

#ifndef		TOTO_HPP__
# define	TOTO_HPP__

#include	<iostream>
#include	<string>
#include	<unistd.h>

#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/stat.h>

class		gnl
{
public:
  gnl(int);
  virtual	~gnl();
  std::string	get_next_line();
  std::string	get_answer();
  std::string	getbuffer() const;
  std::string	geterror() const;

private:
  int		_fd;
  bool		_error;
  std::string	_buffer;
};

#endif
