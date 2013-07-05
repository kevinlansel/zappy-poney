//
// Player.hpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Tue Jul  2 10:34:25 2013 gery baudry
// Last update Fri Jul  5 11:13:08 2013 gery baudry
//

#ifndef				PLAYER__
# define			PLAYER__

#include			<SFML/Graphics.hpp>
#include			"Personnage.hpp"

class				Player
{
public:
  Player(sf::Vector2i, int, int, int, int, int, int, int, int, std::string);
  virtual			~Player();
  std::string			doTextPlayer(sf::Vector2<int>);

public:
  sf::Vector2i			getPosition() const;
  int				getNourriture() const;
  int				getLinemate() const;
  int				getDeraumere() const;
  int				getSibur() const;
  int				getMendiane() const;
  int				getPhiras() const;
  int				getThystame() const;
  int				getLevel() const;
  Personnage			getImage() const;
  std::string			getTeamname() const;

public:
  void				setPosition(const sf::Vector2i &);
  void				setNourriture(int);
  void				setLinemate(int);
  void				setDeraumere(int);
  void				setSibur(int);
  void				setMendiane(int);
  void				setPhiras(int);
  void				setThystame(int);
  void				setLevel(int);
  void				setImage(int);
  void				setTeamname(std::string);

private:
  sf::Vector2i			_pos;
  int				_nourriture;
  int				_linemate;
  int				_deraumere;
  int				_sibur;
  int				_mendiane;
  int				_phiras;
  int				_thystame;
  int				_level;
  Personnage			_image;
  std::string			_teamname;
};

#endif
