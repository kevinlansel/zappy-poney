//
// Message.cpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Mon Jul 15 23:38:38 2013 florian dewulf
// Last update Tue Jul 16 15:01:26 2013 florian dewulf
//

#include	"Message.hpp"

Message::Message()
{
  this->pattern["msz"] = 3;
  this->pattern["bct"] = 10;
  this->pattern["tna"] = 1;
  this->pattern["pnw"] = 7;
  this->pattern["ppo"] = 5;
  this->pattern["plv"] = 3;
  this->pattern["pin"] = 11;
  this->pattern["pex"] = 2;
  this->pattern["pbc"] = 3;
  this->pattern["pie"] = 4;
  this->pattern["pfk"] = 2;
  this->pattern["pdr"] = 3;
  this->pattern["pgt"] = 3;
  this->pattern["pdi"] = 2;
  this->pattern["enw"] = 5;
  this->pattern["eht"] = 2;
  this->pattern["ebo"] = 2;
  this->pattern["edi"] = 2;
  this->pattern["sgt"] = 2;
  this->pattern["seg"] = 2;
}

Message::~Message()
{
}

void	Message::init()
{
  this->ptr["msz"] = &Interpret::setSizeMap;
  this->ptr["bct"] = &Interpret::setCaseContent;
  this->ptr["tna"] = &Interpret::addTeamName;
  this->ptr["pnw"] = &Interpret::newPlayer;
  this->ptr["ppo"] = &Interpret::setPosPlayer;
  this->ptr["plv"] = &Interpret::setLvlPlayer;
  this->ptr["pin"] = &Interpret::setInvPlayer;
  this->ptr["pex"] = &Interpret::expulsePlayer;
  this->ptr["pbc"] = &Interpret::broadcastPlayer;
  this->ptr["pic"] = &Interpret::beginIncant;
  this->ptr["pie"] = &Interpret::endIncant;
  this->ptr["pfk"] = &Interpret::eggPop;
  this->ptr["pdr"] = &Interpret::dropRess;
  this->ptr["pgt"] = &Interpret::takeRess;
  this->ptr["pdi"] = &Interpret::dead;
  this->ptr["enw"] = &Interpret::eggOnCase;
  this->ptr["eht"] = &Interpret::eggSpawn;
  this->ptr["ebo"] = &Interpret::eggConnexion;
  this->ptr["edi"] = &Interpret::eggDead;
  this->ptr["sgt"] = &Interpret::setTime;
  this->ptr["seg"] = &Interpret::endGame;
}

bool		Message::work(const std::string &str, Memory *mem)
{
  std::stringstream	ss;
  std::string		part;
  Interpret		inter;

  ss.str(str);
  while ((ss >> part) && part != "")
    {
      this->vec.push_back(part);
      part = "";
    }
  std::cout << "Size vec : " << this->vec.size() << std::endl;
  std::cout << "before if" << std::endl;
  if ((vec.size() > 0 && this->vec[0] != "pic" && this->pattern.find(this->vec[0]) != this->pattern.end() &&
       vec.size() == static_cast<unsigned int>(this->pattern[this->vec[0]])) || (vec.size() > 0 && this->vec[0] != "pic" && vec.size() >= 5))
    {
      bool b;
      bool	(Interpret::*func)(Memory *);

      std::cout << "YOOO" << std::endl;
      inter.setVec(this->vec);
      std::cout << "YUUUU" << std::endl;
      func = ptr[this->vec[0]];
      b = (inter.*func)(mem);
      std::cout << "Coucou" << std::endl;
      return (b);
    }
  this->vec.clear();
  return (true);
}
