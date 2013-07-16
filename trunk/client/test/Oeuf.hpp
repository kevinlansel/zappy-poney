//
// Oeuf.cpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Tue Jul 16 13:20:24 2013 florian dewulf
// Last update Tue Jul 16 13:26:39 2013 florian dewulf
//

#ifndef		OEUF_HPP__
# define	OEUF_HPP__

#include	<string>

class		Oeuf
{
public:
  Oeuf(int, int, int);
  virtual	~Oeuf();

  int		getId() const;
  int		getX() const;
  int		getY() const;

private:
  int		x;
  int		y;
  int		id;
};

#endif
