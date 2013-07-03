/*
** connexion.c for  in /home/lund/Projets/zappy-poney/serveur
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu Jun 27 10:38:25 2013 florian dewulf
** Last update Wed Jul  3 10:42:32 2013 florian dewulf
*/

#include	"serveur.h"

static void	graphic_connect(t_client *cl, t_map **map)
{
  getmapsize(NULL, cl->fd, map, cl);
  gettime(NULL, cl->fd, NULL, cl);
  getcasemap(NULL, cl->fd, map, cl);
}

static void	ia_connect()
{
  char		*str;
  int		size;

  //
  
}

/*
** Valeur de retour :
** 0 = client à supprimer à cause d'un fail + le kick
** 1 = ok
*/

int		connexion(t_client *cl, t_map **map)
{
  int		ret;
  char		buffer[1024];

  write(cl->fd, "BIENVENUE\n", 10);
  if ((ret = read(cl->fd, buffer, 1024)) > 0)
    {
      buffer[ret - 1] = '\0';
      if (strcmp(buffer, "GRAPHIC\n") == 0)
	return (graphic_connect());
      else
	return (ia_connect());
    }
  return (0);
}
