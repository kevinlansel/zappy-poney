//
// Message.cpp for Message in /home/haz3/projet/zappy-poney/client/display
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Mon Jul  8 15:02:02 2013 Maxime Wojciak
// Last update Mon Jul  8 18:02:22 2013 Maxime Wojciak
//

#include	"Message.hpp"

Message::Message() {
  this->font.loadFromFile("../ressources/fonts/Sansation_Bold.ttf");
}

Message::~Message() {
}

void	Message::setPex(/*joueur dans la liste*/) {
  /*if (joueur dans la liste && joueur existe) */
  std::cout << "Joueur expulser (Supression du joueur)" << std::endl;
  // delete(joueur dans la liste);
}

void	Message::setPbc(std::string broadcast, std::string _player) {
  if (broadcast && _player) {
    std::cout << "Le joueur X effectue un broadcast" << broadcast << std::endl;
  }
  else
    setSbp();
}

void	Message::setPic(int _x, int _y, int _level, std::string _player) {
  if (_x && _y && _level && _player) {
    // Change color de la case en x et y
    std::cout << "Incantation du joueur" << _player << std::endl;
  }
  else
    setSbp();
}

void	Message::setPie(int _x, int _y, int _level, int _r) {
  if (_x && _y && _level && _r) {
    if (_r == 1)
      {
	// Incantation réussie.
	// Change Color(défaut) de la case _x, _y
	// ../ressources/audio/bloup.mp3
      }
  }
  setSbp();
}

void	Message::setPfk(int _x, int _y) {
  if (_x && _y) {
    // Pond un oeuf
    // Change color Case
    // Son
    // +1 Oeuf attribut de la case
  }
  else
    setSbp();
}

void	Message::setPdr(int _n, int _i) {
  if (_n && _i) {
  // numero de joueur _n jette ressource numero de ressource _i
  // -1 ressource _i --> player _n
  // +1 ressource _i --> player _n
  }
  else
    setSbp();
}

void	Message::setPgt(int _n, int _i) {
  if (_n && _i) {
    // numero de joueur _n jette ressource numero de ressource _i
    // +1 ressource _i --> player _n
    // -1 ressource _i --> player _n
  }
  else
    setSbp();
}

void	Message::setPdi(int _n) {
  if (_n) {
    std::string text = "Le joueur " + _n + " est mort de faim";
    this->text(text, this->font, 15);
    this->text.move(sf::Vector2f(/*position*/));
    // delete joueur _n de la liste;
  }
  else
    setSbp();
}

void	Message::setEnw(int _n, int _e, int _x, int _y) {
  if (_n && _e && _x && _y) {
    std::string textOeuf = "L'oeuf " + _e + " est présent sur la case " _x + ", " + _y;
    std::string textPlay = "Le joueur " + _n + " est présent sur la case " _x + ", " + _y;
    this->text(textOeuf, this->font, 15);
    this->text(textPlay, this->font, 15);
    this->text.move(sf::Vector2f(/*position du display*/));
  }
  else
    setSbp();
}

void	Message::setEht(int _e) {
  if (_e) {
    std::string text = "L'oeuf " + _e + " à eclot";
    this->text(text, this->font, 15);
    this->text.move(sf::Vector2f(/*position du display*/));
    this->sound.loadFromFile("../ressources/audio/bloup.mp3");
  }
  else
    setSbp();
}

void	Message::setEbo(int _e) {
  if (_e) {
    std::string text = "Un joueur c'est connecté pour l'oeuf " + _e;
    this->text(text, this->font, 15);
    this->text.move(sf::Vector2f(/*position du display*/));
    // delete _e oeuf
  }
  else
    setSbp();
}

void	Message::setEdi(int _e) {
  if (_e) {
    std::string text = "L'oeuf " + _e " est mort de faim";
    this->text(text, this->font, 15);
    this->text.move(sf::Vector2f(/*position du display*/));
    // delete oeuf _e
  }
  else
    setSbp();
}

void	Message::setSgt(int _T) {
  if (_T) {
    std::string text = "Unité de temps du serveur: " + _T;
    this->text(text, this->font, 15);
    this->text.move(sf::Vector2f(/*position du display*/));
  }
  else
    setSbp();
}

void	Message::setSeg(std::string _N) {
  if (_N) {
    std::string text = "Fin du jeu, L'équipe " + _N + " remporte la partie";
    this->text(text, this->font, 15);
    this->text.move(sf::Vector2f(/*position du display*/));
    // delete equipe _N de la liste
  }
  else
    setSbp();
}

void	Message::setSmg(std::string _M) {
  if (_M) {
    std::string text = "Serveur: " + _M;
    this->text(text, this->font, 15);
    this->text.move(sf::Vector2f(/*position du display*/));
  }
  else
    setSbp();
}

void	Message::setPnw(int _n, int _x, int _y, int _O, int _L, std::string _N) {
  if (_n && _x && _y && _O && _L && _M) {
    std::string _text = _n.c_str() + " case x: " + _x + ", y: " + _y + " Orientation: " + _O + " Level: " + _L + " Equipe: " + _N;
    this->text(text, this->font, 15);
    this->text.move(sf::Vector2f(/*position du display*/));
  }
  else
    setSbp();
}

void	Message::setSuc() {
  this->text("Bad Command", this->font, 15);
  this->text.move(sf::Vector2f(/*position du display*/));
}

void	Message::setSbp() {
  this->text("Bad Parameter", this->font, 15);
  this->text.move(sf::Vector2f(/*position du display*/));
}
