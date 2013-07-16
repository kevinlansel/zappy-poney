//
// Case.hpp for zappy in /home/peelou/SVN/zappy-poney/client/CouillePutePlus
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon Jul  1 11:11:59 2013 gery baudry
// Last update Tue Jul 16 11:17:19 2013 florian dewulf
//

#ifndef			CASE__
# define		CASE__

#include		<SFML/Graphics.hpp>
#include		<vector>

class			Case
{
public:
  Case(const sf::Vector2f<float> &, int, int);
  virtual			~Case();

public:
  sf::RectangleShape		getRectangle() const;
  std::vector<int>		getInv() const;

public:
  void				setRessource(int, int, int, int, int, int, int);
  void				changeColor();

private:
  sf::RectangleShape		_rectangle;
  int				_x;
  int				_y;
  int				_ress[7];
};

#endif
