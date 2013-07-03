//
// Ia.hpp for zappy in /home/seth/System_unix/zappy-poney/client/ia
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Thu Jun 27 17:17:11 2013 kevin lansel
// Last update Wed Jul  3 12:53:07 2013 kevin lansel
//

#ifndef		IA_HPP_
# define	IA_HPP_

#include	<string>
#include	<list>
#include	<map>

class	Ia
{
public:
  Ia();
  virtual ~Ia();

private:
  int				_lvl;
  int				_group;
  int				_slave;
  int				_chef;
  int				_member;
  int				_wait;
  std::list<std::string>	_msg;
  std::map<std::string, int>	_inv;
  std::vector<std::string>	_road;
  std::vector<std::string>	_need;

public:
  void				setLvl(int);
  void				setGroup(int);
  void				setSlave(int);
  void				setChef(int);
  void				setMember(int);
  void				setWait(int);
  void				setMsg(std::list<std::string>);
  void				setInv(std::map<std::string, int>);
  void				setRoad(std::vector<std::string>);
  void				setNeed(std::vector<std::string>);

  int				getLvl(void) const;
  int				getGroup(void) const;
  int				getSlave(void) const;
  int				getChef(void) const;
  int				getMember(void) const;
  int				getWait(void) const;
  std::list<std::string>	getMsg(void) const;
  std::map<std::string, int>	getInv(void) const;
  std::vector<std::string>	getRoad(void) const;
  std::vector<std::string>	getNeed(void) const;

  void				maj_inv(void);
  const std::string		faim(void);
  const std::string		move_rd(void) const;
  const std::string		move_to(int cas);
  const std::string		voir(void);
  const std::string		prendre_nourriture() const;

  std::map<std::string, int>	ref();
  std::vector<std::string>	what();
};

#endif /* IA_HPP_ */
