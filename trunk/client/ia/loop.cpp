#include	<sys/select.h>
#include	<sys/time.h>
#include	<sys/types.h>
#include	<unistd.h>

using namespace std;
// à la construction met la première commande en mémoire dans la liste d'init
// prend en paramètre la socket (nommée "socket") et le get_next_line (nommé getnext) utilisé pour avoir la taille de la map
{
  //première commande de l'ia
  int		error = 0;
  fd_set	readfd;
  string	str;
  emsg		msg;

  while (error != -1)
    {
      msg = NONE;// à define
      FD_ZERO(&readfd);
      FD_SET(socket, &readfd);
      if (getnext.getBuffer() == "" &&
	  (error = select(socket + 1, &readfd, NULL, NULL, NULL)) != -1)
	str = getnext.get_next_line();
      else
	{
	  str = get_answer();
	  if (this->last_cmd == /* valeur pour connect nbr */ && isalpha(str))
	    msg = ;//connectnbr
	  else if (str == "mort")
	    error = -1;
	  else
	    msg = action(str);//<- à rename ? le reste de ce qui est utile est en attribut
	}
      if (msg != NONE)
	do_action(msg);
    }
  //close la socket, etc
}
