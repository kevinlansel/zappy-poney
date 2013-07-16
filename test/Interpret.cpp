//
// Interpret.cpp for  in /home/lund/Projets/zappy-poney/test
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Tue Jul 16 14:44:57 2013 florian dewulf
// Last update Tue Jul 16 14:49:45 2013 florian dewulf
//

#include	"Interpret.hpp"

int		toInt(const std::string &);

bool		Interpret::setSizeMap(Memory *mem)
{
  std::cout << "Haha !\n" << std::endl;
  mem->setSizeMap(toInt(this->vec[1]), toInt(this->vec[2]));//crée toute la map de case
  std::cout << "Héhé !\n" << std::endl;
  return (true);
}

bool		Interpret::setCaseContent(Memory *mem)
{
  Case		*c;

  c = mem->getCase(toInt(this->vec[1]), toInt(this->vec[2]));
  if (c)
    c->setRessource(toInt(this->vec[3]), toInt(this->vec[4]), toInt(this->vec[5]), toInt(this->vec[6]), toInt(this->vec[7]), toInt(this->vec[8]), toInt(this->vec[9]));
  return (true);
}

bool		Interpret::addTeamName(Memory *mem)
{
  if (std::find(mem->getTeamlist().begin(), mem->getTeamlist().end(), vec[1]) == mem->getTeamlist().end())
    mem->getTeamlist().push_back(vec[1]);
  return (true);
}

bool		Interpret::newPlayer(Memory *mem)
{
  mem->getPlayerlist().push_back(new Player(toInt(vec[1]), toInt(vec[2]), toInt(vec[3]), toInt(vec[4]), toInt(vec[5]), vec[6]));
  mem->getPlayerlist().back()->setCase(mem->getCase(toInt(this->vec[1]), toInt(this->vec[2])));
  return (true);
}

bool		Interpret::setPosPlayer(Memory *mem)
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

bool		Interpret::setLvlPlayer(Memory *mem)
{
  std::list<Player *>	list = mem->getPlayerlist();

  for (std::list<Player *>::iterator it = list.begin() ; it != list.end() ; ++it)
    if ((*it)->getId() == toInt(this->vec[1]))
      (*it)->setLvl(toInt(this->vec[2]));
  return (true);
}

bool		Interpret::setInvPlayer(Memory *mem)
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

bool		Interpret::expulsePlayer(Memory *mem)
{
  (void)(mem);
  return (true);
}

bool		Interpret::broadcastPlayer(Memory *mem)
{
  (void)(mem);
  return (true);
}

bool		Interpret::beginIncant(Memory *mem)
{
  Case		*c;

  c = mem->getCase(toInt(this->vec[1]), toInt(this->vec[2]));
  if (c)
    c->changeColor();
  return (true);
}

bool		Interpret::endIncant(Memory *mem)
{
  Case		*c;

  c = mem->getCase(toInt(this->vec[1]), toInt(this->vec[2]));
  if (c)
    c->changeColor();
  return (true);
}

bool		Interpret::eggPop(Memory *mem)
{
  (void)(mem);
  return (true);
}

bool		Interpret::dropRess(Memory *mem)
{
  std::list<Player *>	list = mem->getPlayerlist();

  for (std::list<Player *>::iterator it = list.begin() ; it != list.end() ; ++it)
    if ((*it)->getId() == toInt(this->vec[1]))
      (*it)->drop(toInt(vec[2]));
  return (true);
}

bool		Interpret::takeRess(Memory *mem)
{
  std::list<Player *>	list = mem->getPlayerlist();

  for (std::list<Player *>::iterator it = list.begin() ; it != list.end() ; ++it)
    if ((*it)->getId() == toInt(this->vec[1]))
      (*it)->take(toInt(vec[2]));
  return (true);
}

bool		Interpret::dead(Memory *mem)
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

bool		Interpret::eggOnCase(Memory *mem)
{
  mem->getOeuf().push_back(new Oeuf(toInt(vec[1]), toInt(vec[3]), toInt(vec[4])));
  return (true);
}

bool		Interpret::eggSpawn(Memory *mem)
{
  (void)(mem);
  return (true);
}

bool		Interpret::eggConnexion(Memory *mem)
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

bool		Interpret::eggDead(Memory *mem)
{
  this->eggConnexion(mem);
  return (true);
}

bool		Interpret::setTime(Memory *mem)
{
  (void)(mem);
  return (true);
}

bool		Interpret::endGame(Memory *mem)
{
  (void)mem;
  std::cout << "L'équipe " << this->vec[1] << " a gagné" << std::endl;
  return (false);
}

void		Interpret::setVec(const std::vector<std::string> &v)
{
  this->vec = v;
}
