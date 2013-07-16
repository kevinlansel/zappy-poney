//
// Oeuf.cpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Tue Jul 16 13:27:00 2013 florian dewulf
// Last update Tue Jul 16 13:33:51 2013 florian dewulf
//

#include	"Oeuf.hpp"

Oeuf::Oeuf(int _id, int _x, int _y) : x(_x), y(_y), id(_id)
{
}

Oeuf::~Oeuf()
{
}

int		Oeuf::getId() const
{
  return (this->id);
}

int		Oeuf::getX() const
{
  return (this->x);
}

int		Oeuf::getY() const
{
  return (this->y);
}
