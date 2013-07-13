//
// Oeuf.hpp for zappy in /home/peelou/SVN/zappy-poney/client/display
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Tue Jul  9 10:05:20 2013 gery baudry
// Last update Sat Jul 13 17:03:27 2013 gery baudry
//

#ifndef		OEUF__
# define	OEUF__

#include	<vector>

class		Oeuf
{
public:
  Oeuf(int);
  virtual ~Oeuf();

public:
  int			getId() const;

private:
  int			_id;
  bool			_eclo;
};

#endif
