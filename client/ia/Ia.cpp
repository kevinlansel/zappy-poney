//
// Ia.cpp for zappy in /home/seth/System_unix/zappy-poney/client/ia
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Thu Jun 27 17:17:04 2013 kevin lansel
// Last update Wed Jul  3 12:55:25 2013 kevin lansel
//

#include	<vector>
#include	<iostream>
#include	<sstream>
#include	<cstdlib>
#include	"Ia.hpp"

Ia::Ia() : _lvl(1), _group(0), _slave(0), _chef(0), _member(0), _wait(0)
{
  this->_inv.insert(std::pair<std::string, int>("nourriture", 10));
  this->_inv.insert(std::pair<std::string, int>("linemate", 0));
  this->_inv.insert(std::pair<std::string, int>("deraumere", 0));
  this->_inv.insert(std::pair<std::string, int>("sibur", 0));
  this->_inv.insert(std::pair<std::string, int>("mendiane", 0));
  this->_inv.insert(std::pair<std::string, int>("phiras", 0));
  this->_inv.insert(std::pair<std::string, int>("thystame", 0));
}

Ia::~Ia()
{

}

void				Ia::setLvl(int lvl)
{
  this->_lvl = lvl;
}

void				Ia::setGroup(int group)
{
  this->_group = group;
}

void				Ia::setSlave(int slave)
{
  this->_slave = slave;
}

void				Ia::setChef(int chef)
{
  this->_chef = chef;
}

void				Ia::setMember(int member)
{
  this->_member = member;
}

void				Ia::setWait(int wait)
{
  this->_wait = wait;
}

void				Ia::setMsg(std::list<std::string> msg)
{
  this->_msg = msg;
}

void				Ia::setInv(std::map<std::string, int> inv)
{
  this->_inv = inv;
}

void				Ia::setRoad(std::vector<std::string> road)
{
  this->_road = road;
}

void				Ia::setNeed(std::vector<std::string> need)
{
  this->_need = need;
}

int				Ia::getLvl(void) const
{
  return (this->_lvl);
}

int				Ia::getGroup(void) const
{
  return (this->_group);
}

int				Ia::getSlave(void) const
{
  return (this->_slave);
}

int				Ia::getChef(void) const
{
  return(this->_chef);
}

int				Ia::getMember(void) const
{
  return (this->_member);
}

int				Ia::getWait(void) const
{
  return (this->_wait);
}

std::list<std::string>		Ia::getMsg(void) const
{
  return (this->_msg);
}

std::map<std::string, int>	Ia::getInv(void) const
{
  return (this->_inv);
}

std::vector<std::string>	Ia::getRoad(void) const
{
  return (this->_road);
}

std::vector<std::string>	Ia::getNeed(void) const
{
  return (this->_need);
}

void		Ia::maj_inv(void)
{
  //snd("inventaire");
  std::string			tmp;
  std::vector<std::string>	vec;
  std::string			rec;
  std::string			sav;
  std::stringstream		ss;
  int				i;

  tmp = "{nourriture 35, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0}";
  if (tmp.find("{") >= 0 && tmp.find("{") <= tmp.length())
    tmp = tmp.substr(tmp.find("{") + 1, tmp.length());
  if (tmp.find("}") >= 0 && tmp.find("}") <= tmp.length())
    tmp = tmp.substr(0, tmp.find("}"));
  while (tmp != "")
    {
      vec.push_back(tmp.substr(0, tmp.find(",")));
      if (tmp.find(", ") >= 0 && tmp.find(", ") <= tmp.length())
	tmp = tmp.substr(tmp.find(", ") + 2);
      else
	tmp = "";
    }
  for (std::vector<std::string>::iterator it = vec.begin() ; it != vec.end() ; ++it)
    {
      rec = (*it).substr(0, (*it).find(" "));
      sav = (*it).substr((*it).find(" ") + 1, (*it).length());
      ss.str(sav);
      ss >> i;
      this->_inv[rec] = i;
      ss.clear();
    }
}

const std::string	Ia::faim(void)
{
  int		t;

  t = this->_inv["nourriture"];
  if (t < 20)
    return ("OK");
  else
    return ("KO");
}

const std::string	Ia::move_rd(void) const
{
  unsigned int	rd;

  rd = rand() % 3;
  if (rd == 0)
    ; //return (snd("avance"));
  else if (rd == 1)
    ; //return (snd("gauche"));
  else
    ; //return (snd("droite"));
  return ("OK");
}

const std::string	Ia::move_to(int cas)
{
  if (cas == 1 || cas == 8 || cas == 2)
    ; //return (snd("avance"));
  else if (cas == 7 || cas == 5 || cas == 4 || cas == 6)
    ; //return (snd("droite"));
  else if (cas == 3)
    ; //return (snd("gauche"));
  else
    ; //return (snd("broadcast HERE" + this->_lvl);
  return ("OK");
}

