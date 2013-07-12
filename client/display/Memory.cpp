//
// Memory.cpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Fri Jul 12 15:37:57 2013 gery baudry
// Last update Fri Jul 12 16:16:42 2013 gery baudry
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

std::vector<Player>		Memory::getPliste() const
{
  return (this->_pliste);
}

std::vector<Case>		Memory::getMap() const
{
  return (this->_map);
}
