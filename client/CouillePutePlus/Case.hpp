//
// Case.hpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon Jul  1 11:11:59 2013 gery baudry
// Last update Mon Jul  1 12:05:12 2013 gery baudry
//

#ifndef			CASE__
# define		CASE__

#include		<SFML/Graphics.hpp>

class			Case
{
public:
  Case();
  ~Case();

public:
  void				setPosition(const sf::Vector2f &);
  sf::RectangleShape		getRectangle() const;
private:
  sf::RectangleShape		rectangle;

};

#endif
