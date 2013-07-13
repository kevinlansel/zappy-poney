//
// Oeuf.cpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Tue Jul  9 10:08:13 2013 gery baudry
// Last update Sat Jul 13 17:03:51 2013 gery baudry
//

#include	"Oeuf.hpp"

Oeuf::Oeuf(int id) : _id(id), _eclo(false)
{
}

Oeuf::~Oeuf()
{
}

int			Oeuf::getId() const
{
  return (this->_id);
}
