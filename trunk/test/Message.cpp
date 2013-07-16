//
// Message.cpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Mon Jul 15 23:38:38 2013 florian dewulf
// Last update Tue Jul 16 12:56:03 2013 florian dewulf
//

#include	"Message.hpp"

Message::Message(const std::string &str)
{
  ptr["msz"] = 3;
  ptr["bct"] = 10;
  ptr["tna"] = 1;
  ptr["pnw"] = 7;
  ptr["ppo"] = 5;
  ptr["plv"] = 3;
  ptr["pin"] = 11;
  ptr["pex"] = 2;
  ptr["pbc"] = 3;
  ptr["pie"] = 4;
  ptr["pfk"] = 2;
  ptr["pdr"] = 3;
  ptr["pgt"] = 3;
  ptr["pdi"] = 2;
  ptr["enw"] = 5;
  ptr["eht"] = 2;
  ptr["ebo"] = 2;
  ptr["edi"] = 2;
  ptr["sgt"] = 2;
  ptr["seg"] = 2;
}

void	Message::init()
{
  ptr["msz"] = &Message::setSizeMap;
  ptr["bct"] = &Message::setCaseContent;
  ptr["tna"] = &Message::addTeamName;
  ptr["pnw"] = &Message::newPlayer;
  ptr["ppo"] = &Message::setPosPlayer;
  ptr["plv"] = &Message::setLvlPlayer;
  ptr["pin"] = &Message::setInvPlayer;
  ptr["pex"] = &Message::expulsePlayer;
  ptr["pbc"] = &Message::broadcastPlayer;
  ptr["pic"] = &Message::beginIncant;
  ptr["pie"] = &Message::endIncant;
  ptr["pfk"] = &Message::eggPop;
  ptr["pdr"] = &Message::dropRess;
  ptr["pgt"] = &Message::takeRess;
  ptr["pdi"] = &Message::dead;
  ptr["enw"] = &Message::eggOnCase;
  ptr["eht"] = &Message::eggSpawn;
  ptr["ebo"] = &Message::eggConnexion;
  ptr["edi"] = &Message::eggDead;
  ptr["sgt"] = &Message::setTime;
  ptr["seg"] = &Message::endGame;
}

bool		Message::work(const std::string &str, Memory *mem)
{
  std::stringstream	ss;
  std::string		part;

  ss.str(str);
  while ((ss >> part) && part != "")
    {
      this->vec.push_back(part);
      part = "";
    }
  if ((vec.size() > 0 && vec[0] != "pic" && this->pattern.find(vec[0]) != this->pattern.end() &&
       vec.size() == this->pattern[vec[0]]) || (vec.size() > 0 && vec[0] != "pic" && vec.size() >= 5))
    return ((this->*ptr[vec[0]])(mem));
  this->vec.clear();
  return (true);
}

bool		Message::setSizeMap(Memory *mem)
{
  mem->setSizeMap(toInt(this->vec[1]), toInt(this->vec[2]));//crée toute la map de case
  return (true);
}

bool		Message::setCaseContent(Memory *mem)
{
  Case		*c;

  c = mem->getCase(toInt(this->vec[1]), toInt(this->vec[2]));
  if (c)
    c->setRessource(toInt(this->vec[3]), toInt(this->vec[4]), toInt(this->vec[5]), toInt(this->vec[6]), toInt(this->vec[7]), toInt(this->vec[8]), toInt(this->vec[9]));
  return (true);
}

bool		Message::addTeamName(Memory *mem)
{
  if (std::find(mem->getTeamlist().begin, mem->getTeamlist().end(), vec[1]) == mem->getTeamlist().end())
    mem->getTeamlist().push_back(vec[1]);
  return (true);
}

bool		Message::newPlayer(Memory *mem)
{
  mem->getPlayerlist().push_back(new Player(toInt(vec[1]), toInt(vec[2]), toInt(vec[3]), toInt(vec[4]), toInt(vec[5]), toInt(vec[6])));
  mem->getPlayerlist().back->setCase(mem->getCase(toInt(this->vec[1]), toInt(this->vec[2])));
  return (true);
}

