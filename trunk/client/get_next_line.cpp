//
// get_next_line.cpp for  in /home/lund/Projets/zappy-poney/client
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Thu Jun 27 16:20:21 2013 florian dewulf
// Last update Thu Jun 27 16:36:28 2013 florian dewulf
//

#include	"get_next_line.hpp"

gnl::gnl(int fd) : _fd(fd)
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

  while (this->_buffer.find("\n") == std::string::npos)
    {
      if ((i = read(this->_fd, buffer, 1024)) > 0)
	{
	  buffer[i] = '\0';
	  this->_buffer += buffer;
	}
    }
  tmp = this->_buffer.substr(0, this->_buffer.find("\n"));
  this->_buffer = this->_buffer.substr(this->_buffer.find("\n") + 1, this->_buffer.size());
  return tmp;
}

int	main()
{
  int	fd;
  std::string	tmp = "0";
  int		i = 0;

  fd = open("get_next_line.cpp", O_RDONLY);

  gnl	test(fd);

  while (tmp != "")
    {
      tmp = test.get_next_line();
      std::cout << "string n°" << i << " : " << tmp << std::endl;
      i++;
    }
  close(fd);
  return (0);
}
