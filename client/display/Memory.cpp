//
// Memory.cpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Fri Jul 12 15:37:57 2013 gery baudry
// Last update Tue Jul 16 14:01:50 2013 gery baudry
//

#include			"Memory.hpp"

Memory::Memory()
{
}

Memory::Memory(const Memory &d): _pliste(d.getPliste()), _map(d.getMap()), _oeuf(d.getOeuf())
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

void				Memory::pushPlayer(const Player &_player)
{
  this->_pliste.push_back(_player);
}
std::vector<Oeuf>		Memory::getOeuf() const
{
  return (this->_oeuf);
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