bool		Message::setPosPlayer(Memory *mem)
{
  std::list<Player *>	list mem->getPlayerlist();

  for (std::list<Player *>::iterator it = list.begin() ; it != list.end() ; ++it)
    if ((*it)->getId() == toInt(this->vec[1]))
      {
	(*it)->majPos(toInt(vec[2]), toInt(vec[3]), toInt(vec[4]));
	(*it)->setCase(mem->getCase(toInt(this->vec[2]), toInt(this->vec[3])));
      }
  return (true);
}

bool		Message::setLvlPlayer(Memory *mem)
{
  std::list<Player *>	list mem->getPlayerlist();

  for (std::list<Player *>::iterator it = list.begin() ; it != list.end() ; ++it)
    if ((*it)->getId() == toInt(this->vec[1]))
      (*it)->setLvl(toInt(this->vec[2]));
  return (true);
}

bool		Message::setInvPlayer(Memory *mem)
{
  std::list<Player *>	list mem->getPlayerlist();

  for (std::list<Player *>::iterator it = list.begin() ; it != list.end() ; ++it)
    if ((*it)->getId() == toInt(this->vec[1]))
      {
	(*it)->majPos(toInt(vec[2]), toInt(vec[3]), (*it)->getDirec());
	(*it)->setCase(mem->getCase(toInt(this->vec[2]), toInt(this->vec[3])));
	(*it)->majInv(toInt(vec[4]), toInt(vec[5]), toInt(vec[6]), toInt(vec[7]), toInt(vec[8]), toInt(vec[9]), toInt(vec[10]));
      }
  return (true);
}

bool		Message::expulsePlayer(Memory *mem)
{
  (void)(mem);
  return (true);
}

bool		Message::broadcastPlayer(Memory *mem)
{
  (void)(mem);
  return (true);
}

bool		Message::beginIncant(Memory *mem)
{
  Case		*c;

  c = mem->getCase(toInt(this->vec[1]), toInt(this->vec[2]));
  if (c)
    c->changeColor();
  return (true);
}

bool		Message::endIncant(Memory *mem)
{
  Case		*c;

  c = mem->getCase(toInt(this->vec[1]), toInt(this->vec[2]));
  if (c)
    c->changeColor();
  return (true);
}

bool		Message::eggPop(Memory *mem)
{
  (void)(mem);
  return (true);
}

bool		Message::dropRess(Memory *mem)
{
  std::list<Player *>	list mem->getPlayerlist();

  for (std::list<Player *>::iterator it = list.begin() ; it != list.end() ; ++it)
    if ((*it)->getId() == toInt(this->vec[1]))
      (*it)->drop(toInt(vec[2]));
  return (true);
}

bool		Message::takeRess(Memory *mem)
{
  std::list<Player *>	list mem->getPlayerlist();

  for (std::list<Player *>::iterator it = list.begin() ; it != list.end() ; ++it)
    if ((*it)->getId() == toInt(this->vec[1]))
      (*it)->take(toInt(vec[2]));
  return (true);
}

bool		Message::dead(Memory *mem)
{
  std::list<Player *>	list mem->getPlayerlist();

  for (std::list<Player *>::iterator it = list.begin() ; it != list.end() ; ++it)
    if ((*it)->getId() == toInt(this->vec[1]))
      {
	delete *it;
	list.erase(it);
	break;
      }
  return (true);
}

bool		Message::eggOnCase(Memory *mem)
{
  mem->getEgglist(new Oeuf(toInt(vec[1]), toInt(vec[3]), toInt(vec[4])));
  return (true);
}

bool		Message::eggSpawn(Memory *mem)
{
  (void)(mem);
  return (true);
}

bool		Message::eggConnexion(Memory *mem)
{
  std::list<Oeuf *>	list mem->getOeuflist();

  for (std::list<Oeuf *>::iterator it = list.begin() ; it != list.end() ; ++it)
    if ((*it)->getId() == toInt(this->vec[1]))
      {
	delete *it;
	list.erase(it);
	break;
      }
  return (true);
}

bool		Message::eggDead(Memory *mem)
{
  this->eggConnexion(mem);
  return (true);
}

bool		Message::setTime(Memory *mem)
{
  (void)(mem);
  return (true);
}

bool		Message::endGame(Memory *mem)
{
  std::cout << "L'équipe " << this->vec[1] << " a gagné" << std::endl;
  return (false);
}
