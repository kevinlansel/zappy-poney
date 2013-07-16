//
// tmp.hpp for zappy in /home/seth/System_unix/zappy-poney/client/ia
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Mon Jul 15 10:44:45 2013 kevin lansel
// Last update Tue Jul 16 21:03:04 2013 kevin lansel
//

#ifndef		TMP_HPP_
# define	TMP_HPP_

#include	<vector>
#include	<string>
#include	<list>
#include	<map>
#include	"get_next_line.hpp"

enum	emsg {
  OK,
  KO,
  PREND,
  START,
  END,
  CONNECT,
  ERROR,
  NONE
  /*MAKE,
  RENFORT,
  NEED,
  ACCEPT,
  THANKS,
  JOIN,
  BREAK,
  STOP,
  POSE,
  INCANT,
  UP,*/
};

enum	efunc {
  FAIM,
  MOVE_RD,
  PRENDRE_NOURRITURE,
  INVENTAIRE,
  MAJ,
  WHAT,
  VOIR,
  MAJ_VOIR,
  WHERE,
  MAKE_ROAD,
  FOLLOW_ROAD,
  PREND_OBJECT,
  CHECK_GROUP,
  INCANTATION,
  MAJ_LVL,
  VIDE_CASE,
  POSE_OBJECT,
  STAND
};

class		Tmp
{
public:
  Tmp(int, int, std::string);
  virtual ~Tmp();

private:
  int				_x;
  int				_y;
  std::string			_team;
  int				_lvl;
  int				_group;
  int				_slave;
  int				_chef;
  int				_member;
  int				_wait;
  int				_last_cmd;
  bool				_silence;
  std::string			_answer;
  emsg				_futur;
  std::string			_target;
  int				_cas;
  std::vector<int>		_where;
  std::vector<std::string>	_see;
  std::map<std::string, int>	_inv;
  std::list<std::vector<std::string> >	_road;
  std::vector<std::string>		_ressource;
  std::vector<std::vector<int> >	_tab;
  std::vector<std::vector<int> >	_view;
  int				_socket;
  std::vector<std::string>	_end_road;
  emsg				(Tmp::*_ptr_func[15])();

  std::list<std::string>	_msg;


public:
  void				setLvl(int);
  void				setGroup(int);
  void				setSlave(int);
  void				setChef(int);
  void				setMember(int);
  void				setWait(int);
  void				setMsg(std::list<std::string>);
  void				setInv(std::map<std::string, int>);
  void				setRoad(std::list<std::vector<std::string> >);
  void				setRessource(std::vector<std::string>);
  void				setLast_cmd(int);

  int				getLvl(void) const;
  int				getGroup(void) const;
  int				getSlave(void) const;
  int				getChef(void) const;
  int				getMember(void) const;
  int				getWait(void) const;
  std::list<std::string>	getMsg(void) const;
  std::map<std::string, int>	getInv(void) const;
  std::list<std::vector<std::string> >	getRoad(void) const;
  std::vector<std::string>	getRessource(void) const;
  int				getLast_cmd(void) const;

  void				loop(gnl &, const int);

private:
  emsg				faim(void);
  emsg				move_rd(void);
  emsg				prendre_nourriture(void);
  emsg				inventaire(void);
  emsg				maj_inv(void);
  emsg				what(void);
  emsg				voir(void);
  emsg				maj_voir(void);
  emsg				where(void);
  emsg				make_road(void);
  emsg				follow_road(void);
  emsg				prend_object(void);
  emsg				check_group(void);
  emsg				incantation(void);
  emsg				maj_lvl(void);
  emsg				vide_case(void);
  emsg				pose_object(void);
  emsg				stand(void);

  emsg				snd(const std::string &);
  emsg				action(std::string);
  void				do_action(const emsg);

  std::map<std::string, int>	ref(void);
};

#endif
