//
// Ia.hpp for zappy in /home/seth/System_unix/zappy-poney/client/ia
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Thu Jun 27 17:17:11 2013 kevin lansel
// Last update Mon Jul  8 13:19:50 2013 kevin lansel
//

#ifndef		IA_HPP_
# define	IA_HPP_

#include	<string>
#include	<list>
#include	<map>

enum	emsg {
  OK,
  KO,
  MAKE,
  RENFORT,
  NEED,
  ACCEPT,
  THANKS,
  JOIN,
  BREAK,
  STOP,
  ERROR,
};


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
  std::vector<std::string>	_ressource;

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
  void				setRessource(std::vector<std::string>);

  int				getLvl(void) const;
  int				getGroup(void) const;
  int				getSlave(void) const;
  int				getChef(void) const;
  int				getMember(void) const;
  int				getWait(void) const;
  std::list<std::string>	getMsg(void) const;
  std::map<std::string, int>	getInv(void) const;
  std::vector<std::string>	getRoad(void) const;
  std::vector<std::string>	getRessource(void) const;

  emsg				maj_inv(void);
  emsg				faim(void);
  emsg				move_rd(void) const;
  emsg				move_to(int cas);
  emsg				voir(void);
  emsg				prendre_nourriture(void) const;
  emsg				prendre_pierre(void);
  emsg				msg_list(void) const;
  emsg				check_msg(void);
  emsg				pose_objet(void);

  /* Group maker */
  emsg				make(void);
  emsg				renfort(void);
  emsg				need(void);
  emsg				accept(void);
  emsg				thanks(void);
  emsg				join(void);
  emsg				break_group(void);
  emsg				brk(void);
  emsg				check_case(void);
  int				max_member(void);

  std::map<std::string, int>	ref(void);
  void				what(void);
};

std::vector<std::string>	cut_msg(std::string );

/*
  Fonction necessaire :

  - faim
  - prendre nourriture
  - move rand
  - msg_list
  - check_msg
  --  -> make
  --  -> renfort
  --  -> need
  --  -> accept
  --  -> thanks
  --  -> join
  --  -> break_group
  --  -> brk
 */


#endif /* IA_HPP_ */
