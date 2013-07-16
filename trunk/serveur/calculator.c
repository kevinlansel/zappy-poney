/*
** calculator.c for  in /home/lund/Projets/zappy-poney/serveur
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Tue Jun 25 14:43:22 2013 florian dewulf
** Last update Tue Jul 16 17:26:24 2013 guillaume duez
*/

#include	<math.h>
#include	"serveur.h"

static t_angle	*create_angle(int offone, int offtwo, int pond,
			      t_angle *next)
{
  t_angle	*ang;

  ang = xmalloc(sizeof(t_angle));
  ang->borne[0] = offone;
  ang->borne[1] = offtwo;
  ang->pond = pond;
  ang->next = next;
  return (ang);
}

static int	check_pond(int angle, t_angle *ang)
{
  int		ret;
  t_angle	*tmp;
  t_angle	*tempo;

  ret = 0;
  tmp = ang;
  while (tmp)
    {
      if (tmp->borne[0] <= angle && angle <= tmp->borne[1])
	ret = tmp->pond;
      tmp = tmp->next;
    }
  tmp = ang;
  while (tmp)
    {
      tempo = tmp;
      tmp = tmp->next;
      free (tempo);
    }
  return (ret);
}

static int	calcpond(int angle, int dir)
{
  t_angle	*begin;
  t_angle	*tmp;
  t_angle	*tmp2;
  int		incr;
  int		pond;

  incr = 50;
  pond = 1;
  begin = create_angle(0, 20, pond, NULL);
  tmp2 = begin;
  while (++pond <= 8)
    {
      tmp = create_angle(tmp2->borne[1], tmp2->borne[1] + incr, pond, NULL);
      tmp2->next = tmp;
      incr = (incr == 40) ? 50 : 40;
      tmp2 = tmp;
    }
  tmp2->next = create_angle(340, 360, 1, NULL);
  tmp = begin;
  while (tmp)
    {
      tmp->pond += (dir * 2);
      tmp = tmp->next;
    }
  return (check_pond(angle, begin));
}

static int	create_vtor(int s[2], int d[2], int size[2], int dir)
{
  int		newd[2];
  int		v[2];
  int		scalaire;
  int		normeab;
  int		normeac;

  newd[0] = d[0];
  newd[1] = d[1];
  v[0] = d[0];
  v[1] = d[1];
  if (s[1] - d[1] > size[1] / 2)
    newd[1] = s[1] + (size[1] - s[1]) + d[1];
  if (s[0] - d[0] > size[0] / 2)
    newd[0] = s[0] + (size[0] - s[0]) + d[0];
  v[0] += ((dir == OUEST) ? -1 : ((dir == EST) ? 1 : 0));
  v[1] += ((dir == NORD) ? -1 : ((dir == SUD) ? 1 : 0));
  scalaire = (s[0] - newd[0]) * (v[0] - newd[0]) + (s[1] - newd[1])
    * (v[1] - newd[1]);
  normeab = sqrt(pow((s[0] - newd[0]), 2) + pow((s[1] - newd[1]), 2));
  normeac = sqrt(pow((v[0] - newd[0]), 2) + pow((v[1] - newd[1]), 2));
  return (acos(scalaire / (normeab * normeac)));
}

/*
** s = source
** d = dest
** sz = sizemap
*/

int		calcul_K(t_client *from, t_client *actu)
{
  int		s[2];
  int		d[2];
  int		sz[2];

  s[1] = (s[0] = from->map->x) ? from->map->y : from->map->y;
  sz[0] = from->map->x_world;
  sz[1] = from->map->y_world;
  d[0] = actu->map->x;
  d[1] = actu->map->y;
  if (d[0] == s[0] && d[1] == s[1])
    return (0);
  return (calcpond(create_vtor(s, d, sz, actu->direct), actu->direct));
}
