//
// Memory.cpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Fri Jul 12 15:37:57 2013 gery baudry
// Last update Fri Jul 12 17:44:17 2013 gery baudry
//

#include			"Memory.hpp"

Memory::Memory()
{
}

Memory::~Memory()
{
}

//
// Getter
//

void				Memory::pushCase(const Case &_case)
{
  this->_map.push_back(_case);
}

std::vector<Player>		Memory::getPliste() const
{
  return (this->_pliste);
}

std::vector<Case>		Memory::getMap() const
{
  return (this->_map);
}

void				Memory::DrawRec(sf::RenderWindow &win)
{
  for (std::vector<Case>::iterator it = this->_map.begin(); it != this->_map.end() ; ++it)
    win.draw(it->getRectangle());
}
