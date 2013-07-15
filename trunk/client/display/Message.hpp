//
// Message.hpp for Message in /home/haz3/projet/zappy-poney/client/display
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Mon Jul  8 15:02:08 2013 Maxime Wojciak
// Last update Mon Jul 15 12:45:59 2013 gery baudry
//

#ifndef				MESSAGE__
#define				MESSAGE__

#include			<SFML/Graphics.hpp>
#include			<SFML/Audio.hpp>
#include			<SFML/Window.hpp>
#include			<vector>
#include			<iostream>
#include			"Case.hpp"
#include			"Player.hpp"
#include			"Memory.hpp"

class				Message
{
public:
  Message(Memory *);
  ~Message();

public:
  void				setPex(int);
  void				setPbc(std::string, std::string);
  std::vector<Case>		setPic(int, int,int, std::string);
  std::vector<Case>		setPie(int, int, int, int);
  std::vector<Case>		setPfk(int, int);
  void				setPdr(int, int);
  void				setPgt(int, int);
  void				setPdi(int);
  void				setEnw(int, int, int, int);
  void				setEht(int);
  void				setEbo(int);
  void				setEdi(int);
  void				setSgt(int);
  void				setSeg(std::string);
  void				setSmg(std::string);
  void				setPnw(int, int, int, int, int, std::string);
  void				setSuc();
  void				setSbp();
  int				checkString(std::string &);

public:
  sf::Text			getText() const;
  
private:
  sf::Text			text;
  sf::Font			font;
  sf::Music			sound;
  Memory			*_mem;
  std::map<int, std::string>	_map;
};

#endif		/* !MESSAGE__ */