std::map<std::string, int>	Ia::ref()
{
  std::map<std::string, int>	r;

  switch (this->_lvl)
    {
    case 1:
      {
	r.insert(std::pair<std::string, int>("linemate", 1));
	r.insert(std::pair<std::string, int>("deraumere", 0));
	r.insert(std::pair<std::string, int>("sibur", 0));
	r.insert(std::pair<std::string, int>("mendiane", 0));
	r.insert(std::pair<std::string, int>("phiras", 0));
	r.insert(std::pair<std::string, int>("thystame", 0));
	break;
      }
    case 2:
      {
	r.insert(std::pair<std::string, int>("linemate", 1));
	r.insert(std::pair<std::string, int>("deraumere", 1));
	r.insert(std::pair<std::string, int>("sibur", 1));
	r.insert(std::pair<std::string, int>("mendiane", 0));
	r.insert(std::pair<std::string, int>("phiras", 0));
	r.insert(std::pair<std::string, int>("thystame", 0));
	break;
      }
    case 3:
      {
	r.insert(std::pair<std::string, int>("linemate", 2));
	r.insert(std::pair<std::string, int>("deraumere", 0));
	r.insert(std::pair<std::string, int>("sibur", 1));
	r.insert(std::pair<std::string, int>("mendiane", 0));
	r.insert(std::pair<std::string, int>("phiras", 2));
	r.insert(std::pair<std::string, int>("thystame", 0));
	break;
      }
    case 4:
      {
	r.insert(std::pair<std::string, int>("linemate", 1));
	r.insert(std::pair<std::string, int>("deraumere", 1));
	r.insert(std::pair<std::string, int>("sibur", 2));
	r.insert(std::pair<std::string, int>("mendiane", 0));
	r.insert(std::pair<std::string, int>("phiras", 1));
	r.insert(std::pair<std::string, int>("thystame", 0));
	break;
      }
    case 5:
      {
	r.insert(std::pair<std::string, int>("linemate", 1));
	r.insert(std::pair<std::string, int>("deraumere", 2));
	r.insert(std::pair<std::string, int>("sibur", 1));
	r.insert(std::pair<std::string, int>("mendiane", 3));
	r.insert(std::pair<std::string, int>("phiras", 0));
	r.insert(std::pair<std::string, int>("thystame", 0));
	break;
      }
    case 6:
      {
	r.insert(std::pair<std::string, int>("linemate", 1));
	r.insert(std::pair<std::string, int>("deraumere", 2));
	r.insert(std::pair<std::string, int>("sibur", 3));
	r.insert(std::pair<std::string, int>("mendiane", 0));
	r.insert(std::pair<std::string, int>("phiras", 1));
	r.insert(std::pair<std::string, int>("thystame", 0));
	break;
      }
    case 7:
      {
	r.insert(std::pair<std::string, int>("linemate", 2));
	r.insert(std::pair<std::string, int>("deraumere", 2));
	r.insert(std::pair<std::string, int>("sibur", 2));
	r.insert(std::pair<std::string, int>("mendiane", 2));
	r.insert(std::pair<std::string, int>("phiras", 2));
	r.insert(std::pair<std::string, int>("thystame", 1));
	break;
      }
    default:
      break;
    }
  return (r);
}

std::vector<std::string>	Ia::what()
{
  std::vector<std::string>	vec;
  std::map<std::string, int>	r;

  r = this->ref();
  for (std::map<std::string, int>::iterator it = r.begin() ; it != r.end() ; ++it)
    {
      if (this->_inv[it->first] < it->second)
	vec.push_back(it->first);
    }
  this->_need = vec;
  for (std::vector<std::string>::iterator it = vec.begin() ; it != vec.end() ; ++it)
    {
      std::cout << *it << std::endl;
    }
  return (vec);
}

const std::string		Ia::voir()
{
  std::string			see;
  std::string			tmp;
  std::vector<std::string>	vec;
  std::vector<std::string>	need;
  std::vector<int>		where;
  int				i;

  i = 0;
  ; //see = snd("voir");
  tmp = "{linemate deraumere,,, thystame,, nourriture,,,,, thystame,,,,,}";
  if (tmp.find("{") >= 0 && tmp.find("{") <= tmp.length())
    tmp = tmp.substr(tmp.find("{") + 1, tmp.length());
  if (tmp.find("}") >= 0 && tmp.find("}") <= tmp.length())
    tmp = tmp.substr(0, tmp.find("}"));
  while (tmp != "")
    {
      vec.push_back(tmp.substr(0, tmp.find(",")));
      if (tmp.find(",") >= 0 && tmp.find(",") <= tmp.length())
	tmp = tmp.substr(tmp.find(",") + 1);
      else
	tmp = "";
    }
  std::cout << "-------------------------" << std::endl;
  need = what();
  std::cout << "-------------------------" << std::endl;
  for (std::vector<std::string>::iterator it = vec.begin() ; it != vec.end() ; ++it)
    {
      for (std::vector<std::string>::iterator ti = need.begin() ; ti != need.end() ; ++ti)
	{
	  if ((*it).find((*ti)) >= 0 && (*it).find((*ti)) <= (*ti).length())
	    std::cout << i << std::endl;
	}
      std::cout << "--[" << *it << "]--"<< std::endl;
      i++;
    }
  return ("OK");
}

const std::string	Ia::prendre_nourriture() const
{
  ; // return (snd("prend nourriture"));
}

int				main()
{
  Ia				bot;
  std::map<std::string, int>	tmp;

  tmp = bot.getInv();
  for (std::map<std::string, int>::iterator it = tmp.begin() ; it != tmp.end() ; ++it)
    std::cout << it->first << " : " << it->second<< std::endl;
  bot.maj_inv();

  tmp = bot.getInv();
  for (std::map<std::string, int>::iterator it = tmp.begin() ; it != tmp.end() ; ++it)
    std::cout << it->first << " : " << it->second<< std::endl;

  bot.voir();
}
