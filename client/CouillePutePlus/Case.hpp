//
// Case.hpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon Jul  1 11:11:59 2013 gery baudry
// Last update Tue Jul  2 10:38:27 2013 gery baudry
//

#ifndef			CASE__
# define		CASE__

#include		<SFML/Graphics.hpp>

class			Case
{
public:
  Case(int, int, int, int, int, int, int);
  ~Case();

public:
  sf::RectangleShape		getRectangle() const;
  sf::Vector2f			getPosition() const;
  int				getNourriture() const;
  int				getLinemate() const;
  int				getDeraumere() const;
  int				getSibur() const;
  int				getMendiane() const;
  int				getPhiras() const;
  int				getThystame() const;

public:
  void				setPosition(const sf::Vector2f &);
  void				setNourriture(int);
  void				setLinemate(int);
  void				setDeraumere(int);
  void				setSibur(int);
  void				setMendiane(int);
  void				setPhiras(int);
  void				setThystame(int);


private:
  sf::RectangleShape		rectangle;
  sf::Vector2f			_pos;
  int				_nourriture;
  int				_linemate;
  int				_deraumere;
  int				_sibur;
  int				_mendiane;
  int				_phiras;
  int				_thystame;
};

#endif
