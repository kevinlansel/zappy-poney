//
// Player.hpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Tue Jul  2 10:34:25 2013 gery baudry
// Last update Tue Jul  2 14:48:22 2013 gery baudry
//

#ifndef				PLAYER__
# define			PLAYER__

#include			<SFML/Graphics.hpp>

class				Player
{
public:
  Player();
  ~Player();

public:
  sf::Vector2f			getPosition() const;
  int				getNourriture() const;
  int				getLinemate() const;
  int				getDeraumere() const;
  int				getSibur() const;
  int				getMendiane() const;
  int				getPhiras() const;
  int				getThystame() const;
  int				getLevel() const;

public:
  void				setPosition(const sf::Vector2f &);
  void				setNourriture(int);
  void				setLinemate(int);
  void				setDeraumere(int);
  void				setSibur(int);
  void				setMendiane(int);
  void				setPhiras(int);
  void				setThystame(int);
  void				setLevel(int);

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
};

#endif
