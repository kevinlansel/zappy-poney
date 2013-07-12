//
// Player.cpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Tue Jul  2 10:35:58 2013 gery baudry
// Last update Fri Jul 12 15:21:48 2013 gery baudry
//

#include		"Player.hpp"
#include		<sstream>

Player::Player(sf::Vector2i pos, int id, int nourriture, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame, int orientation, int level, std::string team) : _pos(pos), _id(id), _nourriture(nourriture), _linemate(linemate), _deraumere(deraumere), _sibur(sibur), _mendiane(mendiane), _phiras(phiras), _thystame(thystame), _orientation(orientation), _level(level), _image(level), _teamname(team)
{
}

Player::~Player()
{
}

std::string			Player::doTextPlayer(sf::Vector2<int> souris)
{
  std::stringstream		inv;

  inv << "Inventaire du player \nX = " << souris.x << " Y = " << souris.y << "\nNourriture = " << this->_nourriture << " \nLinemate = " << this->_linemate << " \nDeraumere = " << this->_deraumere << " \nSibur = " << this->_sibur << " \nMediane = " << this->_mendiane << " \nPhiras = " << this->_phiras << " \nThystame = " << this->_thystame << " \nLevel = " << this->_level << " \nTeam Name =" << this->_teamname;
  // std::cout << inv.str() << std::endl;
  return (inv.str());
}


//
//			Getter
//

sf::Vector2i			Player::getPosition() const
{
  return (this->_pos);
}

int				Player::getNourriture() const
{
  return (this->_nourriture);
}

int				Player::getLinemate() const
{
  return (this->_linemate);
}

int				Player::getDeraumere() const
{
  return (this->_deraumere);
}

int				Player::getSibur() const
{
  return (this->_sibur);
}

int				Player::getMendiane() const
{
  return (this->_mendiane);
}

int				Player::getPhiras() const
{
  return (this->_phiras);
}

int				Player::getThystame() const
{
  return (this->_thystame);
}

int				Player::getLevel() const
{
  return (this->_level);
}

Personnage			Player::getImage() const
{
  return (this->_image);
}

std::string			Player::getTeamname() const
{
  return (this->_teamname);
}

int				Player::getOrientation() const
{
  return (this->_orientation);
}

int				Player::getId() const
{
  return (this->_id);
}

//
//		Setter
//

void				Player::setPosition(const sf::Vector2i &pos)
{
  this->_pos = pos;
}

void				Player::setNourriture(int val)
{
  this->_nourriture = val;
}

void				Player::setLinemate(int val)
{
  this->_linemate = val;
}

void				Player::setDeraumere(int val)
{
  this->_deraumere = val;
}

void				Player::setSibur(int val)
{
  this->_sibur = val;
}

void				Player::setMendiane(int val)
{
  this->_mendiane = val;
}

void				Player::setPhiras(int val)
{
  this->_phiras = val;
}

void				Player::setThystame(int val)
{
  this->_thystame = val;
}

void				Player::setLevel(int val)
{
  this->_level = val;
}

void				Player::setImage(int val)
{
  this->_image = Personnage(val);
}

void				Player::setTeamname(std::string team)
{
  this->_teamname = team;
}

void				Player::setOrientation(int val)
{
  this->_orientation = val;
}
