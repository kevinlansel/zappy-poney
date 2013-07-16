//
// Memory.cpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Fri Jul 12 15:37:57 2013 gery baudry
// Last update Tue Jul 16 18:25:25 2013 florian dewulf
//

#include			"Memory.hpp"

Memory::Memory() : _win(sf::VideoMode(RES_X, RES_Y), "Client Zappy"/*, sf::Style::Fullscreen*/), _sizex(0), _sizey(0)
{
  sf::Texture		tmp;

  if (tmp.loadFromFile("./ressources/pictures/oeuf.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[0] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/aquali.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[1] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/evoli.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[2] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/givrali.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[3] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/mentali.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[4] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/noctali.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[5] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/phyllali.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[6] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/pyroli.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[7] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/voltali.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[8] = tmp;

  //-----------------//

  if (tmp.loadFromFile("./ressources/pictures/nourriture.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[9] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/linemate.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[10] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/deraumere.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[11] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/sibur.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[12] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/mendiane.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[13] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/phiras.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[14] = tmp;
  if (tmp.loadFromFile("./ressources/pictures/thystame.png") == false)
    throw Except("Fail on loading ressources");
  this->_lvlsprite[15] = tmp;
}

Memory::~Memory()
{
}

std::list<Player *>		Memory::getPlayerlist() const
{
  return (this->_player);
}

Case				*Memory::getCase(int x, int y) const
{
  std::cout << "x= " << x << "y = " << y << std::endl;
  if (this->_case.size() >= static_cast<unsigned int>(y) && this->_case[y].size() >= static_cast<unsigned int>(x))
    return (this->_case[y][x]);
  std::cout << "scout" << std::endl;
  return (NULL);
}

void				Memory::setSizeMap(int x, int y)
{
  if (x > 0 && y > 0)
    {
      this->_sizex = (RES_X - 200) / x;
      this->_sizey = (RES_Y - 100) / y;
      sf::Vector2<float>	vec(this->_sizex, this->_sizey);
      for (int tmpy = 0 ; tmpy < y ; ++tmpy)
	{
	  std::vector<Case *>	casetmp;

	  for (int tmpx = 0; tmpx < x ; ++tmpx)
	    casetmp.push_back(new Case(vec, tmpx, tmpy));
	  this->_case.push_back(casetmp);
	}
    }
}

int				Memory::getX() const
{
  return (this->_sizex);
}

int				Memory::getY() const
{
  return (this->_sizey);
}

std::list<Oeuf *>		Memory::getOeuf() const
{
  return (this->_oeuf);
}

void				Memory::drawCase()
{
  float				positionx[] = {this->_sizex / 1.75, this->_sizex - this->_sizex * 0.2,
					       this->_sizex / 1.75, this->_sizex - this->_sizex * 0.2,
					       this->_sizex / 1.75, this->_sizex - this->_sizex * 0.2,
					       this->_sizex / 1.75};
  float				positiony[] = {0, 0, this->_sizey * 0.2, this->_sizey * 0.2,
					       this->_sizey * 0.45, this->_sizey * 0.45, this->_sizey * 0.70};
  sf::Vector2<float>            vecscale(this->_sizex * 0.2 / 640, this->_sizey * 0.2 / 840);

  for (std::vector<std::vector<Case *> >::iterator it = this->_case.begin() ; it != this->_case.end() ; ++it)
    for (std::vector<Case *>::iterator it2 = it->begin() ; it2 != it->end() ; ++it2)
      {
	this->_win.draw((*it2)->getRectangle());
	for (unsigned int i = 0 ; i < 7 ; ++i)
	  {
	    sf::Sprite		sp(this->_lvlsprite[9 + i]);
	    sp.setPosition(sf::Vector2<float>(positionx[i], positiony[i]));
	    sp.scale(vecscale);
	    this->_win.draw(sp);
	  }
      }
}

void				Memory::drawPlayer()
{
  sf::Vector2<float>		vecscale(this->_sizex * 0.4 / 140, this->_sizey * 0.4 / 140);

  for (std::list<Player *>::iterator it = this->_player.begin() ; it != this->_player.end() ; ++it)
    if ((*it)->getLvl() >= 1 && (*it)->getLvl() <= 8)
      {
	sf::Sprite	sp(this->_lvlsprite[(*it)->getLvl()]);
	sp.setPosition(sf::Vector2<float>((*it)->getX() * this->_sizex, (*it)->getY() * this->_sizey));
	sp.scale(vecscale);
	this->_win.draw(sp);
      }
}

void				Memory::drawOeuf()
{
  int				sizecasex = this->_sizex / RES_X;
  int				sizecasey = this->_sizey / RES_Y;
  sf::Vector2<float>		vecscale(sizecasex * 0.4 / 140, sizecasey * 0.4 / 140);

  for (std::list<Player *>::iterator it = this->_player.begin() ; it != this->_player.end() ; ++it)
      {
	sf::Sprite	sp(this->_lvlsprite[0]);
	sp.setPosition(sf::Vector2<float>((*it)->getX() * sizecasex, (*it)->getY() * sizecasey + sizecasey / 2));
	sp.scale(vecscale);
	this->_win.draw(sp);
      }
}

std::list<std::string>		Memory::getTeamlist() const
{
  return (this->_team);
}

void				Memory::clear_win()
{
  this->_win.clear();
}

void				Memory::display_win()
{
  this->_win.display();
}

void				Memory::modifCase(int id, Case *c)
{
  for (std::list<Player *>::iterator it = this->_player.begin() ; it != this->_player.end() ; ++it)
    if ((*it)->getId() == id)
      (*it)->setCase(c);
}

void				Memory::modiflastCase(Case *c)
{
  std::cout << c->getX() << std::endl;
  this->_player.back()->setCase(c);
}
