//
// Message.cpp for Message in /home/haz3/projet/zappy-poney/client/display
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Mon Jul  8 15:02:02 2013 Maxime Wojciak
// Last update Mon Jul 15 21:20:31 2013 gery baudry
//

#include	"Message.hpp"

std::string	tonton(int);

Message::Message(Memory *mem): _mem(mem)
{
  this->font.loadFromFile("../ressources/fonts/Sansation_Bold.ttf");
}

Message::Message(const Message &d): _mem(d.getMem())
{
}

Message::~Message() {
}

Memory			*Message::getMem() const
{
  return (this->_mem);
}

sf::Text		Message::getText() const
{
  return (this->text);
}

void	Message::setPex(int _n) {
  if (_n) {
    for (std::vector<Player>::iterator it = this->_mem->getPliste().begin(); it != this->_mem->getPliste().end(); ++it)
      {
	if (it->getId() == _n)
	  this->_mem->getPliste().erase(it);
      }
    std::string texte = "Le joueur toto à été expulser";
    this->text = sf::Text(texte, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
    // delete(joueur dans la liste);
  }
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
      for (std::vector<Case>::iterator it = this->_mem->getMap().begin(); it != this->_mem->getMap().end(); it++)
	{
	  sf::Vector2f tmp(it->getPosition());
	  if (tmp.x <= _x && tmp.y <= _y)
	    it->setCasecolor(sf::Color(201, 0, 0));
	}
      std::string text = "Incantation de joueur " + _player + " au level " + tonton(_level) + " sur la case " + tonton(_x) + "-" + tonton(_y);
      this->text = sf::Text(text, this->font, 15);
      this->text.move(sf::Vector2f(1110, 900));
    }
  else
    setSbp();
  return (this->_mem->getMap());
}

std::vector<Case>	Message::setPie(int _x, int _y, int _level, int _r) {
  if (_x && _y && _level && _r)
    {
      if (_r == 1)	// Incantation réussie.
	{
	  for (std::vector<Case>::iterator it = this->_mem->getMap().begin(); it != this->_mem->getMap().end(); it++)
	    {
	      sf::Vector2f tmp(it->getPosition());
	      if (tmp.x <= _x && tmp.y <= _y)
		it->setCasecolor(sf::Color(201, 0, 0));
	    }
	  std::string text = "L'incantation de level " + tonton(_level) + "sur la case " + tonton(_x) + ", " + tonton(_y) + " à réussi";
	  this->text = sf::Text(text, this->font, 15);
	  this->text.move(sf::Vector2f(1110, 900));
	  this->sound.openFromFile("../ressources/audio/bloup.mp3");
	}
    }
  else
    setSbp();
  return (this->_mem->getMap());
}

std::vector<Case>	Message::setPfk(int _x, int _y) {
  if (_x && _y)
    {
      Oeuf		_noeuf(1);
      this->_mem->getOeuf().push_back(_noeuf);
      //Oeuf	oeuf;						// Pond un oeuf
      for (std::vector<Case>::iterator it = this->_mem->getMap().begin(); it != this->_mem->getMap().end(); it++)
	{
	  sf::Vector2f tmp(it->getPosition());
	  if (tmp.x <= _x && tmp.y <= _y)
	    it->setCasecolor(sf::Color(255, 0, 0));    // Change color de la case en x et y
	}
      this->sound.openFromFile("../ressources/audio/bloup.mp3");	// Son
      //this-case += Oeuf +1;
      // +1 Oeuf attribut de la case
      std::string text = "Un oeuf à été pondu sur la case " + tonton(_x) + ", " + tonton(_y);
      this->text = sf::Text(text, this->font, 15);
      this->text.move(sf::Vector2f(1110, 900));
    }
  else
    setSbp();
  return (this->_mem->getMap());
}

