//
// Player.cpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Tue Jul 16 01:14:00 2013 florian dewulf
// Last update Tue Jul 16 17:00:33 2013 florian dewulf
//

#include	"Player.hpp"

Player::Player(int id, int x_, int y_, int direction, int level, const std::string &team_) : _id(id), x(x_), y(y_), dir(direction), lvl(level), team(team_), _case(NULL)
{
  this->ress[0] = 0;
  this->ress[1] = 0;
  this->ress[2] = 0;
  this->ress[3] = 0;
  this->ress[4] = 0;
  this->ress[5] = 0;
  this->ress[6] = 0;
}

Player::~Player()
{
}

void		Player::setCase(Case *c)
{
  if (c)
    {
      this->x = c->getX();
      this->y = c->getY();
      this->_case = c;
    }
}

int		Player::getId() const
{
  return (this->_id);
}

int		Player::getLvl() const
{
  return (this->lvl);
}

void		Player::majPos(int x, int y, int dir)
{
  this->x = x;
  this->y = y;
  this->dir = dir;
}

void		Player::setLvl(int level)
{
  this->lvl = level;
}

void		Player::majInv(int a, int b, int c, int d, int e, int f, int g)
{
  ress[0] = a;
  ress[1] = b;
  ress[2] = c;
  ress[3] = d;
  ress[4] = e;
  ress[5] = f;
  ress[6] = g;
}

int		Player::getDirec() const
{
  return (this->dir);
}

void		Player::drop(int ress)
{
  if (this->_case)
    this->_case->upRess(ress);
  this->ress[ress] -= 1;
}

void		Player::take(int ress)
{
  if (this->_case)
    this->_case->downRess(ress);
  this->ress[ress] += 1;
}

std::vector<int>	Player::getInventaire() const
{
  return (std::vector<int>(this->ress, this->ress + sizeof(this->ress) / sizeof(int)));
}

int		Player::getX() const
{
  return (this->x);
}

int		Player::getY() const
{
  return (this->y);
}
