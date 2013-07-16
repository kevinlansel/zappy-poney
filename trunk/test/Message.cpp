//
// Message.cpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Mon Jul 15 23:38:38 2013 florian dewulf
// Last update Tue Jul 16 14:37:14 2013 florian dewulf
//

#include	"Message.hpp"

int		toInt(const std::string &);

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
  this->ptr["msz"] = &Message::setSizeMap;
  this->ptr["bct"] = &Message::setCaseContent;
  this->ptr["tna"] = &Message::addTeamName;
  this->ptr["pnw"] = &Message::newPlayer;
  this->ptr["ppo"] = &Message::setPosPlayer;
  this->ptr["plv"] = &Message::setLvlPlayer;
  this->ptr["pin"] = &Message::setInvPlayer;
  this->ptr["pex"] = &Message::expulsePlayer;
  this->ptr["pbc"] = &Message::broadcastPlayer;
  this->ptr["pic"] = &Message::beginIncant;
  this->ptr["pie"] = &Message::endIncant;
  this->ptr["pfk"] = &Message::eggPop;
  this->ptr["pdr"] = &Message::dropRess;
  this->ptr["pgt"] = &Message::takeRess;
  this->ptr["pdi"] = &Message::dead;
  this->ptr["enw"] = &Message::eggOnCase;
  this->ptr["eht"] = &Message::eggSpawn;
  this->ptr["ebo"] = &Message::eggConnexion;
  this->ptr["edi"] = &Message::eggDead;
  this->ptr["sgt"] = &Message::setTime;
  this->ptr["seg"] = &Message::endGame;
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
  std::cout << this->vec[0] << " - " << this->vec[1] << " - " << this->vec[2] << std::endl;
  if ((vec.size() > 0 && this->vec[0] != "pic" && this->pattern.find(this->vec[0]) != this->pattern.end() &&
       vec.size() == static_cast<unsigned int>(this->pattern[this->vec[0]])) || (vec.size() > 0 && this->vec[0] != "pic" && vec.size() >= 5))
    return ((this->*ptr[this->vec[0]])(mem));
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
  if (std::find(mem->getTeamlist().begin(), mem->getTeamlist().end(), vec[1]) == mem->getTeamlist().end())
    mem->getTeamlist().push_back(vec[1]);
  return (true);
}

bool		Message::newPlayer(Memory *mem)
{
  mem->getPlayerlist().push_back(new Player(toInt(vec[1]), toInt(vec[2]), toInt(vec[3]), toInt(vec[4]), toInt(vec[5]), vec[6]));
  mem->getPlayerlist().back()->setCase(mem->getCase(toInt(this->vec[1]), toInt(this->vec[2])));
  return (true);
}

bool		Message::setPosPlayer(Memory *mem)
{
  std::list<Player *>	list = mem->getPlayerlist();

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
  std::list<Player *>	list = mem->getPlayerlist();

  for (std::list<Player *>::iterator it = list.begin() ; it != list.end() ; ++it)
    if ((*it)->getId() == toInt(this->vec[1]))
      (*it)->setLvl(toInt(this->vec[2]));
  return (true);
}

bool		Message::setInvPlayer(Memory *mem)
{
  std::list<Player *>	list = mem->getPlayerlist();

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
  std::list<Player *>	list = mem->getPlayerlist();

  for (std::list<Player *>::iterator it = list.begin() ; it != list.end() ; ++it)
    if ((*it)->getId() == toInt(this->vec[1]))
      (*it)->drop(toInt(vec[2]));
  return (true);
}

bool		Message::takeRess(Memory *mem)
{
  std::list<Player *>	list = mem->getPlayerlist();

  for (std::list<Player *>::iterator it = list.begin() ; it != list.end() ; ++it)
    if ((*it)->getId() == toInt(this->vec[1]))
      (*it)->take(toInt(vec[2]));
  return (true);
}

bool		Message::dead(Memory *mem)
{
  std::list<Player *>	list = mem->getPlayerlist();

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
  mem->getOeuf().push_back(new Oeuf(toInt(vec[1]), toInt(vec[3]), toInt(vec[4])));
  return (true);
}

bool		Message::eggSpawn(Memory *mem)
{
  (void)(mem);
  return (true);
}

bool		Message::eggConnexion(Memory *mem)
{
  std::list<Oeuf *>	list = mem->getOeuf();

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
  (void)mem;
  std::cout << "L'équipe " << this->vec[1] << " a gagné" << std::endl;
  return (false);
}
