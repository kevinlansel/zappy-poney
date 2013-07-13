//
// Memory.hpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Fri Jul 12 15:35:32 2013 gery baudry
// Last update Sat Jul 13 16:52:15 2013 gery baudry
//

#ifndef				MEMORY___
# define			MEMORY___

#include			<vector>
#include			<SFML/Graphics.hpp>
#include			"Player.hpp"
#include			"Case.hpp"
#include			"Oeuf.hpp"

class				Memory
{
public:
  Memory();
  virtual ~Memory();

public:
  std::vector<Player>		getPliste() const;
  std::vector<Case>		getMap() const;
  std::vector<Oeuf>		getOeuf() const;
  void				pushCase(const Case &);
  void				DrawRec(sf::RenderWindow &);

private:
  std::vector<Player>		_pliste;
  std::vector<Case>		_map;
  std::vector<Oeuf>		_oeuf;
};

#endif
