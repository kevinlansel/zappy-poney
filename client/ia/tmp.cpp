//
// tmp.cpp for zappy in /home/seth/System_unix/zappy-poney/client/ia
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Mon Jul 15 10:44:17 2013 kevin lansel
// Last update Tue Jul 16 22:19:33 2013 kevin lansel
//

#include	<vector>
#include	<iostream>
#include	<sstream>
#include	<cstdlib>
#include	<algorithm>
#include	"tmp.hpp"

Tmp::Tmp(int x, int y, std::string team) : _x(x), _y(y), _team(team), _lvl(1), _group(0), _slave(0), _chef(0), _member(0), _wait(0), _last_cmd(1), _silence(false), _answer(""), _futur(OK), _target("")
{
  //			{OK, KO, PREND, START, END}
  int		faim[] = {2, 5, 0, 0, 0};
  int		move_rd[] = {2, 2, 1, 0, 0};
  int		prendre_nourriture[] = {3, 1, 2, 0, 0};
  int		inventaire[] = {4, 4, 4, 0, 0};
  int		maj_inv[] = {0, 0, 4, 0, 0};
  int		what[] = {6, 12, 10, 0, 0};
  int		voir[] = {7, 7, 6, 0, 0};
  int		maj_voir[] = {8, 8, 7, 15, 0};
  int		where[] = {9, 1, 8, 0, 0};
  int		make_road[] = {10, 0, 11, 0, 0};
  int		follow_road[] = {10, 0, 11, 0, 0};
  int		prend_object[] = {3, 0, 0, 0, 0};
  int		check_group[] = {6, 0, 0, 0, 0};
  int		incantation[] = {12, 12, 12, 17, 14};
  int		maj_lvl[] = {0, 0, 0, 0, 0};
  int		vide_case[] = {0, 0, 0, 16, 0};
  int		pose_object[] = {0, 0, 0, 13, 0};
  int		stand[] = {0, 0, 0, 0, 14};

  int		lvl0[] = {0};
  int		lvl1[] = {2, 1, 3};
  int		lvl2[] = {6, 5, 7, 4, 8};
  int		lvl3[] = {12, 11, 13, 10, 14, 9, 15};
  int		lvl4[] = {20, 19, 21, 18, 22, 17, 23, 16, 24};
  int		lvl5[] = {30, 29, 31, 28, 32, 27, 33, 26, 34, 25, 35};
  int		lvl6[] = {42, 41, 43, 40, 44, 39, 45, 38, 46, 37, 47, 36, 48};
  int		lvl7[] = {56, 55, 57, 54, 58, 53, 59, 52, 60, 51, 61, 50, 62, 49, 63};
  int		lvl8[] = {72, 71, 73, 70, 74, 69, 75, 68, 76, 67, 77, 66, 78, 65, 79, 64, 80};

  this->_view.push_back(std::vector<int>(lvl0, lvl0 + sizeof(lvl0) / sizeof(int)));
  this->_view.push_back(std::vector<int>(lvl1, lvl1 + sizeof(lvl1) / sizeof(int)));
  this->_view.push_back(std::vector<int>(lvl2, lvl2 + sizeof(lvl2) / sizeof(int)));
  this->_view.push_back(std::vector<int>(lvl3, lvl3 + sizeof(lvl3) / sizeof(int)));
  this->_view.push_back(std::vector<int>(lvl4, lvl4 + sizeof(lvl4) / sizeof(int)));
  this->_view.push_back(std::vector<int>(lvl5, lvl5 + sizeof(lvl5) / sizeof(int)));
  this->_view.push_back(std::vector<int>(lvl6, lvl6 + sizeof(lvl6) / sizeof(int)));
  this->_view.push_back(std::vector<int>(lvl7, lvl7 + sizeof(lvl7) / sizeof(int)));
  this->_view.push_back(std::vector<int>(lvl8, lvl8 + sizeof(lvl8) / sizeof(int)));

  this->_inv.insert(std::pair<std::string, int>("nourriture", 10));
  this->_inv.insert(std::pair<std::string, int>("linemate", 0));
  this->_inv.insert(std::pair<std::string, int>("deraumere", 0));
  this->_inv.insert(std::pair<std::string, int>("sibur", 0));
  this->_inv.insert(std::pair<std::string, int>("mendiane", 0));
  this->_inv.insert(std::pair<std::string, int>("phiras", 0));
  this->_inv.insert(std::pair<std::string, int>("thystame", 0));

  this->_tab.push_back(std::vector<int>(faim, faim + sizeof(faim) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(move_rd, move_rd + sizeof(move_rd) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(prendre_nourriture, prendre_nourriture + sizeof(prendre_nourriture) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(inventaire, inventaire + sizeof(inventaire) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(maj_inv, maj_inv + sizeof(maj_inv) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(what, what + sizeof(what) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(voir, voir + sizeof(voir) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(maj_voir, maj_voir + sizeof(maj_voir) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(where, where + sizeof(where) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(make_road, make_road + sizeof(make_road) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(follow_road, follow_road + sizeof(follow_road) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(prend_object, prend_object + sizeof(prend_object) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(check_group, check_group + sizeof(check_group) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(incantation, incantation + sizeof(incantation) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(maj_lvl, maj_lvl + sizeof(maj_lvl) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(vide_case, vide_case + sizeof(vide_case) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(pose_object, pose_object + sizeof(pose_object) / sizeof(int)));
  this->_tab.push_back(std::vector<int>(stand, stand + sizeof(stand) / sizeof(int)));

  this->_ptr_func[FAIM] = (&Tmp::faim);
  this->_ptr_func[MOVE_RD] = (&Tmp::move_rd);
  this->_ptr_func[PRENDRE_NOURRITURE] = (&Tmp::prendre_nourriture);
  this->_ptr_func[INVENTAIRE] = (&Tmp::inventaire);
  this->_ptr_func[MAJ] = (&Tmp::maj_inv);
  this->_ptr_func[WHAT] = (&Tmp::what);
  this->_ptr_func[VOIR] = (&Tmp::voir);
  this->_ptr_func[MAJ_VOIR] = (&Tmp::maj_voir);
  this->_ptr_func[WHERE] = (&Tmp::where);
  this->_ptr_func[MAKE_ROAD] = (&Tmp::make_road);
  this->_ptr_func[FOLLOW_ROAD] = (&Tmp::follow_road);
  this->_ptr_func[PREND_OBJECT] = (&Tmp::prend_object);
  this->_ptr_func[CHECK_GROUP] = (&Tmp::check_group);
  this->_ptr_func[INCANTATION] = (&Tmp::incantation);
  this->_ptr_func[MAJ_LVL] = (&Tmp::maj_lvl);
  this->_ptr_func[VIDE_CASE] = (&Tmp::vide_case);
  this->_ptr_func[POSE_OBJECT] = (&Tmp::pose_object);
  this->_ptr_func[STAND] = (&Tmp::stand);
}

Tmp::~Tmp()
{

}

void				Tmp::setLvl(int lvl)
{
  this->_lvl = lvl;
}

void				Tmp::setGroup(int group)
{
  this->_group = group;
}

void				Tmp::setSlave(int slave)
{
  this->_slave = slave;
}

void				Tmp::setChef(int chef)
{
  this->_chef = chef;
}

void				Tmp::setMember(int member)
{
  this->_member = member;
}

void				Tmp::setWait(int wait)
{
  this->_wait = wait;
}

void				Tmp::setMsg(std::list<std::string> msg)
{
  this->_msg = msg;
}

void				Tmp::setInv(std::map<std::string, int> inv)
{
  this->_inv = inv;
}

void				Tmp::setRoad(std::list<std::vector<std::string> > road)
{
  this->_road = road;
}

void				Tmp::setRessource(std::vector<std::string> ressource)
{
  this->_ressource = ressource;
}

void				Tmp::setLast_cmd(int last_cmd)
{
  this->_last_cmd = last_cmd;
}

int				Tmp::getLvl(void) const
{
  return (this->_lvl);
}

int				Tmp::getGroup(void) const
{
  return (this->_group);
}

int				Tmp::getSlave(void) const
{
  return (this->_slave);
}

int				Tmp::getChef(void) const
{
  return(this->_chef);
}

int				Tmp::getMember(void) const
{
  return (this->_member);
}

int				Tmp::getWait(void) const
{
  return (this->_wait);
}

std::list<std::string>		Tmp::getMsg(void) const
{
  return (this->_msg);
}

std::map<std::string, int>	Tmp::getInv(void) const
{
  return (this->_inv);
}

std::list<std::vector<std::string> >	Tmp::getRoad(void) const
{
  return (this->_road);
}

std::vector<std::string>	Tmp::getRessource(void) const
{
  return (this->_ressource);
}

int				Tmp::getLast_cmd(void) const
{
  return (this->_last_cmd);
}

emsg		Tmp::faim(void)
{
  this->_last_cmd = FAIM;
  this->_silence = true;
  std::cout << this->_inv["nourriture"] << std::endl;
  if (this->_inv["nourriture"] < 50)
    {
      this->_futur = OK;
      return (OK);
    }
  else
    {
      this->_futur = KO;
      return (KO);
    }
}

emsg		Tmp::move_rd(void)
{
  unsigned int	rd;

  this->_silence = false;
  this->_last_cmd = MOVE_RD;
  rd = rand() % 16;
  if (rd == 0)
    snd("droite\n");
  else if (rd == 1)
    snd("gauche\n");
  else
    snd("avance\n");
  return (OK);
}

emsg		Tmp::prendre_nourriture(void)
{
  this->_silence = false;
  this->_last_cmd = PRENDRE_NOURRITURE;
  snd("prend nourriture\n");
  return (OK);
}

emsg		Tmp::maj_inv(void)
{
  std::string			tmp;
  std::vector<std::string>	vec;
  std::string			rec;
  std::string			sav;
  std::stringstream		ss;
  int				i;

  this->_last_cmd = MAJ;
  this->_silence = true;
  if (this->_answer == "")
    {
      this->_futur = KO;
      return (KO);
    }
  tmp = this->_answer;
  if (tmp.find("{") == 0)
    tmp = tmp.substr(tmp.find("{") + 1, tmp.length());
  if (tmp.find("}") == tmp.length() - 1)
    tmp = tmp.substr(0, tmp.find("}"));
  while (tmp != "")
    {
      vec.push_back(tmp.substr(0, tmp.find(",")));
      if (tmp.find(", ") != std::string::npos)
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
  this->_futur = OK;
  return (OK);
}

emsg		Tmp::inventaire(void)
{
  this->_silence = false;
  this->_last_cmd = INVENTAIRE;
  snd("inventaire\n");
  return (OK);
}

emsg				Tmp::voir(void)
{
  std::cout << "VOIR" << std::endl;

  this->_silence = false;
  this->_last_cmd = VOIR;
  snd("voir\n");
  return (OK);
}

emsg				Tmp::maj_voir(void)
{
  std::string			tmp;
  std::vector<std::string>	vec;

  this->_silence = true;
  this->_last_cmd = MAJ_VOIR;
  if (this->_answer == "")
    {
      this->_futur = KO;
      return (KO);
    }
  tmp = this->_answer;
  if (tmp.find("{") == 0 && tmp.find("}") == tmp.length() - 1)
    {
      tmp = tmp.substr(tmp.find("{") + 1, tmp.length());
      tmp = tmp.substr(0, tmp.find("}"));
    }
  while (tmp != "")
    {
      vec.push_back(tmp.substr(0, tmp.find(",")));
      if (tmp.find(",") != std::string::npos)
	tmp = tmp.substr(tmp.find(",") + 1);
      else
	tmp = "";
    }
  this->_see = vec;
  if (this->_group == 2)
    {
      this->_futur = START;
      return (START);
    }
  this->_futur = OK;
  return (OK);
}

emsg		Tmp::where(void)
{
  std::vector<int>		tmp;
  int				i;

  i = 0;
  this->_silence = true;
  this->_last_cmd = WHERE;
  for (std::vector<std::string>::iterator it = this->_see.begin() ; it != this->_see.end() ; ++it)
    {
      for (std::vector<std::string>::iterator ti = this->_ressource.begin() ; ti != this->_ressource.end() ; ++ti)
	{
	  if ((*it).find((*ti)) != std::string::npos)
	    tmp.push_back(i);
	}
      i++;
    }
  this->_where = tmp;
  if (this->_where.size() == 0)
    {
      this->_futur = KO;
      return (KO);
    }
  else
    {
      this->_futur = OK;
      return (OK);
    }
}

emsg				Tmp::make_road(void)
{
  int				x;
  int				y;
  int				line;
  std::vector<int>::iterator	c;
  std::vector<int>::iterator	tmp;
  std::vector<std::string>	road;
  unsigned int			len;

  len = 18;
  this->_silence = true;
  this->_last_cmd = MAKE_ROAD;
  for (std::vector<int>::iterator ti = this->_where.begin(); ti != this->_where.end(); ++ti)
    {
      line = 0;
      road.clear();
      for (std::vector<std::vector<int> >::iterator it = this->_view.begin(); it != this->_view.end(); ++it)
	{
	  x = 0;
	  if ((tmp = std::find (it->begin(), it->end(), *ti)) != it->end())
	    {
	      y = line;
	      c = tmp;
	      for (std::vector<int>::iterator ite = it->begin() ; ite != c ; ++ite)
		x++;
	      while (y > 0)
		{
		  road.push_back("avance\n");
		  y--;
		}
	      if (x != 0)
		{
		  if (x % 2 == 1)
		    {
		      road.push_back("gauche\n");
		      x = (x / 2) + 1;
		      while (x > 0)
			{
			  road.push_back("avance\n");
			  x--;
			}
		    }
		  else
		    {
		      road.push_back("droite\n");
		      x = x / 2;
		      while (x > 0)
			{
			  road.push_back("avance\n");
			  x--;
			}
		    }
		}
	      this->_road.push_back(road);
	    }
	  line++;
	}
    }
  std::vector<int>::iterator	wh = this->_where.begin();

  for (std::list<std::vector<std::string> >::iterator it = this->_road.begin() ; it != this->_road.end() ; ++it)
    {
      if (it->size() < len)
	{
	  len = it->size();
	  this->_cas = *wh;
	  this->_end_road = *it;
	}
      ++wh;
    }
  if (this->_end_road.size() != 0)
    {
      this->_futur = OK;
      return (OK);
    }
  else if (this->_end_road.size() == 0 && this->_where.size() != 0)
    {
      for (std::vector<std::string>::iterator it = this->_ressource.begin(); it != this->_ressource.end(); ++it)
	{
	  if (this->_see[this->_cas].find(*it) != std::string::npos)
	    {
	      this->_target = *it;
	      break;
	    }
	}
      this->_futur = PREND;
      return (PREND);
    }
  else
    {
      this->_futur = KO;
      return (KO);
    }
}

emsg				Tmp::follow_road(void)
{
  std::string			direction;

  this->_silence = true;
  this->_last_cmd = FOLLOW_ROAD;
  if (this->_end_road.size() != 0)
    {
      direction = this->_end_road[0];
      this->_end_road.erase(this->_end_road.begin());
    }
  snd(direction);
  if (this->_end_road.size() == 0)
    {
      for (std::vector<std::string>::iterator it = this->_ressource.begin(); it != this->_ressource.end(); ++it)
	{
	  if (this->_see[this->_cas].find(*it) != std::string::npos)
	    {
	      this->_target = *it;
	      break;
	    }
	}
      this->_futur = PREND;
      return (PREND);
    }
  else
    {
      this->_futur = OK;
      return (OK);
    }
}

emsg				Tmp::prend_object(void)
{
  std::string			tmp;

  this->_silence = false;
  this->_last_cmd = PREND_OBJECT;
  std::cout << "------------------------------------------- prend " << this->_target << std::endl;
  snd("prend " + this->_target + "\n");
  if (this->_see[0].find(this->_target) != std::string::npos)
    {
      tmp = this->_see[0].substr(0, this->_see[0].find(this->_target));
      tmp += this->_see[0].substr(this->_see[0].find(this->_target) + this->_target.length(), this->_see[0].length());
      this->_see[0] = tmp;
    }
  this->_target = "";
  this->_where.clear();
  this->_road.clear();
  return (OK);
}

std::map<std::string, int>	Tmp::ref(void)
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

emsg				Tmp::what(void)
{
  std::vector<std::string>	vec;
  std::map<std::string, int>	r;

  this->_silence = true;
  this->_last_cmd = WHAT;
  r = this->ref();
  for (std::map<std::string, int>::iterator it = r.begin() ; it != r.end() ; ++it)
    {
      if (this->_inv[it->first] < it->second)
	vec.push_back(it->first);
    }
  this->_ressource = vec;
  if (this->_road.size() != 0 && this->_where.size() != 0)
    {
      this->_futur = PREND;
      return (PREND);
    }
  else if (this->_ressource.size() != 0)
    {
      this->_futur = OK;
      return (OK);
    }
  else
    {
      std::cout << this->_lvl << std::endl;
      if (this->_lvl == 2)
	{
	  this->_futur = END;
	  return (END);
	}
      this->_futur = KO;
      return (KO);
    }
}

emsg		Tmp::check_group(void)
{
  this->_silence = true;
  this->_last_cmd = CHECK_GROUP;

  if (this->_lvl == 1)
    {
      this->_group = 2;
      this->_futur = OK;
      return (OK);
    }
  else
    {
      this->_futur = KO;
      return (KO);
    }
}

emsg		Tmp::stand(void)
{
  std::cout << "STAND" << std::endl;
  abort();
  this->_silence = false;
  this->_last_cmd = STAND;
  return (END);
}

emsg		Tmp::incantation(void)
{
  this->_silence = false;
  this->_last_cmd = INCANTATION;
  std::cout << "INCANTATION" << std::endl;
  snd("incantation\n");
  return (OK);
}

emsg		Tmp::maj_lvl(void)
{
  std::string		tmp;
  std::stringstream	ss;
  int			lvl;

  this->_silence = true;
  this->_last_cmd = MAJ_LVL;
  this->_futur = OK;
  if (this->_answer.find("niveau actuel :") != std::string::npos)
    {
      std::cout << this->_answer << std::endl;
      tmp = this->_answer.substr(this->_answer.find("niveau actuel :"), this->_answer.length());
      std::cout << "TMP ***** ---------------------------" << tmp << std::cout;
      ss.str(tmp);
      ss >> lvl;
      this->_lvl = lvl;
      ss.clear();
      std::cout << this->_lvl << std::endl;
    }
  return (OK);
}

emsg				Tmp::vide_case(void)
{
  std::string			tmp;
  std::string			take;
  std::map<int, std::string>	mat;
  int				v;

  mat.insert(std::pair<int, std::string>(1, "nourriture"));
  mat.insert(std::pair<int, std::string>(2, "linemate"));
  mat.insert(std::pair<int, std::string>(3, "deraumere"));
  mat.insert(std::pair<int, std::string>(4, "sibur"));
  mat.insert(std::pair<int, std::string>(5, "mendiane"));
  mat.insert(std::pair<int, std::string>(6, "phiras"));
  mat.insert(std::pair<int, std::string>(7, "thystame"));

  this->_silence = true;
  this->_last_cmd = VIDE_CASE;
  tmp = this->_see[0];
  std::cout << tmp << std::endl;
  abort();
  while (tmp != "")
    {
      v = 0;
      for (std::map<int, std::string>::iterator it = mat.begin() ; it != mat.end(); ++it)
	{
	  if (tmp.find(it->second) != std::string::npos)
	    {
	      take = it->second;
	      tmp = this->_see[0].substr(0, this->_see[0].find(it->second));
	      tmp += this->_see[0].substr(this->_see[0].find(it->second) + it->second.length(), this->_see[0].length());
	      this->_see[0] = tmp;
	      v = 1;
	      snd("prend " + take + "\n");
	      take = "";
	      break;
	    }
	  if (v == 0)
	    tmp = "";
	}
    }
  std::cout << "XXXXXXXXXXXXXXXXXXXXXXXX---" << this->_see[0] << "********************" << std::endl;
  this->_futur = START;
  return (START);
}

emsg					Tmp::pose_object(void)
{
  std::map<std::string, int>	r;
  int				i;

  r = ref();
  this->_silence = true;
  this->_last_cmd = POSE_OBJECT;
  for (std::map<std::string, int>::iterator it = r.begin() ; it != r.end() ; ++it)
    {
      i = it->second;
      while (it->second > 0 && this->_inv[it->first] > 0)
	{
	  std::cout << "pose " << it->first << std::endl;
	  snd("pose " + it->first + "\n");
	  std::cout << it->second << " :: " << this->_inv[it->first] << std::endl;
	  r[it->first] = i - 1;
	  this->_inv[it->first] -= 1;
	}
    }
  this->_futur = START;
  return (START);
}

void		Tmp::loop(gnl &getnext, const int socket)
{
  int		error = 0;
  fd_set	readfd;
  std::string	str;
  emsg		msg;

  this->_socket = socket;
  snd("avance\n");
  while (error != -1)
    {
      str = "";
      msg = NONE;// à define
      FD_ZERO(&readfd);
      FD_SET(socket, &readfd);
      if (this->_silence == true)
	msg = this->_futur;
      else if (getnext.getbuffer() == "" &&
	  (error = select(socket + 1, &readfd, NULL, NULL, NULL)) != -1)
	str = getnext.get_next_line();
      else
	str = getnext.get_answer();
      if (getnext.getError() == true)
	error = -1;
      if (str != "" && error != -1)
	{
	  /*if (this->last_cmd == CONNECT && isalpha(str))
	    msg = ;//connectnbr
	    else */
	  if (str == "mort")
	    error = -1;
	  else if (str.find("message ") == 0)
	    this->_msg.push_front(str);
	  else
	    msg = this->action(str);
	}
      this->_answer = str;
      std::cout << this->_answer << std::endl;
      if (msg != NONE && error != -1)
	this->do_action(msg);
    }
  close(socket);
}

emsg		Tmp::snd(const std::string &msg)
{
  write(this->_socket, msg.c_str(), msg.size());
  return (OK);
}

emsg		Tmp::action(std::string msg)
{
  if (msg == "ko")
    return (KO);
  else if (msg == "elevation en cours")
    {
      std::cout << msg << std::endl;
      return (START);
    }
  else if (msg.find("niveau actuel :") != std::string::npos)
    {
      std::cout << msg << std::endl;
      return (END);
    }
  else
    return (OK);
}

void		Tmp::do_action(const emsg state)
{
  (this->*(this->_ptr_func[this->_tab[this->_last_cmd][state]]))();
}