void	Message::setPdr(int _n, int _i) {
  if (_n && _i) {
    for (std::vector<Player>::iterator it = this->_mem->getPliste().begin(); it != this->_mem->getPliste().end(); ++it)
      {
	if (it->getId() == _n)
	  {
	    sf::Vector2i		pos(sf::Vector2i(it->getPosition()));
	    for (std::vector<Case>::iterator it2 = this->_mem->getMap().begin(); it2 != this->_mem->getMap().end(); ++it2)
	      {
		if (pos.x <= it2->getPosition().x && pos.y <= it2->getPosition().y)
		  {
		    if (_i == 0){
		      it->setNourriture(-1);
		      it2->setNourriture(1);
		    }
		    else if (_i == 1){
		      it->setLinemate(-1);
		      it2->setLinemate(1);
		    }
		    else if (_i == 2){
		      it->setDeraumere(-1);
		      it2->setDeraumere(1);
		    }
		    else if (_i == 3){
		      it->setSibur(-1);
		      it2->setSibur(1);
		    }
		    else if (_i == 4){
		      it->setMendiane(-1);
		      it2->setMendiane(1);
		    }
		    else if (_i == 5){
		      it->setPhiras(-1);
		      it2->setPhiras(1);
		    }
		    else if (_i == 6){
		      it->setThystame(-1);
		      it2->setThystame(1);
		    }
		  }
	      }
	  }
      }
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
    for (std::vector<Player>::iterator it = this->_mem->getPliste().begin(); it != this->_mem->getPliste().end(); ++it)
      {
	if (it->getId() == _n)
	  {
	    sf::Vector2i		pos(sf::Vector2i(it->getPosition()));
	    for (std::vector<Case>::iterator it2 = this->_mem->getMap().begin(); it2 != this->_mem->getMap().end(); ++it2)
	      {
		if (pos.x <= it2->getPosition().x && pos.y <= it2->getPosition().y)
		  {
		    if (_i == 0){
		      it->setNourriture(1);
		      it2->setNourriture(-1);
		    }
		    else if (_i == 1){
		      it->setLinemate(1);
		      it2->setLinemate(-1);
		    }
		    else if (_i == 2){
		      it->setDeraumere(1);
		      it2->setDeraumere(-1);
		    }
		    else if (_i == 3){
		      it->setSibur(1);
		      it2->setSibur(-1);
		    }
		    else if (_i == 4){
		      it->setMendiane(1);
		      it2->setMendiane(-1);
		    }
		    else if (_i == 5){
		      it->setPhiras(1);
		      it2->setPhiras(-1);
		    }
		    else if (_i == 6){
		      it->setThystame(1);
		      it2->setThystame(-1);
		    }
		  }
	      }
	  }
      }
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
      for (std::vector<Player>::iterator it = this->_mem->getPliste().begin(); it != this->_mem->getPliste().end(); ++it)
	{
	  if (it->getId() == _n)
	    this->_mem->getPliste().erase(it);
	}
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
    for (std::vector<Oeuf>::iterator it = this->_mem->getOeuf().begin(); it != this->_mem->getOeuf().end(); ++it)
      {
	if (it->getId() == _e)
	  {
	    std::string text = "Un joueur c'est connecté pour l'oeuf " + tonton(_e);
	    this->text = sf::Text(text, this->font, 15);
	    this->text.move(sf::Vector2f(1110, 900));
	    // delete _e oeuf
	  }
      }
  }
  else
    setSbp();
}

void	Message::setEdi(int _e) {
  if (_e) {
    for (std::vector<Oeuf>::iterator it = this->_mem->getOeuf().begin(); it != this->_mem->getOeuf().end(); ++it)
      {
	if (it->getId() == _e)
	  {
	    std::string text = "L'oeuf " + tonton(_e) + " est mort de faim";
	    this->text = sf::Text(text, this->font, 15);
	    this->text.move(sf::Vector2f(1110, 900));
	  }
      }
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
  std::cout << "set pnw !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
  if (_n && _x && _y && _O && _L && _N != "") {
    std::cout << "creation player" << std::endl;
    sf::Vector2i	pos(_x, _y);
    Player		player(pos, _n, 10, 0, 0, 0, 0, 0, 0, _O, _L, _N);
    this->_mem->getPliste().push_back(player);
    std::string _text = tonton(_n) + " case x: " + tonton(_x) + ", y: " + tonton(_y) + " Orientation: " + tonton(_O) + " Level: " + tonton(_L) + " Equipe: " + _N;
    this->text = sf::Text(_text, this->font, 15);
    this->text.move(sf::Vector2f(1110, 900));
  }
  else
    setSbp();
}

void			Message::setPlv(int l)
{
  (double)l;
}

void			Message::setPpo(int _x, int _y, int _O)
{
  for (std::vector<Player>::iterator it = this->_mem->getPliste().begin(); it != this->_mem->getPliste().end(); ++it)
    it->doTextPlayer(it->getPosition());
}

void			Message::setPin(/*int _x, int _y, int _n, int _l, int _d, int _s, int _m, int _p, int _t*/)
{
  for (std::vector<Player>::iterator it = this->_mem->getPliste().begin(); it != this->_mem->getPliste().end(); ++it)
    it->doTextPlayer(it->getPosition());
}

void	Message::setSuc() {
  this->text = sf::Text("Bad Command", this->font, 15);
  this->text.move(sf::Vector2f(1110, 900));
}

void	Message::setSbp() {
  this->text = sf::Text("Bad Parameter", this->font, 15);
  this->text.move(sf::Vector2f(1110, 900));
}
