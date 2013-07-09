//
// Message.cpp for Message in /home/haz3/projet/zappy-poney/client/display
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Mon Jul  8 15:02:02 2013 Maxime Wojciak
// Last update Tue Jul  9 16:26:25 2013 Maxime Wojciak
//

#include	"Message.hpp"

std::string	tonton(int);

Message::Message(std::vector<Case> map): _map(map) {
  this->font.loadFromFile("../ressources/fonts/Sansation_Bold.ttf");
}

Message::~Message() {
}

void	Message::setPex(/*joueur dans la liste*/) {
  /*if (joueur dans la liste && joueur existe) */
  std::string texte = "Le joueur toto à été expulser";
  this->text = sf::Text(texte, this->font, 15);
  this->text.move(sf::Vector2f(1110, 900));
  // delete(joueur dans la liste);
}

void	Message::setPbc(std::string broadcast, std::string _player) {
  if (broadcast != "" && _player != "") {
    std::string text = "Le joueur " + _player + " effectue un broadcast " + broadcast;
    this->text = sf::Text(text, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
  }
  else
    setSbp();
}

std::vector<Case>	Message::setPic(int _x, int _y, int _level, std::string _player) {
  if (_x && _y && _level && _player != "")
    {
      for (std::vector<Case>::iterator it = this->_map.begin(); it != this->_map.end(); it++)
	{
	  sf::Vector2f tmp(it->getPosition());
	  if (tmp.x <= _x && tmp.y <= _y)
	    {
	      //sf::RectangleShape rec = it->getRectangle();
	      it->getRectangle().setColorcase(sf::Color(201, 0, 0));    // Change color de la case en x et y
	    }
	}
      std::string text = "Incantation de joueur " + _player + " au level " + tonton(_level) + " sur la case " + tonton(_x) + "-" + tonton(_y);
      this->text = sf::Text(text, this->font, 15);
      this->text.move(sf::Vector2f(1110, 900));
    }
  else
    setSbp();
  return (this->_map);
}

  std::vector<Case>	Message::setPie(int _x, int _y, int _level, int _r) {
    if (_x && _y && _level && _r)
      {
	if (_r == 1)	// Incantation réussie.
	  {
	    for (std::vector<Case>::iterator it = this->_map.begin(); it != this->_map.end(); it++)
	      {
		sf::Vector2f tmp(it->getPosition());
		if (tmp.x <= _x && tmp.y <= _y)
		  sf::RectangleShape rec = it->getRectangle();
	      }
	    rec.setColorcase(sf::Color(201, 0, 0));    // Change color de la case en x et y
	    std::string text = "L'incantation de level " + tonton(_level) + "sur la case " + tonton(_x) + ", " + tonton(_y) + " à réussi";
	    this->text = sf::Text(text, this->font, 15);
	    this->text.move(sf::Vector2f(1110, 900));
	    this->sound.openFromFile("../ressources/audio/bloup.mp3");
	  }
      }
    else
      setSbp();
    return (this->_map);
  }

std::vector<Case>	Message::setPfk(int _x, int _y) {
  if (_x && _y)
    {
      //Oeuf	oeuf;						// Pond un oeuf
      for (std::vector<Case>::iterator it = this->_map.begin(); it != this->_map.end(); it++)
	{
	  sf::Vector2f tmp(it->getPosition());
	  if (tmp.x <= _x && tmp.y <= _y)
	    sf::RectangleShape rec = it->getRectangle();
	}
      rec.setColorcase(sf::Color(255, 0, 0));    // Change color de la case en x et y
      this->sound.openFromFile("../ressources/audio/bloup.mp3");	// Son
      //this-case += Oeuf +1;
      // +1 Oeuf attribut de la case
      std::string text = "Un oeuf à été pondu sur la case " + tonton(_x) + ", " + tonton(_y);
      this->text = sf::Text(text, this->font, 15);
      this->text.move(sf::Vector2f(1110, 900));
    }
  else
    setSbp();
  return (this->_map);
}

void	Message::setPdr(int _n, int _i) {
  if (_n && _i) {
    /* for (this->player) {
       this->PlayerRessource -1;
       this->CaseRessource +1;
       }*/
    std::string text = "Le joueur " + tonton(_n) + " jette la ressource " + tonton(_i) + " sur la case";
    this->text = sf::Text(text, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
    // Joueur jette une ressource sur la case
  }
  else
    setSbp();
}

void	Message::setPgt(int _n, int _i) {
  if (_n && _i) {
    /* for (this->player) {
       this->PlayerRessource +1;
       this->CaseRessource -1;
       }*/
    std::string text = "Le joueur " + tonton(_n) + " prend la ressource " + tonton(_i) + " de la case";
    this->text = sf::Text(text, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
    // Joueur prend une ressource de la case
  }
  else
    setSbp();
}

void	Message::setPdi(int _n) {
  if (_n) {
    std::string text = "Le joueur " + tonton(_n) + " est mort de faim";
    this->text = sf::Text(text, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
    // delete joueur _n de la liste;
  }
  else
    setSbp();
}

void	Message::setEnw(int _n, int _e, int _x, int _y) {
  if (_n && _e && _x && _y) {
    std::string textOeuf = "L'oeuf " + tonton(_e) + " est présent sur la case " + tonton(_x) + ", " + tonton(_y);
    std::string textPlay = "Le joueur " + tonton(_n) + " est présent sur la case " + tonton(_x) + ", " + tonton(_y);
    this->text = sf::Text(textOeuf, this->font, 15);
    this->text = sf::Text(textPlay, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
  }
  else
    setSbp();
}

void	Message::setEht(int _e) {
  if (_e) {
    std::string text = "L'oeuf " + tonton(_e) + " à eclot";
    this->text = sf::Text(text, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
    this->sound.openFromFile("../ressources/audio/bloup.mp3");
  }
  else
    setSbp();
}

void	Message::setEbo(int _e) {
  if (_e) {
    std::string text = "Un joueur c'est connecté pour l'oeuf " + tonton(_e);
    this->text = sf::Text(text, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
    // delete _e oeuf
  }
  else
    setSbp();
}

void	Message::setEdi(int _e) {
  if (_e) {
    std::string text = "L'oeuf " + tonton(_e) + " est mort de faim";
    this->text = sf::Text(text, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
    // delete oeuf _e
  }
  else
    setSbp();
}

void	Message::setSgt(int _T) {
  if (_T) {
    std::string text = "Unité de temps du serveur: " + tonton(_T);
    this->text = sf::Text(text, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
  }
  else
    setSbp();
}

void	Message::setSeg(std::string _N) {
  if (_N != "") {
    std::string text = "Fin du jeu, L'équipe " + _N + " remporte la partie";
    this->text = sf::Text(text, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
    // delete equipe _N de la liste
  }
  else
    setSbp();
}

void	Message::setSmg(std::string _M) {
  if (_M != "") {
    std::string text = "Serveur: " + _M;
    this->text = sf::Text(text, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
  }
  else
    setSbp();
}

void	Message::setPnw(int _n, int _x, int _y, int _O, int _L, std::string _N) {
  if (_n && _x && _y && _O && _L && _N != "") {
    std::string _text = tonton(_n) + " case x: " + tonton(_x) + ", y: " + tonton(_y) + " Orientation: " + tonton(_O) + " Level: " + tonton(_L) + " Equipe: " + _N;
    this->text = sf::Text(text, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
  }
  else
    setSbp();
}

void	Message::setSuc() {
  this->text = sf::Text("Bad Command", this->font, 15);
  this->text.move(sf::Vector2f(1110, 900));
}

void	Message::setSbp() {
  this->text = sf::Text("Bad Parameter", this->font, 15);
  this->text.move(sf::Vector2f(1110, 900));
}
