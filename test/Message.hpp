//
// Message.hpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Mon Jul 15 23:16:18 2013 florian dewulf
// Last update Tue Jul 16 14:43:12 2013 florian dewulf
//

#ifndef		MESSAGE_HPP__
# define	MESSAGE_HPP__

#include	<sstream>
#include	<string>
#include	<vector>
#include	"Memory.hpp"
#include	"Oeuf.hpp"
#include	"Interpret.hpp"

class		Message
{
public:
  Message();
  virtual	~Message();
  void		init();
  bool		work(const std::string &, Memory *);

private:
  std::map<std::string, int>	pattern;
  std::map<std::string, bool (Interpret::*)(Memory *)>	ptr;
  std::vector<std::string>	vec;
};

#endif
