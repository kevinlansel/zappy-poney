//
// Memory.hpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Fri Jul 12 15:35:32 2013 gery baudry
// Last update Fri Jul 12 16:16:49 2013 gery baudry
//

#ifndef				MEMORY___
# define			MEMORY___

#include			<vector>
#include			"Player.hpp"
#include			"Case.hpp"

class				Memory
{
public:
  Memory();
  virtual ~Memory();

public:
  std::vector<Player>		getPliste() const;
  std::vector<Case>		getMap() const;

private:
  std::vector<Player>		_pliste;
  std::vector<Case>		_map;
};

#endif
