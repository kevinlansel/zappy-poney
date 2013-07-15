//
// get_next_line.cpp for  in /home/lund/Projets/zappy-poney/client
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Thu Jun 27 16:20:21 2013 florian dewulf
// Last update Mon Jul 15 15:56:35 2013 florian dewulf
//

#include	"get_next_line.hpp"

gnl::gnl(int fd) : _fd(fd), _error(false)
{
}

gnl::~gnl()
{
}

std::string		gnl::get_next_line()
{
  char			buffer[1024];
  int			i;
  std::string		tmp;

  if (this->_buffer.find("\n") == std::string::npos)
    {
      if ((i = read(this->_fd, buffer, 1024)) > 0)
	{
	  buffer[i] = '\0';
	  this->_buffer += buffer;
	}
      else {
	this->_error = true;
	return "";
      }
    }
  tmp = this->_buffer.substr(0, this->_buffer.find("\n"));
  this->_buffer = this->_buffer.substr(this->_buffer.find("\n") + 1, this->_buffer.size());
  return tmp;
}

std::string		gnl::get_answer()
{
  char			buffer[1024];
  int			i;
  std::string		tmp;

  if (this->_buffer == "")
    {
      if ((i = read(this->_fd, buffer, 1024)) > 0)
	{
	  buffer[i] = '\0';
	  this->_buffer = buffer;
	}
      else {
	this->_error = true;
	return "";
      }
    }
  return this->_buffer;
}

std::string	gnl::getbuffer() const
{
  return (this->_buffer);
}

bool		gnl::getError() const
{
  return (this->_error);
}
