//
// Message.hpp for Message in /home/haz3/projet/zappy-poney/client/display
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Mon Jul  8 15:02:08 2013 Maxime Wojciak
// Last update Tue Jul  9 15:06:24 2013 Maxime Wojciak
//

#ifndef		MESSAGE__
#define		MESSAGE__

#include	<SFML/Graphics.hpp>
#include	<iostream>
#include	"Case.hpp"

class	Message {
public:
  Message();
  ~Message();

public:
  void		setPex(/*liste de joueur*/);
  void		setPbc(std::string, std::string);
  void		setPic(int, int,int, std::string);
  void		setPie(int, int, int, int);
  void		setPfk(int, int);
  void		setPdr(int, int);
  void		setPgt(int, int);
  void		setPdi(int);
  void		setEnw(int, int, int, int);
  void		setEht(int);
  void		setEbo(int);
  void		setEdi(int);
  void		setSgt(int);
  void		setSeg(std::string);
  void		setSmg(std::string);
  void		setPnw(int, int, int, int, int, std::string);
  void		setSuc();
  void		setSbp();
private:
  sf::Text	text;
  sf::Font	font;
  sf::Music	sound;
};

#endif		/* !MESSAGE__ */
