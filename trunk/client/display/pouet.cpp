//
// pouet.cpp for pouet in /home/haz3/projet/zappy-poney/client/display
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Tue Jul  9 15:54:45 2013 Maxime Wojciak
// Last update Tue Jul 16 13:21:11 2013 Maxime Wojciak
//

#include	<string>
#include	<sstream>

std::string	tonton(int nazi) {
  std::stringstream	ss;
  ss << nazi;
  return ss.str();
}

int		tata(const std::string &noir) {
  std::stringstream	ss;
  int			value = 0;

  ss.str(noir);
  ss >> value;
  return value;
}