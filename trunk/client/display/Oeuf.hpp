//
// Oeuf.hpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Tue Jul  9 10:05:20 2013 gery baudry
// Last update Tue Jul  9 10:09:52 2013 gery baudry
//

#ifndef		OEUF__
# define	OEUF__

#include	<vector>
#include	"Window.hpp"

class		Oeuf
{
public:
  Oeuf();
  virtual ~Oeuf();

private:
  int			_id;
  bool			_eclo;
  std::vector<Oeuf>	_liste;
};

#endif
