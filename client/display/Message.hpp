//
// Message.hpp for Message in /home/haz3/projet/zappy-poney/client/display
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Mon Jul  8 15:02:08 2013 Maxime Wojciak
// Last update Tue Jul  9 15:46:46 2013 Maxime Wojciak
//

#ifndef				MESSAGE__
#define				MESSAGE__

#include			<SFML/Graphics.hpp>
#include			<SFML/Audio.hpp>
#include			<SFML/Window.hpp>
#include			<vector>
#include			<iostream>
#include			"Case.hpp"

class				Message
{
public:
  Message(std::vector<Case>);
  ~Message();

public:
  void				setPex(/*liste de joueur*/);
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

private:
  sf::Text			text;
  sf::Font			font;
  sf::Music			sound;
  std::vector<Case>		_map;
};

#endif		/* !MESSAGE__ */
