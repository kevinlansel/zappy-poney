//
// Ia.cpp for zappy in /home/seth/System_unix/zappy-poney/client/ia
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Thu Jun 27 17:17:04 2013 kevin lansel
// Last update Mon Jul 15 18:01:33 2013 kevin lansel
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

void				Ia::setRessource(std::vector<std::string> ressource)
{
  this->_ressource = ressource;
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

std::vector<std::string>	Ia::getRessource(void) const
{
  return (this->_ressource);
}

emsg		Ia::maj_inv(void)
{
  std::string			tmp;
  std::vector<std::string>	vec;
  std::string			rec;
  std::string			sav;
  std::stringstream		ss;
  int				i;

  //snd("inventaire");
  tmp = "{nourriture 51, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0}";
  if (tmp.find("{") == 0);
    tmp = tmp.substr(tmp.find("{") + 1, tmp.length());
    if (tmp.find("}") == tmp.length() - 1)
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
  return (OK);
}

emsg		Ia::faim(void)
{
  int		t;

  t = this->_inv["nourriture"];
  if (t < 50)
    return (OK);
  else
    return (KO);
}

emsg		Ia::move_rd(void) const
{
  unsigned int	rd;

  rd = rand() % 3;
  if (rd == 0)
    ; //snd("avance");
  else if (rd == 1)
    ; //snd("gauche");
  else
    ; //snd("droite");
  return (OK);
}

emsg		Ia::move_to(int cas)
{
  if (cas == 1 || cas == 8 || cas == 2)
    ; //return (snd("avance"));
  else if (cas == 7 || cas == 5 || cas == 4 || cas == 6)
    ; //return (snd("droite"));
  else if (cas == 3)
    ; //return (snd("gauche"));
  else
    ; //return (snd("broadcast HERE" + this->_lvl);
  return (OK);
}

std::map<std::string, int>	Ia::ref(void)
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

void				Ia::what(void)
{
  std::vector<std::string>	vec;
  std::map<std::string, int>	r;

  r = this->ref();
  for (std::map<std::string, int>::iterator it = r.begin() ; it != r.end() ; ++it)
    {
      if (this->_inv[it->first] < it->second)
	vec.push_back(it->first);
    }
  this->_ressource = vec;
  std::cout << "----- WHAT ----" << std::endl;
  for (std::vector<std::string>::iterator it = vec.begin() ; it != vec.end() ; ++it)
    {
      std::cout << *it << std::endl;
    }
  std::cout << "---------------" << std::endl;
}

emsg				Ia::check_inv(void)
{
  what();
  if (this->_ressource.size() == 0)
    return (OK);
  else
    return (KO);
}

static int	count_player(const std::vector<std::string> &see)
{
  std::string	tmp;
  std::string	cut;
  int		p;

  p = 0;
  if (see.size() <= 0)
    return (-1);
  tmp = see[0];
  while (tmp.find("joueur") != std::string::npos)
    {
      p += 1;
      cut = tmp.substr(0, tmp.find("joueur"));
      tmp = tmp.substr(tmp.find("joueur") + 6, tmp.length());
      tmp = cut + tmp;
    }
  std::cout << "----" << tmp << "----" << std::endl;
  return (p);
}

std::vector<std::string>	Ia::voir(void)
{
  std::string			tmp;
  std::vector<std::string>	vec;
  std::vector<std::string>	need;
  std::vector<int>		where;
  int				i;

  i = 0;
  ; //tmp = snd("voir");
  tmp = "{joueur joueur joueur linemate deraumere,,, thystame,, nourriture,,,,, thystame,,,,,}";
  if (tmp.find("{") == 0 && tmp.find("}") == tmp.length() - 1)
    {
      tmp = tmp.substr(tmp.find("{") + 1, tmp.length());
      tmp = tmp.substr(0, tmp.find("}"));
    }
  while (tmp != "")
    {
      vec.push_back(tmp.substr(0, tmp.find(",")));
      if (tmp.find(",") >= 0 && tmp.find(",") <= tmp.length())
	tmp = tmp.substr(tmp.find(",") + 1);
      else
	tmp = "";
    }
  std::cout << "-------------------------" << std::endl;
  what();
  std::cout << "-------------------------" << std::endl;
  /*for (std::vector<std::string>::iterator it = vec.begin() ; it != vec.end() ; ++it)
    {
      for (std::vector<std::string>::iterator ti = this->_ressource.begin() ; ti != this->_ressource.end() ; ++ti)
	{
	  if ((*it).find((*ti)) != std::string::npos)
	    std::cout << "-----------------------------------------------> " << i << std::endl;
	}
      std::cout << "--[" << *it << "]--"<< std::endl;
      i++;
    }*/
  vide_case(vec);
  return (vec);
}

emsg		Ia::msg_list(void) const
{
  if (this->_msg.size() == 0)
    return (KO);
  else
    return (OK);
}

std::vector<std::string>	cut_msg(std::string msg)
{
  std::vector<std::string>	cut;

  msg = msg.substr(8, msg.length());
  cut.push_back(msg.substr(0, msg.find(",")));
  if (msg.find(", ") != std::string::npos)
    msg = msg.substr(msg.find(", ") + 2, msg.length() - 1);
  else if (msg.find(",") != std::string::npos)
    msg = msg.substr(msg.find(",") + 1, msg.length() - 1);
  if ((msg.find("RENFORT") != std::string::npos ||
       msg.find("NEED") != std::string::npos ||
       msg.find("ACCEPT") != std::string::npos ||
       msg.find("THANKS") != std::string::npos ||
       msg.find("JOIN") != std::string::npos ||
       msg.find("BREAK") != std::string::npos) && msg.find(' ') != std::string::npos)
    cut.push_back(msg.substr(0, msg.find(' ') - 1));
  msg = msg.substr(0, msg.find(' ') - 1);
  cut.push_back(msg);
  return (cut);
}

emsg				Ia::check_msg(void)
{
  std::vector<std::string>		cut;
  std::stringstream			ss;
  int					cas;
  int					lvl;
  std::list<std::string>::iterator	it;

  it = this->_msg.begin();
  if ((*it).find("message ") == 0)
    {
      cut = cut_msg((*it));
      if (cut.size() == 3)
	{
	  ss.str(cut[0]);
	  ss >> cas;
	  ss.clear();
	  ss.str(cut[2]);
	  ss >> lvl;
	  ss.clear();
	  if (cut[1] == "RENFORT" && this->_lvl == lvl && this->_chef == 0 && this->_slave == 0 && this->_group == 0)
	    {
	      this->_msg.clear();
	      return (RENFORT);
	    }
	  else if (cut[1] == "NEED" && this->_lvl == lvl && this->_slave == 0 && this->_wait == 1 &&
		   ((this->_chef == 0 && this->_group == 0) || (this->_chef == 1 && this->_group == 1)))
	    {
	      this->_msg.clear();
	      return (NEED);
	    }
	  else if (cut[1] == "ACCEPT" && this->_lvl == lvl && this->_slave == 0 && this->_group == 0 && this->_wait == 0)
	    {
	      this->_msg.clear();
	      return (ACCEPT);
	    }
	  else if (cut[1] == "THANKS" && this->_lvl == lvl && this->_chef == 1 && this->_group == 1 && this->_wait == 1)
	    {
	      this->_msg.clear();
	      return (THANKS);
	    }
	  else if (cut[1] == "JOIN" && this->_lvl == lvl && this->_slave == 1 && this->_group == 1)
	    {
	      this->_msg.clear();
	      return (JOIN);
	    }
	  else if (cut[1] == "BREAK" && this->_lvl == lvl && this->_slave == 1 && this->_group == 1)
	    {
	      this->_msg.clear();
	      return (BREAK);
	    }
	}
    }
  this->_msg.pop_front();
  return (KO);
}

int		Ia::max_member(void)
{
  if (this->_chef == 1)
    {
      switch (this->_lvl)
	{
	case 1:
	  return (1);
	  break;
	case 2:
	  return (2);
	  break;
	case 3:
	  return (2);
	  break;
	case 4:
	  return (4);
	  break;
	case 5:
	  return (4);
	  break;
	case 6:
	  return (6);
	  break;
	case 7:
	  return (6);
	  break;
	default:
	  break;
	}
    }
  return (-1);
}

emsg		Ia::make(void)
{
  std::stringstream	ss;
  std::string		lvl;

  ss << this->_lvl;
  lvl = ss.str();
  ss.clear();
  if (this->_member == 0)
    this->_member += 1;
  if (this->_member < max_member())
    {
      this->_wait = 1;
      ; //return (return (snd("broadcast RENFORT " + lvl)));
    }
  else
    {
      this->_wait = 1;
      return (STOP);
    }
}

emsg		Ia::renfort(void)
{
  std::stringstream	ss;
  std::string		lvl;

  ss << this->_lvl;
  lvl = ss.str();
  ss.clear();
  ; //return (snd("broadcast NEED " + lvl));
}

emsg		Ia::need(void)
{
  std::stringstream	ss;
  std::string		lvl;

  ss << this->_lvl;
  lvl = ss.str();
  ss.clear();
  this->_wait = 1;
  ; //return (snd("broadcast ACCEPT " + lvl));
}

emsg		Ia::accept(void)
{
  std::stringstream	ss;
  std::string		lvl;

  ss << this->_lvl;
  lvl = ss.str();
  ss.clear();
  this->_slave = 1;
  this->_group = 1;
  ; //return (snd("broadcast THANKS " + lvl));
}

emsg		Ia::thanks(void)
{
  std::stringstream	ss;
  std::string		lvl;

  ss << this->_lvl;
  lvl = ss.str();
  ss.clear();
  this->_chef = 1;
  this->_group = 1;
  this->_member += 1;
}

emsg		Ia::join(void)
{
  std::stringstream	ss;
  std::string		lvl;

  ss << this->_lvl;
  lvl = ss.str();
  ss.clear();
  ; //return (snd("broadcast JOIN " + lvl));
}

emsg		Ia::break_group(void)
{
  std::stringstream	ss;
  std::string		lvl;

  ss << this->_lvl;
  lvl = ss.str();
  ss.clear();
  ; //return (snd("broadcast BREAK " + lvl));
}

emsg		Ia::incantation()
{
  std::string	msg;

  ;//msg = snd("incantation");
  return (UP);
}

emsg		Ia::level_up()
{

}

emsg		Ia::brk(void)
{
  this->_group = 0;
  this->_slave = 0;
  this->_chef = 0;
  this->_member = 0;
  this->_wait = 0;
  return (OK);
}

emsg		Ia::pose_objet(void)
{
  std::map<std::string, int>	r;

  r = ref();
  for (std::map<std::string, int>::iterator it = r.begin() ; it != r.end() ; ++it)
    {
      while (it->second > 0)
	{
	  ; //snd("pose " + it->first);
	  it->second -= 1;
	  this->_inv[it->first] -= 1;
	}
    }
  return (INCANT);
}

emsg		Ia::check_group(void)
{
  if (this->_member == max_member())
    return (OK);
  else
    return (KO);
}

emsg				Ia::vide_case(const std::vector<std::string> &see)
{
  std::string			tmp;
  std::vector<std::string>	take;
  std::string			word;

  if (see.size() <= 0)
    return (ERROR);
  tmp = see[0];
  while (tmp != "")
    {
      if (tmp.find(" ") != std::string::npos)
	{
	  take.push_back(tmp.substr(0, tmp.find(" ")));
	  tmp = tmp.substr(tmp.find(" ") + 1, tmp.length());
	}
      else
	{
	  take.push_back(tmp.substr(0, tmp.length()));
	  tmp = "";
	}
    }
  for (std::vector<std::string>::iterator it = take.begin(); it != take.end(); ++it)
    {
      if (*it != "joueur")
	{
	  //snd("prend " + *it);
	  std::cout << "prend " + *it << std::endl;
	}
    }
  return (POSE);
}

emsg				Ia::check_inc(void)
{
  std::vector<std::string>	see;
  int				p;

  see = voir();
  p = count_player(see);
  if (p < max_member())
    return (JOIN);
  else
    return (vide_case(see));
}

emsg		Ia::prendre_pierre(void)
{
  ; //return (snd("prend " + this->_ressource[0]));
}

emsg		Ia::prendre_nourriture(void) const
{
  ; // return (snd("prend nourriture"));
}

emsg		Ia::check_case(void)
{
  std::vector<std::string>	see;

  see = this->voir();
}


int				main(int ac, char **av)
{
  Ia				bot;
  std::map<std::string, int>	tmp;

  if (ac < 4)
    std::cout << "Usage : ./ia [host] [port] [team]" << std::endl;
  tmp = bot.getInv();
  for (std::map<std::string, int>::iterator it = tmp.begin() ; it != tmp.end() ; ++it)
    std::cout << it->first << " : " << it->second<< std::endl;
  bot.maj_inv();

  tmp = bot.getInv();
  for (std::map<std::string, int>::iterator it = tmp.begin() ; it != tmp.end() ; ++it)
    std::cout << it->first << " : " << it->second<< std::endl;

  bot.voir();
}
